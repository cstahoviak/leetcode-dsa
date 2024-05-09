cmake_minimum_required(VERSION 3.5)

set(TARGET ${PROJECT_NAME}_python)

find_package(pybind11 REQUIRED)

set(SOURCES
  "algorithms/two_pointers.cpp"
  "module.cpp"
)

pybind11_add_module(${TARGET} SHARED ${SOURCES})

# target_include_directories(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# target_link_libraries(${TARGET} PRIVATE
#   dsa::algorithms
# )

# Install the bindings to the python directory
set(OUTPUT_PATH "${PROJECT_SOURCE_DIR}/python/src/bindings")
set_target_properties(${TARGET} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}/$<0:>
  LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}/$<0:>
)