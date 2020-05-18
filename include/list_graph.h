#ifndef MODULE_3_LIST_GRAPH_H
#define MODULE_3_LIST_GRAPH_H
#include "igraph.h"

class ListGraph: public IGraph {
public:
    void addEdge(int from, int to) override;
    int verticesCount() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
};
#endif //MODULE_3_LIST_GRAPH_H
