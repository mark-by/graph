#include <set_graph.h>

void SetGraph::addEdge(int from, int to) {
    _vertices[from].insert(to);
}

int SetGraph::verticesCount() const {
    return _vertices.size();
}

std::vector<int> SetGraph::getNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto &v : _vertices[vertex]) {
        result.push_back(v);
    }
    return result;
}

std::vector<int> SetGraph::getPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < verticesCount(); i++) {
        for (auto & v : _vertices[i]) {
            if (v == vertex) {
                result.push_back(i);
            }
        }
    }
    return result;
}

SetGraph::SetGraph(const IGraph &other) : _vertices(other.verticesCount()) {
    copy(other);
}

