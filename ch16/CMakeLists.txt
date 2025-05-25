set(TARGET_PREFIX ch16-)


add_library(${TARGET_PREFIX}graph STATIC)
target_sources(${TARGET_PREFIX}graph PRIVATE
        adjlist.c
        adjmatrix.c
        dfsfuncs.c
        dfsfuncs.c
        graphs.c
        mstree.c
        pqueue.c
        shpath.c
        topsort.c)
target_include_directories(${TARGET_PREFIX}graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(${TARGET_PREFIX}testing1 testing1.c)
target_link_libraries(${TARGET_PREFIX}testing1 PRIVATE ${TARGET_PREFIX}graph)

add_executable(${TARGET_PREFIX}testing2 testing2.c)
target_link_libraries(${TARGET_PREFIX}testing2 PRIVATE ${TARGET_PREFIX}graph)

add_executable(${TARGET_PREFIX}testing3 testing3.c)
target_link_libraries(${TARGET_PREFIX}testing3 PRIVATE ${TARGET_PREFIX}graph)

add_executable(${TARGET_PREFIX}testing4 testing4.c)
target_link_libraries(${TARGET_PREFIX}testing4 PRIVATE ${TARGET_PREFIX}graph)

add_executable(${TARGET_PREFIX}testing5 testing5.c)
target_link_libraries(${TARGET_PREFIX}testing5 PRIVATE ${TARGET_PREFIX}graph)
