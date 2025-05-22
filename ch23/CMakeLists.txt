
add_library(cgi OBJECT)
target_sources(cgi PRIVATE cgi.c)
target_include_directories(cgi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Proto Proto.c)
target_link_libraries(Proto PRIVATE cgi)

set(cmd ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/proto.html" "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(TARGET Proto POST_BUILD
        COMMENT "${target}: Copying file ${filename}"
        COMMAND ${cmd})
