set(TARGET_PREFIX ch08-)


set(USE_MEM_TRACK TRUE)   # TODO: Should be CMake config option


add_library(${TARGET_PREFIX}memtrack OBJECT)
target_sources(${TARGET_PREFIX}memtrack PRIVATE memtrack.c)


add_executable(${TARGET_PREFIX}memtrkmn memtrkmn.c)
target_link_libraries(${TARGET_PREFIX}memtrkmn PRIVATE ${TARGET_PREFIX}memtrack)

if (USE_MEM_TRACK)
    add_compile_definitions(${TARGET_PREFIX}memtrack MEMTRACK)
    add_compile_definitions(${TARGET_PREFIX}memtrkmn MEMTRACK)
endif()
