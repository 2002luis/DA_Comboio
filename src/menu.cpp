//
// Created by rui on 13/03/2023.
//

#include "menu.h"


void menu::back() {
    std::cout << "\n[1] Back to Menu.\n"
                 "[0] Quit.\n"
                 "> ";

    //topic selection in function back
    int back;
    std::string preventErrors;
    while (true) {
        back = 0;
        preventErrors = "";
        std::cin >> preventErrors;
        //try and catch to prevent input errors
        try {
            back = stoi(preventErrors);
        }
        catch (...) {
            back = 666;
        }
        if (back == 1) menu();
        else if (back == 0) exit(0);
        std::cout << "> Invalid topic.\n"
                     "[1] Back to Menu.\n"
                     "[0] Quit.\n"
                     "> ";
    }
}



void menu::error(const std::string &erro) {
    std::cout << "Error: " << erro << "\n";
}



menu::menu() {
    std::cout << "\n\n\n"
                 "||-----------------------------||\n"
                 "||       RAILWAY NETWORK       ||\n"
                 "||-----------------------------||\n";

    std::cout << "\nChoose one topic:\n"
                 "[1] The maximum amount of trains that can simultaneously travel between two stations.\n"
                 "[2] The station pairs that require the most amount of trains when taking full advantage of the existing network capacity.\n"
                 "[3] Where management should assign larger budgets for the purchasing and maintenance of trains.\n"
                 //"[4] The maximum quantity of trains that can simultaneously arrive at a given station.\n"
                 "[5] The maximum number of trains that can simultaneously travel between two stations with minimum cost.\n"
                 "[6] The maximum quantity of trains that can simultaneously travel between two stations in a network of reduced connectivity.\n"
                 "[7] Provide a report on the stations that are the most affected by each segment failure.\n"

                 "\n[0] Quit.\n"
                 "> ";

    //topic selection in menu
    int topicMenu;
    std::string preventErrors;
    while (true) {
        topicMenu = 0;
        preventErrors = "";
        std::cin >> preventErrors;
        //try and catch to prevent input errors
        try {
            topicMenu = stoi(preventErrors);
        }
        catch (...) {
            topicMenu = 666;
        }


        //the maximum amount of trains that can simultaneously travel between two stations
        if (topicMenu == 1) {
            std::cout << "\nWrite the name of two stations:\n"
                         "> ";
            std::string src, dest;
            std::cin >> src;
            std::cout << "> ";
            std::cin >> dest;

            double ret;
            bool clear = true;
            Graph g;
            fileReader fr("TestData");
            ret = fr.g.maxInPath(src, dest, clear);

            std::cout << "\nThe maximum number of trains is " << ret << ".";
            /*
            1-maxInPath
            2-maxpairs
             3-sortTopList   , municipios/distritos?? , distritos diferentes??, pedir quantos quer
            4-
             5-
             6-
             */

            back();
        }


        //the station pairs that require the most amount of trains when taking full advantage of the existing network capacity
        else if (topicMenu == 2) {


            back();
        }


        //where management should assign larger budgets for the purchasing and maintenance of trains
        else if (topicMenu == 3) {


            back();
        }


        //the maximum quantity of trains that can simultaneously arrive at a given station
        else if (topicMenu == 4) {


            back();
        }


        //the maximum number of trains that can simultaneously travel between two stations with minimum cost
        else if (topicMenu == 5) {


            back();
        }


        //the maximum quantity of trains that can simultaneously travel between two stations in a network of reduced connectivity
        else if (topicMenu == 6) {


            back();
        }


        //provide a report on the stations that are the most affected by each segment failure
        else if (topicMenu == 7) {


            back();
        }


        //quit the program
        else if (topicMenu == 0) exit(0);

        //invalid topic
        else {
            std::cout << "Invalid topic.\n"
                         "> ";
        }
    }
}


