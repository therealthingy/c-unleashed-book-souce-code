set(TARGET_PREFIX ch12-)

add_library(${TARGET_PREFIX}trees OBJECT)
target_sources(
    ${TARGET_PREFIX}trees
    PRIVATE avl.c
            bin.c
            pbin.c
            rb.c
            tbin.c)
