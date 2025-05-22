
set(COMPILE_OPTIONS_CH10 -ansi -pedantic -Wall -O2 -pipe)


add_executable(fact1 fact1.c)
target_compile_options(fact1 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(fact2 fact2.c)
target_compile_options(fact2 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(fact3 fact3.c)
target_compile_options(fact3 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(fib1 fib1.c)
target_compile_options(fib1 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(fib2 fib2.c)
target_compile_options(fib2 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(fib3 fib3.c)
target_compile_options(fib3 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(gcd1 gcd1.c)
target_compile_options(gcd1 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(gcd2 gcd2.c)
target_compile_options(gcd2 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(gcd3 gcd3.c)
target_compile_options(gcd3 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(hello hello.c)
target_compile_options(hello PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(search search.c)
target_compile_options(search PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(tok1 tok1.c)
target_compile_options(tok1 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(tok2 tok2.c)
target_compile_options(tok2 PRIVATE ${COMPILE_OPTIONS_CH10})

add_executable(tok3 tok3.c)
target_compile_options(tok3 PRIVATE ${COMPILE_OPTIONS_CH10})
