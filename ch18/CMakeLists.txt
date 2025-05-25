set(TARGET_PREFIX ch18-)


add_executable(${TARGET_PREFIX}chekline chekline.c)
add_executable(${TARGET_PREFIX}crcccitt crcccitt.c)
add_executable(${TARGET_PREFIX}decode decode.c)
add_executable(${TARGET_PREFIX}encode encode.c)
add_executable(${TARGET_PREFIX}hamming hamming.c)
add_executable(${TARGET_PREFIX}lj300 lj300.c)
add_executable(${TARGET_PREFIX}parity parity.c)
add_executable(${TARGET_PREFIX}pidloop pidloop.c)
add_executable(${TARGET_PREFIX}script script.c)
add_executable(${TARGET_PREFIX}TEXT2BIN TEXT2BIN.c)


# TODO: Consider copying
#   - accel1.pid
#   - calcgram
#   - copygram
#   - genhelp
#   - grammar
#   - help
