set(TARGET_PREFIX ch14-)

add_library(${TARGET_PREFIX}trie STATIC)
target_sources(${TARGET_PREFIX}trie PRIVATE trie.c trie_extra.c)
target_include_directories(${TARGET_PREFIX}trie PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}test_trie test_trie.c)
target_link_libraries(${TARGET_PREFIX}test_trie PRIVATE ${TARGET_PREFIX}trie)
