//
// Created by feld on 04-03-2023.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <list>

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, std::pair<T1,T2> p){
    o << p.first << ":" << p.second;
    return o;
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& o, std::vector<std::pair<T1,T2>> p){
    for(auto i : p) o << i.first << ":" << i.second << ' ';
    return o;
}

std::ostream& operator<<(std::ostream& o, std::vector<std::pair<std::vector<std::string>,int>> p){
    for(auto i : p){
        for(auto j : i.first) o << j << " -> ";
        o << i.second << '\n';
    }
    return o;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> v){
    for(auto i : v) o << v << ' ';
    return o;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, std::list<T> v){
    for(auto i : v) o << v << ' ';
    return o;
}