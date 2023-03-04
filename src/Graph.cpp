//
// Created by feld on 04-03-2023.
//

#include "Graph.h"
#include <queue>

Graph::Graph(){
    this->n=0;
}

int Graph::addStation(Station s) {
    if(this->nodes.find(s.name)!=this->nodes.end()) return this->n;
    this->nodes.insert({s.name,{{},false}});
    this->n++;
    return this->n;
}

std::unordered_map<std::string, Node> Graph::getNodes(){
    return this->nodes;
}

bool Graph::addTransport(std::string source, std::string dest, int capacity, std::string type) {
    if(this->nodes.find(source)==this->nodes.end()) return false;
    this->nodes.find(source)->second.adj.push_back({dest,0,capacity,type});
    this->nodes.find(dest)->second.adj.push_back({source,0,capacity,type}); //Grafo nao direcionado
    return true;
}

void Graph::removeVisited() {
    for (auto &i : this->nodes){
        i.second.visited=false;
        for(auto &j : i.second.adj) j.temp = 0;
    }
}

std::vector<std::pair<std::vector<std::string>,int>> Graph::getPaths(std::string source, std::string dest){
    this->removeVisited();
    std::queue<std::pair<std::vector<std::string>,int>> paths;
    std::vector<std::pair<std::vector<std::string>,int>> out;

    paths.push({{source},INT16_MAX});
    this->nodes.find(source)->second.visited=true;

    while(!paths.empty()){
        std::string frontName = paths.front().first.back();
        int frontLim = paths.front().second;
        if(frontName == dest) out.push_back(paths.front());
        else {
            this->nodes.find(frontName)->second.visited = true;
            for (auto i: this->nodes.find(frontName)->second.adj) {
                if(!this->nodes.find(i.dest)->second.visited) {
                    auto stuff = paths.front().first;
                    stuff.push_back(i.dest);
                    paths.push({stuff,std::min(frontLim,i.cap)});
                }
            }
        }
        paths.pop();
    }

    return out;


}