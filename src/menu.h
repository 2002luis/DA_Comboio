//
// Created by rui on 13/03/2023.
//

#ifndef DA_QUIMBOIO_MENU_H
#define DA_QUIMBOIO_MENU_H

#include "iostream"
#include "string"
#include "data_structs/Station.h"
#include "data_structs/Graph.h"
#include "data_structs/VertexEdge.h"

class menu {
private:

public:
    Station userStation;
    menu();
    void mainMenu();
    void back();
    static void error(const std::string &s);
};


#endif //DA_QUIMBOIO_MENU_H
