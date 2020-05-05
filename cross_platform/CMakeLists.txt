cmake_minimum_required(VERSION 2.8.11)

# Name of the projet
project(bomberman)

set(SRC_DIR
 ./src/
 )

set(INC_DIR
 ./include/
 )

set(SRCS
 ${SRC_DIR}/main.cpp
 )

set(HEADERS
 )

add_executable(bomberman ${SRCS} ${HEADERS})