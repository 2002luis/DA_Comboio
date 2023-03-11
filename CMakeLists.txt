cmake_minimum_required(VERSION 3.23)
project(DA_Quimboio)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA_Quimboio src/data_structs/VertexEdge.cpp src/data_structs/VertexEdge.h src/data_structs/Station.cpp src/data_structs/Station.h src/main.cpp)
