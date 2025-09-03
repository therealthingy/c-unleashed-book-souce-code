set(TARGET_PREFIX ch15-)

add_library(${TARGET_PREFIX}sparse STATIC)
target_sources(
    ${TARGET_PREFIX}sparse
    PRIVATE get_header_list.c
            add_header_dimension.c
            add_tuple.c
            del_header_element.c
            del_node.c
            del_tuple.c
            get_node_list.c
            get_range_max.c
            get_range_min.c
            hdr_list_element_get.c
            ins_header_element.c
            ins_node.c
            next_node.c
            previous_node.c
            retrieve_node.c
            tuple_dim.c)
target_include_directories(${TARGET_PREFIX}sparse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TARGET_PREFIX}testme testme.c)
target_link_libraries(${TARGET_PREFIX}testme PRIVATE ${TARGET_PREFIX}sparse)
