cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Configuracao.cpp Configuracao.h Realsense.cpp Realsense.h LidarLite.cpp LidarLite.h Socket.cpp Socket.h MotorVib.cpp MotorVib.h Processadora.cpp Processadora.h)
