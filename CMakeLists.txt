cmake_minimum_required(VERSION 2.8)
project(bgeo_to_raw)

SET(SOURCE_FILES main.cpp )

SET(PARTIO_INCLUDE "" CACHE PATH "PARTIO INCLUDE")
SET(PARTIO_NAMES ${PARTIO_NAMES} partio)  

FIND_LIBRARY(PARTIO_LIBRARY NAMES ${PARTIO_NAMES} PATHS /usr/lib /usr/local/lib)
find_package(ZLIB)
include_directories(${PARTIO_INCLUDE})

ADD_EXECUTABLE(bgeo_to_raw	${SOURCE_FILES} ${INCLUDE_FILES})
target_link_libraries(bgeo_to_raw  ${PARTIO_LIBRARY} ${ZLIB_LIBRARY})

