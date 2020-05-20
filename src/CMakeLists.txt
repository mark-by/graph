include_directories(../include)

set(graph_source
        igraph.cpp
        list_graph.cpp
        matrix_graph.cpp
        set_graph.cpp
        arc_graph.cpp)

add_library(graph STATIC ${graph_source})