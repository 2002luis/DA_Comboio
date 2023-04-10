//
// Created by feld on 04-03-2023.
//

#include <iostream>
#include <string>
#include <ostream>
#include <unordered_map>
#include "data_structs/Station.h"
#include "data_structs/Graph.h"
#include "fileReader.h"
#include "overloads.h"
#include "menu.h"

int main(){
    try {
        menu();
    }
    /*
    catch (std::ios_base::failure &fail) {
        menu::error(fail.what());
        return 1;
    }
    catch (std::exception &ex) {
        menu::error(ex.what());
        return 1;
    }
    /*
    /*
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


    test.addBidirectionalEdge(s1,s2,5,"");
    test.addBidirectionalEdge(s2,s3,3,"");
    test.addBidirectionalEdge(s1,s4,3,"");
    test.addBidirectionalEdge(s4,s5,3,"");
    test.addBidirectionalEdge(s5,s6,5,"");
    test.addBidirectionalEdge(s3,s6,3,"");



    std::cout << test.costOptimization("s1","s6");



    //std::cout << test;

    //test.dfs(s1.name,s6.name);


    test.addBidirectionalEdge(s2,s5,5,"");

    //test.dfs(s1.name,s6.name);

    //std::cout << test;

    //test.fordFulkerson(s1.name,s6.name);

    //std::cout << test << std::endl << std::endl << test.maxInPath(s1.name,s6.name);

    //std::cout << test.maxPairs();


    //std::cout << test << std::endl << std::endl << test.maxInPath(s1.name,s6.name);

    //fileReader fR("TestData");

    //std::cout << std::endl << std::endl << fR.g << std::endl;

    //std::cout << test.maxArriveInStation(s6.name) << std::endl << test;

    test.removeFlow();

    test.removeVertex(s2.name);

    std::cout << test;
     */
    /*
    fileReader fR("TestData");
    Graph g2(&fR.g);

    g2.removeEdge("s2","s3");

    std::cout << fR.g << std::endl << g2 << std::endl;

    fR.g.maxInPath("s1","s6");
    g2.maxInPath("s1","s6");

    std::cout << fR.g << std::endl << g2;

    std::cout << fR.g.getDiffs(&g2,10);
    */
    return 0;
}