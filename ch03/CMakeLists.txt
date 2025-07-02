set(TARGET_PREFIX ch03-)


# OG: `gcc -ansi -W -Wall -Wno-unused -lm -o $@ $<`
add_executable(${TARGET_PREFIX}speed speed.c)
target_compile_options(${TARGET_PREFIX}speed PRIVATE -ansi -W -Wall -Wno-unused)
target_link_libraries(${TARGET_PREFIX}speed PRIVATE m)

# OG: `gcc -pg -c -ansi -W -Wall -Wno-unused $<`
#     `gcc -pg bubble.o -o $@`
add_executable(${TARGET_PREFIX}bubble bubble.c)
target_compile_options(${TARGET_PREFIX}bubble PRIVATE -ansi -W -Wall -Wno-unused  -pg)
target_link_libraries(${TARGET_PREFIX}bubble PRIVATE -pg)
