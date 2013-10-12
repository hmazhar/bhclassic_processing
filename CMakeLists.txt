cmake_minimum_required(VERSION 2.8)
project(bgeo_to_csv)
include(Utils.cmake)

SET(SOURCE_FILES 
main.cpp )


SET(INCLUDE_FILES "")

SET(PARTIO_INCLUDE "" CACHE PATH "PARTIO INCLUDE")

SET(PARTIO_NAMES ${PARTIO_NAMES} partio)
FIND_LIBRARY(PARTIO_LIBRARY
NAMES ${PARTIO_NAMES}
PATHS /usr/lib /usr/local/lib
)


SET(ZLIB_NAMES ${ZLIB_NAMES} z)
FIND_LIBRARY(ZLIB_LIBRARY
NAMES ${ZLIB_NAMES}
PATHS /usr/lib /usr/local/lib /opt/local/lib
)

ADD_EXECUTABLE(bgeo_to_csv	${SOURCE_FILES} ${INCLUDE_FILES})
target_link_libraries(bgeo_to_csv  ${PARTIO_LIBRARY} ${ZLIB_LIBRARY})
include_directories(${PARTIO_INCLUDE})
