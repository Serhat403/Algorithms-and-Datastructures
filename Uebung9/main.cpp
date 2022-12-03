#include <iostream>
#include "Graph.hpp"
int main() {

    Graph *g = new Graph();
    g->insertVertex(MyVertex());
    g->getNumberOfVertices();
    std::cout << g->getNumberOfVertices() << std::endl;
    return 0;
}
