#include "gtest/gtest.h"
#include <list_graph.h>
#include <matrix_graph.h>
#include <set_graph.h>
#include <arc_graph.h>

auto print = [](int v) {
    std::cout << v << std::endl;
};

std::vector<std::pair<int, int>> edges = {{0, 1},
                                          {1, 2},
                                          {2, 3},
                                          {2, 4},
                                          {3, 4},
                                          {1, 6},
                                          {4, 2},};

std::vector<int> etalonDfs = {0, 1, 2, 3, 4, 6, 5};
std::vector<int> etalonBfs = {0, 1, 2, 6, 3, 4, 5};

std::vector<int> etalonNextVerticesFor1 = {2, 6};
std::vector<int> etalonPrevVerticesFor4 = {2, 3};

void fill(IGraph &graph) {
    for (auto &pair : edges) {
        graph.addEdge(pair.first, pair.second);
    }
}

void getDFS_BFS(IGraph &graph, std::vector<int> &dfsOut, std::vector<int> &bfsOut) {
    graph.dfs([&dfsOut](int v) {
        dfsOut.push_back(v);
    });
    graph.bfs([&bfsOut](int v) {
        bfsOut.push_back(v);
    });
}

TEST(ListGraph, DFS_BFS) {
    ListGraph graph(7);
    std::vector<int> dfsOut, bfsOut;
    fill(graph);
    getDFS_BFS(graph, dfsOut, bfsOut);
    EXPECT_EQ(dfsOut, etalonDfs);
    EXPECT_EQ(bfsOut, etalonBfs);
}

TEST(ListGraph, next_prevVertices) {
    ListGraph graph(7);
    fill(graph);
    EXPECT_EQ(etalonNextVerticesFor1, graph.getNextVertices(1));
    EXPECT_EQ(etalonPrevVerticesFor4, graph.getPrevVertices(4));
}

TEST(MatrixGraph, DFS_BFS) {
    MatrixGraph graph(7);
    std::vector<int> dfsOut, bfsOut;
    fill(graph);
    getDFS_BFS(graph, dfsOut, bfsOut);
    EXPECT_EQ(dfsOut, etalonDfs);
    EXPECT_EQ(bfsOut, etalonBfs);
}

TEST(MatrixGraph, next_prevVertices) {
    MatrixGraph graph(7);
    fill(graph);
    EXPECT_EQ(etalonNextVerticesFor1, graph.getNextVertices(1));
    EXPECT_EQ(etalonPrevVerticesFor4, graph.getPrevVertices(4));
}

TEST(SetGraph, DFS_BFS) {
    SetGraph graph(7);
    std::vector<int> dfsOut, bfsOut;
    fill(graph);
    getDFS_BFS(graph, dfsOut, bfsOut);
    EXPECT_EQ(dfsOut, etalonDfs);
    EXPECT_EQ(bfsOut, etalonBfs);
}

TEST(SetGraph, next_prevVertices) {
    SetGraph graph(7);
    fill(graph);
    EXPECT_EQ(etalonNextVerticesFor1, graph.getNextVertices(1));
    EXPECT_EQ(etalonPrevVerticesFor4, graph.getPrevVertices(4));
}


TEST(ArcGraph, DFS_BFS) {
    ArcGraph graph(7);
    std::vector<int> dfsOut, bfsOut;
    fill(graph);
    getDFS_BFS(graph, dfsOut, bfsOut);
    EXPECT_EQ(dfsOut, etalonDfs);
    EXPECT_EQ(bfsOut, etalonBfs);
}

TEST(ArcGraph, next_prevVertices) {
    ArcGraph graph(7);
    fill(graph);
    EXPECT_EQ(etalonNextVerticesFor1, graph.getNextVertices(1));
    EXPECT_EQ(etalonPrevVerticesFor4, graph.getPrevVertices(4));
}

TEST(Copy, copyTest) {
    ListGraph listGraph(7);
    fill(listGraph);
    MatrixGraph matrixGraph(listGraph);
    SetGraph setGraph(matrixGraph);
    ArcGraph arcGraph(setGraph);

    std::vector<int> listDFS, listBFS, matrixDFS, matrixBFS, setDFS, setBFS, arcDFS, arcBFS;
    getDFS_BFS(listGraph, listDFS, listBFS);
    getDFS_BFS(matrixGraph, matrixDFS, matrixBFS);
    getDFS_BFS(setGraph, setDFS, setBFS);
    getDFS_BFS(arcGraph, arcDFS, arcBFS);

    EXPECT_EQ(listDFS, etalonDfs);
    EXPECT_EQ(matrixDFS, etalonDfs);
    EXPECT_EQ(setDFS, etalonDfs);
    EXPECT_EQ(arcDFS, etalonDfs);

    EXPECT_EQ(listBFS, etalonBfs);
    EXPECT_EQ(matrixBFS, etalonBfs);
    EXPECT_EQ(setBFS, etalonBfs);
    EXPECT_EQ(arcBFS, etalonBfs);
}