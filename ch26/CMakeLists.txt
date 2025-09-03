set(TARGET_PREFIX ch26-)

add_subdirectory(book_listings/)

#add_library(${TARGET_PREFIX}byteorder OBJECT)
#target_sources(${TARGET_PREFIX}byteorder PRIVATE byteorder.c)

add_library(${TARGET_PREFIX}modes OBJECT)
target_sources(${TARGET_PREFIX}modes PRIVATE modes.c)
