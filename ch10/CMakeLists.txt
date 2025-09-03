set(TARGET_PREFIX ch10-)

add_compile_options(
    -ansi
    -pedantic
    -Wall
    -O2
    -pipe)

add_executable(${TARGET_PREFIX}fact1 fact1.c)
add_executable(${TARGET_PREFIX}fact2 fact2.c)
add_executable(${TARGET_PREFIX}fact3 fact3.c)
add_executable(${TARGET_PREFIX}fib1 fib1.c)
add_executable(${TARGET_PREFIX}fib2 fib2.c)
add_executable(${TARGET_PREFIX}fib3 fib3.c)
add_executable(${TARGET_PREFIX}gcd1 gcd1.c)
add_executable(${TARGET_PREFIX}gcd2 gcd2.c)
add_executable(${TARGET_PREFIX}gcd3 gcd3.c)
add_executable(${TARGET_PREFIX}hello hello.c)
add_executable(${TARGET_PREFIX}search search.c)
add_executable(${TARGET_PREFIX}tok1 tok1.c)
add_executable(${TARGET_PREFIX}tok2 tok2.c)
add_executable(${TARGET_PREFIX}tok3 tok3.c)
