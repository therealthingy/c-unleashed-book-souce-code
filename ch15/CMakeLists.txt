
add_library(sparse STATIC)
target_sources(sparse PRIVATE
        get_header_list.c
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
        tuple_dim.c
)
target_include_directories(sparse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(testme testme.c)
target_link_libraries(testme PRIVATE sparse)
