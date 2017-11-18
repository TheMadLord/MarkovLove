cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKe_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -std=c++14")
set(CMAKe_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -std=c++14")

project("MarkovLove")

add_subdirectory(src)
