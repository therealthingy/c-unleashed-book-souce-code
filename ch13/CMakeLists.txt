set(TARGET_PREFIX ch13-)

add_library(${TARGET_PREFIX}prng OBJECT)
target_sources(${TARGET_PREFIX}prng PRIVATE cockus.c)
target_include_directories(${TARGET_PREFIX}prng PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # `mtrand.h`

add_library(${TARGET_PREFIX}distribs STATIC)
target_sources(${TARGET_PREFIX}distribs PRIVATE distribs.c)
target_include_directories(${TARGET_PREFIX}distribs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET_PREFIX}distribs PUBLIC ${TARGET_PREFIX}prng m)

add_library(${TARGET_PREFIX}keyxfrm OBJECT)
target_sources(${TARGET_PREFIX}keyxfrm PRIVATE keyxfrm.c)
target_include_directories(${TARGET_PREFIX}keyxfrm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${TARGET_PREFIX}sort STATIC)
target_sources(${TARGET_PREFIX}sort PRIVATE sint.c double.c strings.c)
target_include_directories(${TARGET_PREFIX}sort PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # `allsort.h`
target_link_libraries(${TARGET_PREFIX}sort PRIVATE ${TARGET_PREFIX}keyxfrm)

#add_executable(${TARGET_PREFIX}prng_test cockus.c)
#add_compile_definitions(${TARGET_PREFIX}prng_test UNIT_TEST)

add_executable(${TARGET_PREFIX}test test.c)
target_link_libraries(
    ${TARGET_PREFIX}test
    PRIVATE ${TARGET_PREFIX}distribs
            ${TARGET_PREFIX}sort
            ${TARGET_PREFIX}keyxfrm
            ${TARGET_PREFIX}prng)

add_executable(${TARGET_PREFIX}bar bar.c)
target_link_libraries(
    ${TARGET_PREFIX}bar
    PRIVATE ${TARGET_PREFIX}distribs
            ${TARGET_PREFIX}sort
            ${TARGET_PREFIX}keyxfrm
            ${TARGET_PREFIX}prng)
