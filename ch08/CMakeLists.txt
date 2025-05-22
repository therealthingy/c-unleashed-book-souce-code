
set(USE_MEM_TRACK TRUE)   # TODO: Should be CMake config option


add_library(memtrack OBJECT)
target_sources(memtrack PRIVATE memtrack.c)


add_executable(memtrkmn memtrkmn.c)
target_link_libraries(memtrkmn PRIVATE memtrack)

if (USE_MEM_TRACK)
    add_compile_definitions(memtrack MEMTRACK)
    add_compile_definitions(memtrkmn MEMTRACK)
endif()
