cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(cp_main)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp")
  configure_file(${CMAKE_SOURCE_DIR}/Main.cpp.template ${CMAKE_SOURCE_DIR}/Main.cpp COPYONLY)
endif()

set(HEADERS
    algorithms/ds/sparse_table.hpp algorithms/ds/ufds.hpp algorithms/ds/min_max_queue.hpp
    algorithms/ds/fenwick_tree/fenwick_tree_point_update_range_query.hpp
    algorithms/ds/fenwick_tree/fenwick_tree_range_update_point_query.hpp
    algorithms/ds/fenwick_tree/fenwick_tree_range_update_range_query.hpp
    algorithms/ds/fenwick_tree/fenwick_tree_min_max.hpp
    algorithms/ds/fenwick_tree/fenwick_tree2D_point_update_range_query.hpp
    algorithms/ds/fenwick_tree/fenwick_tree3D_point_update_range_query.hpp
    algorithms/ds/sqrt_decomposition/greater_or_less_than_point_update_range_query.hpp
    )

add_executable(cp_main Main.cpp ${HEADERS})

target_include_directories(cp_main
                           PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/algorithms>
                           )

target_compile_features(cp_main PRIVATE cxx_std_17)
target_compile_definitions(cp_main PUBLIC DEBUG=1)

target_link_libraries(cp_main)


add_custom_command(TARGET cp_main POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/Main.cpp ${CMAKE_SOURCE_DIR}/MainFull.cpp)

find_program(SED_TOOL NAMES sed)
if(NOT SED_TOOL)
  message(FATAL_ERROR "Unable to find sed")
endif(NOT SED_TOOL)

file(READ ${CMAKE_SOURCE_DIR}/algorithms/ds/sparse_table.hpp SPARSE_TABLE_CONTENT)

foreach(FILE_NAME in ${HEADERS})
  string(REPLACE "algorithms/" "" FILE_WITHOUT_ALGO ${FILE_NAME})
  string(REPLACE ".hpp" "" FILE_WITHOUT_ALGO_AND_EXT ${FILE_WITHOUT_ALGO})
  string(REPLACE "/" "\\/" FILE_WITHOUT_ALGO_AND_EXT_WITH_COUNTER_BARS ${FILE_WITHOUT_ALGO_AND_EXT})


  add_custom_command(TARGET cp_main POST_BUILD
                     COMMAND ${SED_TOOL} -i -e '/\\\#include <${FILE_WITHOUT_ALGO_AND_EXT_WITH_COUNTER_BARS}\\.hpp>/{r ${CMAKE_SOURCE_DIR}/algorithms/${FILE_WITHOUT_ALGO_AND_EXT}.hpp' -e 'd}' ${CMAKE_SOURCE_DIR}/MainFull.cpp)
  add_custom_command(TARGET cp_main POST_BUILD
                     COMMAND ${SED_TOOL} -i -e '/\\\#include<${FILE_WITHOUT_ALGO_AND_EXT_WITH_COUNTER_BARS}\\.hpp>/{r ${CMAKE_SOURCE_DIR}/algorithms/${FILE_WITHOUT_ALGO_AND_EXT}.hpp' -e 'd}' ${CMAKE_SOURCE_DIR}/MainFull.cpp)
  add_custom_command(TARGET cp_main POST_BUILD
                     COMMAND ${SED_TOOL} -i -e '/\\\#include \"${FILE_WITHOUT_ALGO_AND_EXT_WITH_COUNTER_BARS}\\.hpp\"/{r ${CMAKE_SOURCE_DIR}/algorithms/${FILE_WITHOUT_ALGO_AND_EXT}.hpp' -e 'd}' ${CMAKE_SOURCE_DIR}/MainFull.cpp)
  add_custom_command(TARGET cp_main POST_BUILD
                     COMMAND ${SED_TOOL} -i -e '/\\\#include\"${FILE_WITHOUT_ALGO_AND_EXT_WITH_COUNTER_BARS}\\.hpp\"/{r ${CMAKE_SOURCE_DIR}/algorithms/${FILE_WITHOUT_ALGO_AND_EXT}.hpp' -e 'd}' ${CMAKE_SOURCE_DIR}/MainFull.cpp)
endforeach()
