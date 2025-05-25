set(TARGET_PREFIX ch07-)


add_library(${TARGET_PREFIX}cfollow STATIC)
target_sources(${TARGET_PREFIX}cfollow PRIVATE cfollow.c)
target_include_directories(${TARGET_PREFIX}cfollow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(${TARGET_PREFIX}cfollowd cfollowd.c)
target_link_libraries(${TARGET_PREFIX}cfollowd PRIVATE ${TARGET_PREFIX}cfollow)

add_executable(${TARGET_PREFIX}ch07s001 ch07s001.c)
add_executable(${TARGET_PREFIX}ch07s003 ch07s003.c)
add_executable(${TARGET_PREFIX}ch07s016 ch07s016.c)
add_executable(${TARGET_PREFIX}ch07s017 ch07s017.c)
add_executable(${TARGET_PREFIX}ch07s018 ch07s018.c)
add_executable(${TARGET_PREFIX}ch07s019 ch07s019.c)
add_executable(${TARGET_PREFIX}ch07s020 ch07s020.c)
add_executable(${TARGET_PREFIX}ch07s021 ch07s021.c)
add_executable(${TARGET_PREFIX}ch07s024 ch07s024.c)
add_executable(${TARGET_PREFIX}ch07s027 ch07s027.c)
add_executable(${TARGET_PREFIX}ch07s037 ch07s037.c)
#ch07s048
