set(TARGET_PREFIX ch20-)

add_executable(${TARGET_PREFIX}argproc argproc.c genargs.c)
target_link_libraries(${TARGET_PREFIX}argproc PRIVATE ch11-dllist)

add_executable(${TARGET_PREFIX}tee tee.c)
add_executable(${TARGET_PREFIX}DataGen DataGen.c)
add_executable(${TARGET_PREFIX}hd hd.c)
add_executable(${TARGET_PREFIX}maxline maxline.c)
add_executable(${TARGET_PREFIX}sandra sandra.c)
add_executable(${TARGET_PREFIX}limn limn.c)

# TODO: Consider copying
#   - ascebc.txt
#   - calcgram
#   - copygram
#   - genhelp
#   - grammar
#   - help
