//
// Created by feld on 04-03-2023.
//

#ifndef DA_QUIMBOIO_NODE_H
#define DA_QUIMBOIO_NODE_H

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

#endif //DA_QUIMBOIO_NODE_H
