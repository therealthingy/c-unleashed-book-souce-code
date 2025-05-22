
# OG: `gcc -ansi -W -Wall -Wno-unused -lm -o $@ $<`
add_executable(speed speed.c)
target_compile_options(speed PRIVATE -ansi -W -Wall -Wno-unused)
target_link_options(speed PRIVATE -lm)

# OG: `gcc -pg -c -ansi -W -Wall -Wno-unused $<`
#     `gcc -pg bubble.o -o $@`
add_executable(bubble bubble.c)
target_compile_options(bubble PRIVATE -ansi -W -Wall -Wno-unused  -pg)
target_link_libraries(bubble PRIVATE -pg)
