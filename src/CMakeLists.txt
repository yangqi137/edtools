cmake_minimum_required(VERSION, 2.6)
project(edtools)

file(GLOB ARPACK_DRV_SRCS "edtools/arpack_drv/*.cpp")
add_library(edtools SHARED ${ARPACK_DRV_SRCS})
