#include <matrix_graph.h>

MatrixGraph::MatrixGraph(int verticesCount) : _matrix(verticesCount) {
    for (auto &row : _matrix) {
        row.resize(verticesCount, false);
    }
}

void MatrixGraph::addEdge(int from, int to) {
    _matrix[from][to] = true;
}

int MatrixGraph::verticesCount() const {
    return _matrix.size();
}

std::vector<int> MatrixGraph::getNextVertices(int vertex) const {
    std::vector<int> result;
    for (int v = 0; v < verticesCount(); v++) {
        if (_matrix[vertex][v]) {
            result.push_back(v);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::getPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int v = 0; v < verticesCount(); v++) {
        if (_matrix[v][vertex]) {
            result.push_back(v);
        }
    }
    return result;
}

MatrixGraph::MatrixGraph(const IGraph &other) : _matrix(other.verticesCount()){
    for (auto &row : _matrix) {
        row.resize(other.verticesCount(), false);
    }
    copy(other);
}

