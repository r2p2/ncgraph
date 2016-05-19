cmake_minimum_required(VERSION 2.8.0)
project(ncgraph)

find_package(Curses REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -std=c++11")

include_directories(
	${CURSES_INCLUDE_DIR}
)

add_executable(ncgraph
	src/main.cc
)

target_link_libraries(ncgraph
	${CURSES_LIBRARIES}
)
