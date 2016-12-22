project(StaticTreeLib CXX)

file(GLOB SOURCES *.cpp *.h)

add_library(StaticTreeLib ${SOURCES})
target_link_libraries(StaticTreeLib)