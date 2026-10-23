cmake_minimum_required(VERSION 3.20)
project(LeetCode LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

enable_testing()

# Every problem folder containing solution.c and main.c is built into
# <build-dir>/<problem-folder>/main(.exe) and registered as a CTest test.
# The build scripts use build/c as the build directory.
file(GLOB problem_dirs LIST_DIRECTORIES true CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/problems/*")

foreach(dir IN LISTS problem_dirs)
    if(EXISTS "${dir}/solution.c" AND EXISTS "${dir}/main.c")
        get_filename_component(problem "${dir}" NAME)
        # Short target names (p1111) keep MSBuild's intermediate paths under
        # the Windows 260-character limit for long problem slugs. Folders
        # without a number prefix, or with a duplicate number, fall back to
        # the full folder name so the configure step never fails.
        string(REGEX MATCH "^[0-9]+" number "${problem}")
        set(target "p${number}")
        if(NOT number OR TARGET ${target})
            string(MAKE_C_IDENTIFIER "${problem}" target)
        endif()

        add_executable(${target} "${dir}/solution.c" "${dir}/main.c")
        # "$<0:>" stops multi-config generators (e.g. Visual Studio) from
        # appending a Debug/ or Release/ subfolder to the output path.
        set_target_properties(${target} PROPERTIES
            OUTPUT_NAME main
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${problem}/$<0:>")

        add_test(NAME ${problem} COMMAND ${target})
    endif()
endforeach()
