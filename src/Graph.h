//
// Created by feld on 04-03-2023.
//

#ifndef DA_QUIMBOIO_GRAPH_H
#define DA_QUIMBOIO_GRAPH_H

#include "Station.h"
#include <unordered_map>
#include <vector>
#include <string>

struct Edge{
    std::string dest;
    int temp;
    int cap;
    std::string type;
};
struct Node{
    std::vector<Edge> adj;
    bool visited;
};

class Graph {
private:
    int n = 0; //Graph size
    std::unordered_map<std::string,Node> nodes;
public:
    Graph();
    int addStation(Station s);
    bool addTransport(std::string source, std::string dest, int capacity, std::string type);
    void removeVisited();
    std::unordered_map<std::string, Node> getNodes();
    Graph removeNode(std::string rm);
    std::vector<std::pair<std::vector<std::string>,int>> getPaths(std::string source, std::string dest);
};


#endif //DA_QUIMBOIO_GRAPH_H
