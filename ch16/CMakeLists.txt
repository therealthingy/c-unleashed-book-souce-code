# TODO: Makefile is buggy (invoke it twice deletes binaries  "Circular dependency dropped")

add_library(graph STATIC)
target_sources(graph PRIVATE
        adjlist.c
        adjmatrix.c
        dfsfuncs.c
        dfsfuncs.c
        graphs.c
        mstree.c
        pqueue.c
        shpath.c
        topsort.c)
target_include_directories(graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(testing1 testing1.c)
target_link_libraries(testing1 PRIVATE graph)

add_executable(testing2 testing2.c)
target_link_libraries(testing2 PRIVATE graph)

add_executable(testing3 testing3.c)
target_link_libraries(testing3 PRIVATE graph)

add_executable(testing4 testing4.c)
target_link_libraries(testing4 PRIVATE graph)

add_executable(testing5 testing5.c)
target_link_libraries(testing5 PRIVATE graph)
