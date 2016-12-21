project(StaticStackLib CXX)
file(GLOB SOURCES *.cpp)

add_library(StaticStackLib ${SOURCES})
target_link_libraries(StaticStackLib)