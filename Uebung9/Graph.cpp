//
// Created by Serhat on 22.01.2022.
//

#include "Graph.hpp"
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

Graph::Graph() {

}

// muss man hier size -1 rechnen
int Graph::getNumberOfVertices() {
    return (int)vertices.size();
}


// muss man hier nur return verticises
std::vector<MyVertex> Graph::getVertices() {
    return vertices;
}

int Graph::insertVertex(MyVertex v) {
    if (find(vertices.begin(), vertices.end(), v) != vertices.end()) { return -1; }
    vertices.push_back(v);
    return vertices.size()-1;

}

/* Liefert das Gewicht der Kante zwischen Knoten v1 und v2 wenn
    sie existiert, ansonsten -1. */


int Graph::getEdgeWeight(MyVertex v1, MyVertex v2) {

    //auto begin = vertices.begin();
    //auto end= vertices.end();
    //auto vertex1Index = find(begin, end, v1);
    //auto vertex2Index = find(begin, end, v2);

    for(int i=0;i<edges.size();i++){
        if(edges[i].out==v1 && edges[i].in == v2 || edges[i].out==v2 && edges[i].in==v1){
            return edges[i].weight;
        }
    }
    return -1;
}
// ???????????????????


bool Graph::insertEdge(MyVertex v1, MyVertex v2, int weight) {
    Edge edge;
    edge.in = v1;
    edge.out = v2;
    edge.weight = weight;
    edges.push_back(edge);
    return true;
}

std::vector<std::vector<int>> Graph::getAdjacencyMatrix() {
    vector<vector<int>> matrix(vertices.size(), vector<int>(vertices.size(), -1));
    int zaehler1=0;
    int zaehler2=0;
    for(auto zm1:vertices) {
        for(auto zm2: vertices) {
            matrix[zaehler1][zaehler2++] = getEdgeWeight(zm1,zm2 );
        }
        zaehler1++;
        zaehler2++;
    }
    return matrix;
}
//hilfe
//for (auto v : vertices) {
//if (colorOfVertex(v, colors) == WHITE) {
//}
// man braucht hier getedgeweight


//********************************************************************************
// Teil 2 // Anfang
//********************************************************************************
//

 bool Graph::isConnected() {
     return true;
 }

int Graph::getNumberOfComponents() {
    return 0;
}

void Graph::printComponents() {

}

bool Graph::isCyclic() {
    return false;
}

