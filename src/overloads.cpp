//
// Created by feld on 11-03-2023.
//

#include "overloads.h"
#include <iostream>
#include <vector>
#include "data_structs/Graph.h"
#include "data_structs/Station.h"
#include "data_structs/VertexEdge.h"


std::ostream& operator<<(std::ostream& o, Station s){
    o << s.name << " " << s.line;
    return o;
}

std::ostream& operator<<(std::ostream& o, Vertex* v){
    o  << v->s << v->getAdj();
    return o;
}

std::ostream& operator<<(std::ostream& o, std::vector<Vertex*> v){
    for(auto i : v) o << i << " curPath: " << ((i->getPath()!=nullptr)?i->getPath()->getDest()->s.name:" nada ") << std::endl;
    return o;
}

std::ostream& operator<<(std::ostream& o, std::vector<Edge*> v){
    o << " ( ";
    for(auto i : v) o << i << ' ';
    o << ')';
    return o;
}

std::ostream& operator<<(std::ostream& o, Edge* e){
    o << e->getOrig()->s.name << "->" << e->getDest()->s.name << " " << e->getFlow() << '/' << e->getWeight();
    return o;
}

std::ostream& operator<<(std::ostream& o, Graph g){
    o << g.getVertexSet();
    return o;
}