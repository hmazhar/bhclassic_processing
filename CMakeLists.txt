cmake_minimum_required(VERSION 2.8)
project(bhclassic_processing)

SET(SOURCE_FILES main.cpp )

SET(PARTIO_INCLUDE "" CACHE PATH "PARTIO INCLUDE")
SET(PARTIO_NAMES ${PARTIO_NAMES} partio)  

FIND_LIBRARY(PARTIO_LIBRARY NAMES ${PARTIO_NAMES} PATHS /usr/lib /usr/local/lib)
find_package(ZLIB)
include_directories(${PARTIO_INCLUDE})

ADD_EXECUTABLE(bhclassic_to_ascii	bhclassic_to_ascii.cpp)
target_link_libraries(bhclassic_to_ascii  ${PARTIO_LIBRARY} ${ZLIB_LIBRARY})

ADD_EXECUTABLE(csv_to_bhclassic	csv_to_bhclassic.cpp)
target_link_libraries(csv_to_bhclassic  ${PARTIO_LIBRARY} ${ZLIB_LIBRARY})