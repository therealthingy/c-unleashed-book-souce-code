set(TARGET_PREFIX ch04-)


add_executable(${TARGET_PREFIX}Listing01 Listing01.c)
add_executable(${TARGET_PREFIX}Listing02 Listing02.c)
add_executable(${TARGET_PREFIX}Listing03 Listing03.c)
add_executable(${TARGET_PREFIX}Listing04 Listing04.c)
add_executable(${TARGET_PREFIX}Listing05 Listing05.c)

add_library(${TARGET_PREFIX}Listing06 OBJECT Listing06.c)
add_library(${TARGET_PREFIX}Listing07 OBJECT Listing07.c)
