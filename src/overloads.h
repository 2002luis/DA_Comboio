//
// Created by feld on 04-03-2023.
//

#ifndef DA_QUIMBOIO_OVERLOADS_H
#define DA_QUIMBOIO_OVERLOADS_H

#include "node.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_map>

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, std::pair<T1,T2> p);

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, std::vector<std::pair<T1,T2>> p);

std::ostream& operator<<(std::ostream& o, std::vector<std::pair<std::vector<std::string>,int>> p);

template<typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> v);

template<typename T>
std::ostream& operator<<(std::ostream& o, std::list<T> v);

std::ostream& operator<<(std::ostream& o, std::unordered_map<std::string,Node>);

#endif //DA_QUIMBOIO_OVERLOADS_H
