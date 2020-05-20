#ifndef MODULE_3_MATRIX_GRAPH_H
#define MODULE_3_MATRIX_GRAPH_H
#include "igraph.h"

class MatrixGraph: public IGraph {
public:
    explicit MatrixGraph(int verticesCount);
    explicit MatrixGraph(const IGraph & other);

    void addEdge(int from, int to) override;
    int verticesCount() const override;

    std::vector<int> getNextVertices(int vertex) const override;
    std::vector<int> getPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<bool>> _matrix;
};
#endif //MODULE_3_MATRIX_GRAPH_H
