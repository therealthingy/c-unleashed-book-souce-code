add_library(${TARGET_PREFIX}byteorder OBJECT)
target_sources(${TARGET_PREFIX}byteorder PRIVATE byteorder.c)
target_include_directories(${TARGET_PREFIX}byteorder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${TARGET_PREFIX}rc4 STATIC)
target_sources(${TARGET_PREFIX}rc4 PRIVATE rc4.c)
target_link_libraries(${TARGET_PREFIX}rc4 PRIVATE ${TARGET_PREFIX}byteorder)
target_include_directories(${TARGET_PREFIX}rc4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}rc4n rc4n.c)
target_link_libraries(${TARGET_PREFIX}rc4n PRIVATE ${TARGET_PREFIX}rc4)

add_library(${TARGET_PREFIX}sha1 STATIC)
target_sources(${TARGET_PREFIX}sha1 PRIVATE sha1.c)
target_link_libraries(${TARGET_PREFIX}sha1 PRIVATE ${TARGET_PREFIX}byteorder)
target_include_directories(${TARGET_PREFIX}sha1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}sha1n sha1n.c)
target_link_libraries(${TARGET_PREFIX}sha1n PRIVATE ${TARGET_PREFIX}sha1)
