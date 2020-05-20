#include <arc_graph.h>

void ArcGraph::addEdge(int from, int to) {
    _edges.emplace_back(from, to);
}

int ArcGraph::verticesCount() const {
    return _verticesCount;
}

std::vector<int> ArcGraph::getNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto &edge : _edges) {
        if (edge.first == vertex) {
            result.push_back(edge.second);
        }
    }
    return result;
}

std::vector<int> ArcGraph::getPrevVertices(int vertex) const {
    std::vector<int> result;
    for (auto &edge : _edges) {
        if (edge.second == vertex) {
            result.push_back(edge.first);
        }
    }
    return result;
}

ArcGraph::ArcGraph(const IGraph &other) : _verticesCount(other.verticesCount()) {
    copy(other);
}
