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
IF(CMAKE_BUILD_TYPE MATCHES DEBUG OR CMAKE_BUILD_TYPE MATCHES Debug)
  set(DEBUG_INFO ON)
  message(STATUS "DEBUG_INFO: ${DEBUG_INFO}")
ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG OR CMAKE_BUILD_TYPE MATCHES Debug)

# Set sources and headers
set(LIB_SOURCES
    "cpp/src/dsa/data_structures/heaps.cpp"
    "cpp/src/dsa/data_structures/linked_lists.cpp"
    "cpp/src/dsa/empty.cpp"
)
set(LIB_HEADERS
    "cpp/include/dsa/algorithms/binary_search.h"
    "cpp/include/dsa/algorithms/greedy.h"
    "cpp/include/dsa/algorithms/prefix_sum.h"
    "cpp/include/dsa/algorithms/sliding_window_algos.h"
    "cpp/include/dsa/algorithms/sliding_window.h"
    "cpp/include/dsa/algorithms/two_pointers_algos.h"
    "cpp/include/dsa/algorithms/two_pointers.h"

    "cpp/include/dsa/data_structures/binary_trees.h"
    "cpp/include/dsa/data_structures/graphs.h"
    "cpp/include/dsa/data_structures/hash_maps.h"
    "cpp/include/dsa/data_structures/heaps.h"
    "cpp/include/dsa/data_structures/linked_lists.h"
    "cpp/include/dsa/data_structures/stacks_and_queues.h"
    
    "cpp/include/dsa/utils.h"
)

# TODO: Why do I need this for #include statements to work in cpp/test?
include_directories(cpp/include)

# Create a library
add_library(dsalib ${LIB_SOURCES} ${LIB_HEADERS})

# Add debug info for the library
if( DEBUG_INFO )
    target_compile_definitions(dsalib PRIVATE DEBUG_INFO)
endif()

# Add third party libraries
add_subdirectory(cpp/thirdparty)

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

# Tell CMake that we'll have unit tests 
enable_testing()

# Build the C++ tests
add_subdirectory(cpp/test)

# Build the python bindings
message(STATUS "Building the python bindings.")
add_subdirectory(cpp/bindings)
