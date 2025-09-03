set(TARGET_PREFIX ch17-)

add_library(${TARGET_PREFIX}m_matrix STATIC)
target_sources(${TARGET_PREFIX}m_matrix PRIVATE m_matrix.c)
target_include_directories(${TARGET_PREFIX}m_matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET_PREFIX}m_matrix PRIVATE m)

add_executable(${TARGET_PREFIX}m_test m_test.c)
target_link_libraries(${TARGET_PREFIX}m_test PRIVATE ${TARGET_PREFIX}m_matrix)

set(cmd
    ${CMAKE_COMMAND}
    -E
    copy
    "${CMAKE_CURRENT_LIST_DIR}/mtest1.mat"
    "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(
    TARGET ${TARGET_PREFIX}m_test
    POST_BUILD
    COMMENT "${target}: Copying file ${filename}"
    COMMAND ${cmd})
