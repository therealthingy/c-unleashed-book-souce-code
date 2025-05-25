set(TARGET_PREFIX ch09-)


add_executable(${TARGET_PREFIX}asm asm.c)

set(cmd ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/asm.asm" "${CMAKE_CURRENT_BINARY_DIR}")
add_custom_command(TARGET ${TARGET_PREFIX}asm POST_BUILD
        COMMENT "${target}: Copying file ${filename}"
        COMMAND ${cmd})
