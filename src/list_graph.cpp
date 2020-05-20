#include <list_graph.h>

void ListGraph::addEdge(int from, int to) {
    _vertices.at(from).push_back(to);
}

int ListGraph::verticesCount() const {
    return _vertices.size();
}

std::vector<int> ListGraph::getNextVertices(int vertex) const {
    std::vector<int> result;

    result.resize(_vertices[vertex].size());
    std::copy(_vertices[vertex].cbegin(), _vertices[vertex].cend(), result.begin());

    return result;
}

std::vector<int> ListGraph::getPrevVertices(int vertex) const {
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

ListGraph::ListGraph(const IGraph &other) : _vertices(other.verticesCount()) {
    copy(other);
}
