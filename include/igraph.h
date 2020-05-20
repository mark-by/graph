#ifndef MODULE_3_IGRAPH_H
#define MODULE_3_IGRAPH_H

#include <vector>
#include <functional>

class IGraph {
public:
    virtual ~IGraph() = default;

    virtual void addEdge(int from, int to) = 0;

    virtual int verticesCount() const = 0;

    virtual std::vector<int> getNextVertices(int vertex) const = 0;

    virtual std::vector<int> getPrevVertices(int vertex) const = 0;

    void bfs(const std::function<void(int)> &clb);

    void dfs(const std::function<void(int)> &clb);

protected:

    void copy(const IGraph &other);

    static void __bfs(const IGraph *graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &clb);

    static void __dfs(const IGraph *graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &clb);

    void fs(void (*anyFS)(const IGraph *, int, std::vector<bool> &, const std::function<void(int)> &clb),
            const std::function<void(int)> &clb);
};

#endif //MODULE_3_IGRAPH_H
