set(TARGET_PREFIX ch11-)


add_library(${TARGET_PREFIX}strarr STATIC)                   # Demo of a "A Resizable 2D Array"
target_sources(${TARGET_PREFIX}strarr PRIVATE strarr.c)
target_include_directories(${TARGET_PREFIX}strarr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}c11_018 c11_018.c)
target_link_libraries(${TARGET_PREFIX}c11_018 PRIVATE ${TARGET_PREFIX}strarr)


add_library(${TARGET_PREFIX}sllist STATIC)
target_sources(${TARGET_PREFIX}sllist PRIVATE sllist.c)
target_include_directories(${TARGET_PREFIX}sllist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}sllistmn sllistmn.c)
target_link_libraries(${TARGET_PREFIX}sllistmn PRIVATE ${TARGET_PREFIX}sllist)


add_library(${TARGET_PREFIX}dllist STATIC)
target_sources(${TARGET_PREFIX}dllist PRIVATE dllist.c)
target_include_directories(${TARGET_PREFIX}dllist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}dllistmn dllistmn.c)
target_link_libraries(${TARGET_PREFIX}dllistmn PRIVATE ${TARGET_PREFIX}dllist m)

set(cmd ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/cityloc.txt" "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(TARGET ${TARGET_PREFIX}dllistmn POST_BUILD
        COMMENT "${target}: Copying file ${filename}"
        COMMAND ${cmd})

add_executable(${TARGET_PREFIX}dllisteg dllisteg.c)
target_link_libraries(${TARGET_PREFIX}dllisteg PRIVATE ${TARGET_PREFIX}dllist)


add_library(${TARGET_PREFIX}clist STATIC)
target_sources(${TARGET_PREFIX}clist PRIVATE clist.c)
target_include_directories(${TARGET_PREFIX}clist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}clistmn clistmn.c)
target_link_libraries(${TARGET_PREFIX}clistmn PRIVATE ${TARGET_PREFIX}clist)

add_executable(${TARGET_PREFIX}clistmn2 clistmn2.c)
target_link_libraries(${TARGET_PREFIX}clistmn2 PRIVATE ${TARGET_PREFIX}clist)


add_library(${TARGET_PREFIX}stack STATIC)
target_sources(${TARGET_PREFIX}stack PRIVATE stack.c)
target_include_directories(${TARGET_PREFIX}stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET_PREFIX}stack PRIVATE ${TARGET_PREFIX}sllist)

add_executable(${TARGET_PREFIX}stackmn stackmn.c)
target_link_libraries(${TARGET_PREFIX}stackmn PRIVATE ${TARGET_PREFIX}stack ${TARGET_PREFIX}strarr)


add_library(${TARGET_PREFIX}queue STATIC)
target_sources(${TARGET_PREFIX}queue PRIVATE queue.c)
target_include_directories(${TARGET_PREFIX}queue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET_PREFIX}queue PRIVATE ${TARGET_PREFIX}sllist)

add_executable(${TARGET_PREFIX}queuemn queuemn.c)
target_link_libraries(${TARGET_PREFIX}queuemn PRIVATE ${TARGET_PREFIX}queue)


add_library(${TARGET_PREFIX}deque STATIC)
target_sources(${TARGET_PREFIX}deque PRIVATE deque.c)
target_include_directories(${TARGET_PREFIX}deque PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET_PREFIX}deque PRIVATE ${TARGET_PREFIX}dllist)

add_executable(${TARGET_PREFIX}dequemn dequemn.c)
target_link_libraries(${TARGET_PREFIX}dequemn PRIVATE ${TARGET_PREFIX}deque)


add_library(${TARGET_PREFIX}heap STATIC)
target_include_directories(${TARGET_PREFIX}heap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(${TARGET_PREFIX}heap PRIVATE heap.c)

add_executable(${TARGET_PREFIX}heapmn heapmn.c)
target_link_libraries(${TARGET_PREFIX}heapmn PRIVATE ${TARGET_PREFIX}heap)


# NOTE: These targets DON'T WORK: c11_015 C11_016.o
add_executable(${TARGET_PREFIX}C11_010 C11_010.c)
add_executable(${TARGET_PREFIX}c11_017 c11_017.c)
add_executable(${TARGET_PREFIX}c11_020 c11_020.c)
#add_executable(${TARGET_PREFIX}c11_021 c11_021.c)    # TODO: DOESN'T WORK
add_executable(${TARGET_PREFIX}c11_022 c11_022.c)
