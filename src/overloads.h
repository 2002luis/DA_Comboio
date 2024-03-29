//
// Created by feld on 11-03-2023.
//

#ifndef DA_QUIMBOIO_OVERLOADS_H
#define DA_QUIMBOIO_OVERLOADS_H

#include <iostream>
#include <vector>
#include "data_structs/Graph.h"
#include "data_structs/Station.h"
#include "data_structs/VertexEdge.h"

std::ostream& operator<<(std::ostream& o, Station s);

std::ostream& operator<<(std::ostream& o, Vertex* v);

std::ostream& operator<<(std::ostream& o, std::vector<Vertex*> v);

std::ostream& operator<<(std::ostream& o, std::vector<Edge*> v);

std::ostream& operator<<(std::ostream& o, Edge* e);

std::ostream& operator<<(std::ostream& o, Graph g);

std::ostream& operator<<(std::ostream& o, std::pair<Vertex*,Vertex*> vp);

std::ostream& operator<<(std::ostream& o, std::vector<std::pair<Vertex*,Vertex*>> v);

std::ostream& operator<<(std::ostream& o, std::pair<int,int> p);

std::ostream& operator<<(std::ostream& o, std::vector<std::pair<Edge*, int>> v);


#endif //DA_QUIMBOIO_OVERLOADS_H
