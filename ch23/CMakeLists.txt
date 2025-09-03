set(TARGET_PREFIX ch23-)

add_library(${TARGET_PREFIX}cgi OBJECT)
target_sources(${TARGET_PREFIX}cgi PRIVATE cgi.c)
target_include_directories(${TARGET_PREFIX}cgi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}Proto Proto.c)
target_link_libraries(${TARGET_PREFIX}Proto PRIVATE ${TARGET_PREFIX}cgi)

set(cmd
    ${CMAKE_COMMAND}
    -E
    copy
    "${CMAKE_CURRENT_LIST_DIR}/proto.html"
    "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(
    TARGET ${TARGET_PREFIX}Proto
    POST_BUILD
    COMMENT "${target}: Copying file ${filename}"
    COMMAND ${cmd})
