project(StaticBTreeLib CXX)

file(GLOB SOURCES *.cpp)

add_library(StaticBTreeLib ${SOURCES})
target_link_libraries(StaticBTreeLib)