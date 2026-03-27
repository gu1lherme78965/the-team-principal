cmake_minimum_required(VERSION 3.15)
project(TheTeamPrincipal VERSION 0.0.1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/src/*.c)

# Add main separately
set(MAIN_SOURCE ${PROJECT_SOURCE_DIR}/main.cpp)

# Add SDL3 as a dependency
add_subdirectory(${PROJECT_SOURCE_DIR}/external/SDL)


# Add executables for both release and debug configurations
add_executable(${PROJECT_NAME} ${MAIN_SOURCE} ${SOURCES})

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:CONSOLE"
    )
endif()

# linking SDL3
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/external/*/include)

# Output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin/release
RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/debug
)

# Set compiler flags and definitions for release and debug configurations
target_compile_definitions(${PROJECT_NAME} PRIVATE 
$<$<CONFIG:Release>:NDEBUG>
$<$<CONFIG:Debug>:DEBUG>
)

# Compiler options
if(MSVC)
    # MSVC-specific flags
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:/O2>
        $<$<CONFIG:Debug>:/Zi /Od>
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # GCC/Clang flags
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:-O3>
        $<$<CONFIG:Debug>:-g -O0>
    )
endif()
