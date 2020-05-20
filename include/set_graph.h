#ifndef MODULE_3_SET_GRAPH_H
#define MODULE_3_SET_GRAPH_H
#include "igraph.h"
#include <set>

class SetGraph: public IGraph {
public:
    explicit SetGraph(int verticesCount) : _vertices(verticesCount) {}
    explicit SetGraph(const IGraph & other);
    void addEdge(int from, int to) override;
    int verticesCount() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
private:
    std::vector<std::set<int>> _vertices;
};
#endif //MODULE_3_SET_GRAPH_H
