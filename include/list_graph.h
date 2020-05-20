#ifndef MODULE_3_LIST_GRAPH_H
#define MODULE_3_LIST_GRAPH_H
#include "igraph.h"

class ListGraph: public IGraph {
public:
    explicit ListGraph(int verticesCount) : _vertices(verticesCount) {}
    explicit ListGraph(const IGraph & other);

    void addEdge(int from, int to) override;
    int verticesCount() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<int>> _vertices;
};
#endif //MODULE_3_LIST_GRAPH_H
