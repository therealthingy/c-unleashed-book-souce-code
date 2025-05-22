
add_library(prng OBJECT)
target_sources(prng PRIVATE cockus.c)
target_include_directories(prng PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})  # `mtrand.h`

add_library(distribs STATIC)
target_sources(distribs PRIVATE distribs.c)
target_include_directories(distribs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(distribs PUBLIC prng)

add_library(keyxfrm OBJECT)
target_sources(keyxfrm PRIVATE keyxfrm.c)
target_include_directories(keyxfrm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(sort STATIC)
target_sources(sort PRIVATE
        sint.c
        double.c
        strings.c)
target_include_directories(sort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # `allsort.h`
target_link_libraries(sort PRIVATE keyxfrm)


#add_executable(prng_test cockus.c)
#add_compile_definitions(prng_test UNIT_TEST)

add_executable(test test.c)
target_link_libraries(test PRIVATE
        distribs
        sort
        keyxfrm
        prng)

add_executable(bar bar.c)
target_link_libraries(bar PRIVATE
        distribs
        sort
        keyxfrm
        prng)
