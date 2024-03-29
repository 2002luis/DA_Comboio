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
#include "fileReader.h"
#include "overloads.h"

class menu {
private:

public:
    menu();
    /**
     * @brief Main menu of all the program with all the functionalities
     *
     *
     */
    void mainMenu();
    /**
     * @brief Function to return to the main menu
     *
     *
     */
    void back();
    /**
     * @brief Function for printing errors
     *
     *
     * @param std::string error name
     */
    static void error(const std::string &s);
    Graph g;
};


#endif //DA_QUIMBOIO_MENU_H
