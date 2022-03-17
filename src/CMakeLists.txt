CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
SET(CMAKE_CXX_STANDARD 20)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

LIST(APPEND test_libraries gtest gtest_main)
LIST(APPEND algo_folder array list string)

FOREACH (folder ${algo_folder})
  FILE(GLOB test_srcs ${folder}/*.cc)
  LIST(APPEND algo_test_srcs ${test_srcs})
ENDFOREACH ()

FOREACH (test_item ${algo_test_srcs})
  GET_FILENAME_COMPONENT(test_target_name ${test_item} NAME_WE)
  ADD_EXECUTABLE(${test_target_name} ${test_item})
  TARGET_LINK_LIBRARIES(${test_target_name} ${test_libraries})
  ADD_TEST(NAME ${test_target_name} COMMAND ${test_target_name})
ENDFOREACH ()