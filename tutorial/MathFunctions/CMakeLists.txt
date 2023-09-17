add_library( MathFunctions MathFunctions.cxx )

option (USE_MYMATH "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
    # 添加编译定义 USE_MYMATH，预处理器会自动创建编译宏定义，供在源码中进行条件编译
    target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

    # generate Table.h
    include(MakeTable.cmake)

    add_library( SqrtLibrary STATIC mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    )

    target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)

    # state that we depend on our binary dir to find Table.h
    target_include_directories(SqrtLibrary PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

    # include(CheckCXXSourceCompiles)
    # check_cxx_source_compiles("
    # #include <cmath>
    # int main() {
    #     std::log(1.0);
    #     return 0;
    # }" HAVE_LOG)
    # check_cxx_source_compiles("
    # #include <cmath>
    # int main() {
    #     std::exp(1.0);
    #     return 0;
    # }" HAVE_EXP)

    # if(HAVE_LOG AND HAVE_EXP)
    #     target_compile_definitions(SqrtLibrary PRIVATE "HAVE_LOG" "HAVE_EXP")
    # endif()

    target_link_libraries(MathFunctions PRIVATE SqrtLibrary)

endif()

target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)

target_include_directories(
    MathFunctions
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# setup the version numbering
set_property(TARGET MathFunctions PROPERTY VERSION "1.0.0")
set_property(TARGET MathFunctions PROPERTY SOVERSION "1")

set (installable_libs MathFunctions tutorial_compiler_flags)
if (TARGET SqrtLibrary)
    list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs} 
          EXPORT MathFunctionsTargets
          DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
