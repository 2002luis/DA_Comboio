//
// Created by up202108878 on 13/03/2023.
//

#include "menu.h"

menu::menu() {
    std::cout << "\n\n\n"
                 "||                         ||\n"
                 "||     RAILWAY NETWORK     ||\n"
                 "||                         ||\n";

    std::cout << "\nChoose one topic:\n"
                 "[1] \n"
                 "[2] \n"
                 "[3] \n"
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


        if (topicMenu == 1) {

        }

        else if (topicMenu == 2) {

        }


        //quit the program
        else if (topicMenu == 0) break;
        //invalid topic
        else {
            std::cout << "Invalid topic.\n"
                         "> ";
        }
    }
}

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
        else if (back == 0) break;
        std::cout << "> Invalid topic.\n"
                "[1] Back to Menu.\n"
                "[0] Quit.\n"
                "> ";
    }
}


