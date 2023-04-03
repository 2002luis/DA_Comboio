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



void menu::mainMenu() {
    std::cout << "\n\n\n"
                 "||═════════════════════════════||\n"
                 "||       RAILWAY NETWORK       ||\n"
                 "||═════════════════════════════||\n";

    std::cout << "\nChoose one topic:\n"
                 "[1] \n"
                 "[2] \n"
                 "[3] \n"

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


        //
        if (topicMenu == 1) {

        }


        //
        else if (topicMenu == 2) {

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



menu::menu() {
    std::cout << "\n\n\n"
                 "||═════════════════════════════||\n"
                 "||       RAILWAY NETWORK       ||\n"
                 "||═════════════════════════════||\n";

    std::cout << "\nChoose one topic:\n"
                 "[1] Station login.\n"
                 "[2] Guest.\n"

                 "\n[0] Quit.\n"
                 "> ";

    int topicLogin;
    std::string preventErrors;
    while (true) {
        topicLogin = 0;
        preventErrors = "";
        std::cin >> preventErrors;
        //try and catch to prevent input errors
        try {
            topicLogin = stoi(preventErrors);
        }
        catch (...) {
            topicLogin = 666;
        }


        //program with login
        /*if (topicLogin == 1) {
            std::cout << "\nStation name:\n"
                         "> ";
            std::string stationName;
            std::cin >> stationName;
            Station station;
            station = Station(stationName);
            while (station.name.empty()) {
                std::cout << "Invalid name.\n"
                             "> ";
                std::cin >> stationName;
                Station station = Station(stationName);
            }
            userStation = station;

            std::cout << "\n" << station.name;
            mainMenu();
        }*/

        //program with guest
        /*else*/ if (topicLogin == 2) mainMenu();

        //quit the program
        else if (topicLogin == 0) exit(0);

        //invalid topic
        else {
            std::cout << "Invalid topic.\n"
                         "> ";
        }
    }
}


