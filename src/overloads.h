//
// Created by feld on 04-03-2023.
//

#ifndef DA_QUIMBOIO_OVERLOADS_H
#define DA_QUIMBOIO_OVERLOADS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, std::pair<T1,T2> p);

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, std::vector<std::pair<T1,T2>> p);

std::ostream& operator<<(std::ostream& o, std::vector<std::pair<std::vector<std::string>,int>> p);

template<typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> v);

template<typename T>
std::ostream& operator<<(std::ostream& o, std::list<T> v);

#endif //DA_QUIMBOIO_OVERLOADS_H
