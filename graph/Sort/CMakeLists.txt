project(StaticSortLib CXX)
file(GLOB SOURCES *.cpp)

add_library(StaticSortLib ${SOURCES})
target_link_libraries(StaticSortLib)