find_package(Threads REQUIRED)

include_directories(../include)

file(GLOB graph_tests *.cpp)

add_executable(
        graph_tests
        ${graph_tests})

target_link_libraries(graph_tests
        graph
        gtest_main
        pthread
)

add_test(NAME graph_tests
        COMMAND graph_tests)
