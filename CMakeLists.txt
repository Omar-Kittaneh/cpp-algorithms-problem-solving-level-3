cmake_minimum_required(VERSION 3.20)
project(cpp_algorithms_problem_solving_level_3)

set(CMAKE_CXX_STANDARD 17)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(main main.cpp)
endif()

file(GLOB PROBLEM_FILES CONFIGURE_DEPENDS "Problems/*.cpp")

foreach(PROBLEM_PATH ${PROBLEM_FILES})
    get_filename_component(PROBLEM_NAME ${PROBLEM_PATH} NAME_WE)
    add_executable(${PROBLEM_NAME} ${PROBLEM_PATH})
endforeach()