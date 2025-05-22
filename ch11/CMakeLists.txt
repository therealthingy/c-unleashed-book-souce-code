
add_library(strarr STATIC)
target_sources(strarr PRIVATE strarr.c)
target_include_directories(strarr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(c11_018 c11_018.c)
target_link_libraries(c11_018 PRIVATE strarr)


add_library(sllist STATIC)
target_sources(sllist PRIVATE sllist.c)
target_include_directories(sllist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(sllistmn sllistmn.c)
target_link_libraries(sllistmn PRIVATE sllist)


add_library(dllist STATIC)
target_sources(dllist PRIVATE dllist.c)
target_include_directories(dllist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(dllistmn dllistmn.c)
target_link_libraries(dllistmn PRIVATE dllist)

set(cmd ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/cityloc.txt" "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(TARGET dllistmn POST_BUILD
        COMMENT "${target}: Copying file ${filename}"
        COMMAND ${cmd})

add_executable(dllisteg dllisteg.c)
target_link_libraries(dllisteg PRIVATE dllist)


add_library(clist STATIC)
target_sources(clist PRIVATE clist.c)
target_include_directories(clist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(clistmn clistmn.c)
target_link_libraries(clistmn PRIVATE clist)

add_executable(clistmn2 clistmn2.c)
target_link_libraries(clistmn2 PRIVATE clist)


add_library(stack STATIC)
target_sources(stack PRIVATE stack.c)
target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(stack PRIVATE sllist)

add_executable(stackmn stackmn.c)
target_link_libraries(stackmn PRIVATE stack strarr)


add_library(queue STATIC)
target_sources(queue PRIVATE queue.c)
target_include_directories(queue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(queue PRIVATE sllist)

add_executable(queuemn queuemn.c)
target_link_libraries(queuemn PRIVATE queue)


add_library(deque STATIC)
target_sources(deque PRIVATE deque.c)
target_include_directories(deque PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(deque PRIVATE dllist)

add_executable(dequemn dequemn.c)
target_link_libraries(dequemn PRIVATE deque)


add_library(heap STATIC)
target_include_directories(heap PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(heap PRIVATE heap.c)

add_executable(heapmn heapmn.c)
target_link_libraries(heapmn PRIVATE heap)


# NOTE: These targets DON'T WORK: c11_015 C11_016.o
add_executable(C11_010 C11_010.c)
add_executable(c11_017 c11_017.c)
add_executable(c11_020 c11_020.c)
#add_executable(c11_021 c11_021.c)    # TODO: DOESN'T WORK
add_executable(c11_022 c11_022.c)
