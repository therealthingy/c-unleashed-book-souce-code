
add_library(trie STATIC)
target_sources(trie PRIVATE trie.c trie_extra.c)
target_include_directories(trie PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_trie test_trie.c)
target_link_libraries(test_trie PRIVATE trie)
