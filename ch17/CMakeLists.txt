
add_library(m_matrix STATIC)
target_sources(m_matrix PRIVATE m_matrix.c)
target_include_directories(m_matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(m_test m_test.c)
target_link_libraries(m_test PRIVATE m_matrix)

set(cmd ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/mtest1.mat" "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(TARGET m_test POST_BUILD
        COMMENT "${target}: Copying file ${filename}"
        COMMAND ${cmd})
