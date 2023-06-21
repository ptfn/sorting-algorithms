cmake_minimum_required(VERSION 3.22.1)
project(sorting-algorithms)

ADD_LIBRARY(SortLib STATIC src/sort.c)

SET(APP_EXE sort)

ADD_EXECUTABLE(${APP_EXE} src/main.c) 

TARGET_LINK_LIBRARIES(${APP_EXE} SortLib)