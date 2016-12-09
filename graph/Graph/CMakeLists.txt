project(StaticGraphLib CXX)
file(GLOB SOURCES *.cpp)

add_library(StaticGraphLib ${SOURCES})
target_link_libraries(StaticGraphLib)