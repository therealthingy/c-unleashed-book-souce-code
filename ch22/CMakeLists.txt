set(TARGET_PREFIX ch22-)


# CUPS TCP
add_library(${TARGET_PREFIX}cups OBJECT)
target_sources(${TARGET_PREFIX}cups PRIVATE u_cups.c)
target_include_directories(${TARGET_PREFIX}cups PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}cts cts.c)                    # server
target_link_libraries(${TARGET_PREFIX}cts PRIVATE ${TARGET_PREFIX}cups)

add_executable(${TARGET_PREFIX}ctc ctc.c)                    # client
target_link_libraries(${TARGET_PREFIX}ctc PRIVATE ${TARGET_PREFIX}cups)

# CUPS UDP
add_executable(${TARGET_PREFIX}cus cus.c)                    # server
target_link_libraries(${TARGET_PREFIX}cus PRIVATE ${TARGET_PREFIX}cups)

add_executable(${TARGET_PREFIX}cuc cuc.c)                    # client
target_link_libraries(${TARGET_PREFIX}cuc PRIVATE ${TARGET_PREFIX}cups)


# Unix TCP
add_executable(${TARGET_PREFIX}uts uts.c)                    # server
add_executable(${TARGET_PREFIX}utc utc.c)                    # client

# Unix UDP
add_executable(${TARGET_PREFIX}uus uus.c)                    # server
add_executable(${TARGET_PREFIX}uuc uuc.c)                    # client
