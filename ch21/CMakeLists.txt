
add_executable(8962cd21 8962cd21.c)

set(cmd ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/IBM.dat"
                                 "${CMAKE_CURRENT_LIST_DIR}/INTC.dat"
                                 "${CMAKE_CURRENT_LIST_DIR}/MSFT.dat" "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(TARGET 8962cd21 POST_BUILD
        COMMENT "${target}: Copying file ${filename}"
        COMMAND ${cmd})
