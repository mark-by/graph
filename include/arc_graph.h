#ifndef MODULE_3_ARCGRAPH_H
#define MODULE_3_ARCGRAPH_H
#include "igraph.h"

class ArcGraph: public IGraph {
public:
    explicit ArcGraph(int verticesCount) : _verticesCount(verticesCount) {}
    explicit ArcGraph(const IGraph & other);
    void addEdge(int from, int to) override;
    int verticesCount() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
private:
    std::vector<std::pair<int, int>> _edges;
    int _verticesCount;
};
#endif //MODULE_3_ARCGRAPH_H
