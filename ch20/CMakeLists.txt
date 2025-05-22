
add_executable(argproc argproc.c genargs.c)
target_link_libraries(argproc PRIVATE dllist)

add_executable(tee tee.c)
add_executable(DataGen DataGen.c)
add_executable(hd hd.c)
add_executable(maxline maxline.c)
add_executable(sandra sandra.c)
add_executable(limn limn.c)


# TODO: Consider copying
#   - ascebc.txt
#   - calcgram
#   - copygram
#   - genhelp
#   - grammar
#   - help
