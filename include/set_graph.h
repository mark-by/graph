#ifndef MODULE_3_SET_GRAPH_H
#define MODULE_3_SET_GRAPH_H
#include "igraph.h"

class SetGraph: public IGraph {
public:
    void addEdge(int from, int to) override;
    int verticesCount() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
};
#endif //MODULE_3_SET_GRAPH_H
