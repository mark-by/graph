#include <igraph.h>
#include <queue>
#include <stack>

void IGraph::fs(void(*anyFS)(const IGraph *, int, std::vector<bool> &, const std::function<void(int)> &), const std::function<void(int)> & clb) {
    std::vector<bool> visited(verticesCount(), false);
    for (int vertex = 0; vertex < verticesCount(); vertex++) {
        if (!visited[vertex]) {
            anyFS(this, vertex, visited, clb);
        }
    }
}

void IGraph::dfs(const std::function<void(int)>& clb) {
    fs(__dfs, clb);
}

void IGraph::bfs(const std::function<void(int)>& clb) {
    fs(__bfs, clb);
}

void IGraph::__dfs(const IGraph * graph, int vertex, std::vector<bool> &visited, const std::function<void(int)>& clb) {
    std::stack<int> stack;
    stack.push(vertex);
    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();
        if (visited[currentVertex]) {
            continue;
        }

        visited[currentVertex] = true;
        clb(currentVertex);

        std::vector<int> nextVertices = graph->getNextVertices(currentVertex);
        for (auto it = nextVertices.rbegin(); it != nextVertices.rend(); it++) {
            currentVertex = *it;
            if (!visited[currentVertex]) {
                stack.push(currentVertex);
            }
        }

    }
}

void IGraph::__bfs(const IGraph * graph,int vertex, std::vector<bool> &visited, const std::function<void(int)>& clb) {
    std::queue<int> verticesQueue;
    verticesQueue.push(vertex);
    while (!verticesQueue.empty()) {
        int currVertex = verticesQueue.front();
        verticesQueue.pop();
        clb(currVertex);
        std::vector<int> nextVertices = graph->getNextVertices(currVertex);
        for (int child : nextVertices) {
            if (!visited[child]) {
                visited[child] = true;
                verticesQueue.push(child);
            }
        }
    }
}

void IGraph::copy(const IGraph &other) {
    for (int vertex = 0; vertex < other.verticesCount(); vertex++) {
        std::vector<int> nextVertices = other.getNextVertices(vertex);
        for (auto &v : nextVertices) {
            addEdge(vertex, v);
        }
    }
}

