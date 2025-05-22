
# CUPS TCP
add_library(cups OBJECT)
target_sources(cups PRIVATE u_cups.c)
target_include_directories(cups PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(cts cts.c)                    # server
target_link_libraries(cts PRIVATE cups)

add_executable(ctc ctc.c)                    # client
target_link_libraries(ctc PRIVATE cups)

# CUPS UDP
add_executable(cus cus.c)                    # server
target_link_libraries(cus PRIVATE cups)

add_executable(cuc cuc.c)                    # client
target_link_libraries(cuc PRIVATE cups)


# Unix TCP
add_executable(uts uts.c)                    # server
add_executable(utc utc.c)                    # client

# Unix UDP
add_executable(uus uus.c)                    # server
add_executable(uuc uuc.c)                    # client
