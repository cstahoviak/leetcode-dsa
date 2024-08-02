cmake_minimum_required(VERSION 3.10.2)
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()
message(STATUS "Compiling with C++ Standard: ${CMAKE_CXX_STANDARD}")

project(dsa LANGUAGES CXX)
message(STATUS "PROJECT NAME: ${PROJECT_NAME}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

# Create a macro-defined option with a default value of OFF
option(DEBUG_INFO "Turn on Debug Info" OFF)

# Set sources and headers
set(LIB_SOURCES
    "cpp/src/dsa/empty.cpp"
)
set(LIB_HEADERS
    "cpp/include/dsa/algorithms/two_pointers_algos.h"
    "cpp/include/dsa/algorithms/two_pointers.h"
    "cpp/include/dsa/utils.h"
)

# TODO: Why do I need this for #include statements to work in cpp/test?
include_directories(cpp/include)

# Add googletest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

# Tell CMake that we'll have unit tests 
enable_testing()

# Create a library
add_library(dsalib ${LIB_SOURCES} ${LIB_HEADERS})

# Build all app executables
file( GLOB APP_SOURCES cpp/app/*.cpp )
foreach( testsourcefile ${APP_SOURCES} )
    # Cut off the file extension and directory path
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
    # Make sure YourLib is linked to each app
    target_link_libraries( ${testname} PRIVATE dsalib )
    # TODO: Switch to using target_include_directories()? Success!
    target_include_directories(${testname} PRIVATE 
        "${PROJECT_SOURCE_DIR}/cpp/include"
    )
    # Add debug info for each target
    if( DEBUG_INFO )
        target_compile_definitions(${testname} PRIVATE DEBUG_INFO)
    endif()
endforeach( testsourcefile ${APP_SOURCES} )

# Build the python bindings
# TODO: Adding the python bindings results in a build error "fatal error: 
# dsa/algorithms/two_pointers.h: No such file or directory." Not sure how
# fix this yet.
add_subdirectory(cpp/bindings)

# Build the C++ tests
add_subdirectory(cpp/test)