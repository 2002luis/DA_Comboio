//
// Created by feld on 04-03-2023.
//

#include <iostream>
#include <string>
#include <ostream>
#include "overloads.h"
#include "Station.h"
#include "Graph.h"

int main(){
    Station s1("s1","d1","m1","t1","l1"), s2("s2","d2","m2","t2","l2");
    Station s3("s3","d3","m3","t3","l3"), s4("s4","d4","m4","t4","l4");
    Station s5("s5","d5","m5","t5","l5");
    Graph test;
    test.addStation(s1);
    test.addStation(s2);
    test.addStation(s3);
    test.addStation(s4);
    test.addStation(s5);
    test.addTransport("s1","s2",10,"t1");
    test.addTransport("s2","s5",10,"t1");
    test.addTransport("s1","s3",100,"t2");
    test.addTransport("s3","s5",5,"t2");
    test.addTransport("s3","s4",200,"t2");
    test.addTransport("s4","s5",200,"t2");

    std::cout << test.getPaths("s1","s2");

}