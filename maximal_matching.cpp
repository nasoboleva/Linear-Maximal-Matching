#include <iostream>
#include <vector>

struct Edge {
    size_t v;
    size_t u;

    Edge (size_t v_, size_t u_) : v(v_), u(u_) {}
};


struct Matching {
    std::vector<Edge> matching;
    std::vector<bool> vertecies;

    Matching (size_t VertexNumber) {
        vertecies.resize(VertexNumber, false);
    }
};


Matching FindMatching (std::vector<Edge> graph_, size_t VertexNumber) {
    Matching matching_(VertexNumber);
    for (const auto edge: graph_) {
        if (!matching_.vertecies[edge.v] && !matching_.vertecies[edge.u]) {
            matching_.matching.push_back(edge);
            matching_.vertecies[edge.v] = true;
            matching_.vertecies[edge.u] = true;
        }
    }
    return matching_;
}

int main()
{
    size_t VertexNumber, EdgeNumber;
    std::cin >> VertexNumber >> EdgeNumber;
    std::vector<Edge> graph;
    for (size_t i = 0; i != EdgeNumber; ++i) {
        size_t v, u;
        std::cin >> v >> u;
        graph.push_back(Edge(v, u));
    }
    Matching maximal_matching = FindMatching(graph, VertexNumber);
    std::cout << "Ребра полученного паросочетания:" << std::endl;
    for (const auto edge: maximal_matching.matching) {
        std::cout << "(" << edge.v << "," << edge.u << ")" << std::endl;
    }
    return 0;
}
