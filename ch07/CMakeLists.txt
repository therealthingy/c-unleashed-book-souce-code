
add_library(cfollow STATIC)
target_sources(cfollow PRIVATE cfollow.c)
target_include_directories(cfollow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(cfollowd cfollowd.c)
target_link_libraries(cfollowd PRIVATE cfollow)

add_executable(ch07s001 ch07s001.c)
add_executable(ch07s003 ch07s003.c)
add_executable(ch07s016 ch07s016.c)
add_executable(ch07s017 ch07s017.c)
add_executable(ch07s018 ch07s018.c)
add_executable(ch07s019 ch07s019.c)
add_executable(ch07s020 ch07s020.c)
add_executable(ch07s021 ch07s021.c)
add_executable(ch07s024 ch07s024.c)
add_executable(ch07s027 ch07s027.c)
add_executable(ch07s037 ch07s037.c)
#ch07s048
