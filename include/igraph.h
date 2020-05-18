#ifndef MODULE_3_IGRAPH_H
#define MODULE_3_IGRAPH_H
#include <vector>

struct IGraph {
    virtual ~IGraph() {}

    virtual void addEdge(int from, in to) = 0;
    virtual int verticesCount() const = 0;

    virtual std::vector<int> getNextVertices(int vertex) const = 0;
    virtual std::vector<int> getPrevVertices(int vertex) const = 0;
};
#endif //MODULE_3_IGRAPH_H
