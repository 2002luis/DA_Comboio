//
// Created by feld on 04-03-2023.
//

#include <iostream>
#include <string>
#include <ostream>
#include "data_structs/Station.h"
#include "data_structs/Graph.h"
#include "overloads.h"

int main(){
    Station s1("1"), s2("2");
    Station s3("3"), s4("4");
    Station s5("5"), s6("6");
    Graph test;
    test.addVertex(s1);
    test.addVertex(s2);
    test.addVertex(s3);
    test.addVertex(s4);
    test.addVertex(s5);
    test.addVertex(s6);

    //std::cout << test;

    std::cout << "\n\n\n\n\n";

    test.addBidirectionalEdge(s1,s2,3);
    test.addBidirectionalEdge(s2,s3,3);
    test.addBidirectionalEdge(s1,s4,3);
    test.addBidirectionalEdge(s4,s5,3);
    test.addBidirectionalEdge(s5,s6,3);
    test.addBidirectionalEdge(s3,s6,3);

    //std::cout << test;

    //test.dfs(s1.name,s6.name);

    test.addBidirectionalEdge(s2,s5,5);
    test.dfs(s1.name,s6.name);

    //std::cout << test;

    test.fordFulkerson(s1.name,s6.name);

    std::cout << test;
}