{
  description = "Intraday game";

  inputs = {
    nixpkgs.url =
      "github:NixOS/nixpkgs?rev=e82ffe7b5f25d781eb52cc07c552899cf6f6547b";

    utils.url = "github:numtide/flake-utils";
    utils.inputs.nixpkgs.follows = "nixpkgs";

    vitalpkgs.url = "github:nixvital/vitalpkgs";
    vitalpkgs.inputs.nixpkgs.follows = "nixpkgs";

    basis-flake.url = "git+ssh://git@github.com/quant-wonderland/basis";
    basis-flake.inputs.nixpkgs.follows = "nixpkgs";
    basis-flake.inputs.vitalpkgs.follows = "vitalpkgs";

  };

  outputs = { self, nixpkgs, utils, vitalpkgs, ... }@inputs:
    inputs.utils.lib.eachSystem [ "x86_64-linux" ] (system:
      let
        pkgs = import nixpkgs {
          inherit system;
          overlays = [
            vitalpkgs.overlay
            (final: prev: {
              basis = inputs.basis-flake.defaultPackage."${prev.system}";
            })
          ];
          config.allowUnfree = true;
        };
      in rec {
        devShell =
          pkgs.mkShell.override { stdenv = pkgs.llvmPackages_11.stdenv; } rec {
            name = "demo";

            packages = with pkgs; [
              # Development Tools
              llvmPackages_11.clang
              cmake
              cmakeCurses
              vscode-include-fix
              nixpkgs-fmt

              # Development time dependencies
              gtest

              # Build time and Run time dependencies
              spdlog
              abseil-cpp
              basis
              nlohmann_json
              marl
            ];

            shellHook = let icon = "f121";
            in ''
              export CC=clang
              export CXX=clang++
              export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"
            '';

          };

        defaultPackage = pkgs.callPackage ./default.nix { };

      });
}
