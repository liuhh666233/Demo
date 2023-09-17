cmake_minimum_required(VERSION 3.15)

project(Tutorial VERSION 1.0)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_DEBUG_POSTFIX d)

# 创建interface库，本身不会被编译链接，只是传递编译选项
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_20)

# 设置编译器类型
# COMPILE_LANG_AND_ID 用于判断当前编译器类型是否和 comma-separated entries 匹配
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# 根据编译器类型设置编译选项
# BUILD_INTERFACE 在构建时为真，因此只有在构建时才会添加编译选项
target_compile_options(
    tutorial_compiler_flags INTERFACE 
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wnon-virtual-dtor;-pedantic>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# configure a header file to pass some of the CMake settings.
configure_file(TutorialConfig.h.in TutorialConfig.h)

add_subdirectory(MathFunctions)
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")

add_executable(Tutorial tutorial.cc)
set_target_properties(Tutorial PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# 将interface库的编译选项传递给target
target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
# PROJECT_BINARY_DIR is the directory where cmake is run.
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# ctest -VV -D Experimental
# Support for submitting test results to a CDash dashboard.
include(CTest)

# Add tests
enable_testing()

function( do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction( )

# do a bunch of result based tests
# ctest -V 可以查看测试结果
do_test(Tutorial 4 "Output value: 2")
do_test(Tutorial 9 "Output value: 3")
do_test(Tutorial 5 "Output value: 2.236")
do_test(Tutorial 7 "Output value: 2.645")
do_test(Tutorial 25 "Output value: 5")
do_test(Tutorial -25 "Output value: (-nan|nan|0)")
do_test(Tutorial 0.0001 "Output value: 0.01")


#Packaging an Installer for other platforms.
#cpack -G ZIP -C Debug
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)

install(EXPORT MathFunctionsTargets
  FILE MathFunctionsTargets.cmake
  DESTINATION lib/cmake/MathFunctions
)

include(CMakePackageConfigHelpers)

# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/example"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake"
  VERSION "${Tutorial_VERSION_MAJOR}.${Tutorial_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsConfigVersion.cmake
  DESTINATION lib/cmake/MathFunctions
  )

export(EXPORT MathFunctionsTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/MathFunctionsTargets.cmake"
)
