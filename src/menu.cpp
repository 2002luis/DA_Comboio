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
        if (back == 1) mainMenu();
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

            while (!(g.findVertex(src) && g.findVertex(dest))) {
                std::cout << "\nInvalid stations.\n";
                std::cout << "\nWrite the name of two stations:\n"
                             "> ";
                std::cin >> src;
                std::cout << "> ";
                std::cin >> dest;
            }

            double ret;
            bool clear = true;
            ret = g.maxInPath(src, dest, clear);
            std::cout << "\nThe maximum number of trains is " << ret << ".\n";
            /*
            4-
             5- costOptimization (numero de comboios, preço) --> AINDA N TA
             6- criar outro graph igual, queres tirar vertex ou edge? fazer o 1 topico
            7- criar outro graph igual, queres tirar vertex ou edge? fazer o 3 topico. getDiffs
             */

            back();
        }


        //the station pairs that require the most amount of trains when taking full advantage of the existing network capacity
        else if (topicMenu == 2) {
            std::cout << "\nThe pairs of stations are (wait a moment):\n";
            std::vector<std::pair<Vertex*,Vertex*>> ret;
            ret = g.maxPairs();

            for (auto i : ret) {
                std::cout << "> " << i.first->s.name << " => " << i.second->s.name << "\n";
            }

            back();
        }


        //where management should assign larger budgets for the purchasing and maintenance of trains
        else if (topicMenu == 3) {
            g.sortTopList();

            std::cout << "\nChoose one topic:\n"
                         "[1] Districts\n"
                         "[2] Municipalities\n"
                         "[3] Different districts\n"
                         "[4] Different municipalities\n"
                         "> ";

            int howMany = 0;
            int topic;
            std::string preventError;
            while (true) {
                topic = 0;
                preventError = "";
                std::cin >> preventError;
                //try and catch to prevent input errors
                try {
                    topic = stoi(preventError);
                }
                catch (...) {
                    topic = 666;
                }
                if (topic == 1) {
                    std::cout << "\nHow many results?\n"
                                 "> ";
                    std::cin >> howMany;
                    if (howMany <= 0) break;
                    for (auto i : g.topDistSorted) {
                        std::cout << "> " << i.first << " => " << i.second << "\n";
                        howMany--;
                        if (howMany == 0) break;
                    }
                    if (howMany != 0) {
                        std::cout << "(no more data).\n";
                    }

                    break;
                }
                else if (topic == 2) {
                    std::cout << "\nHow many results?\n"
                                 "> ";
                    std::cin >> howMany;
                    if (howMany <= 0) break;
                    for (auto i : g.topMunSorted) {
                        std::cout << "> " << i.first << " => " << i.second << "\n";
                        howMany--;
                        if (howMany == 0) break;
                    }
                    if (howMany != 0) {
                        std::cout << "(no more data).\n";
                    }

                    break;
                }
                else if (topic == 3) {
                    std::cout << "\nHow many results?\n"
                                 "> ";
                    std::cin >> howMany;
                    if (howMany <= 0) break;
                    for (auto i : g.topDistOnlySameSorted) {
                        std::cout << "> " << i.first << " => " << i.second << "\n";
                        howMany--;
                        if (howMany == 0) break;
                    }
                    if (howMany != 0) {
                        std::cout << "(no more data).\n";
                    }

                    break;
                }
                else if (topic == 4) {
                    std::cout << "\nHow many results?\n"
                                 "> ";
                    std::cin >> howMany;
                    if (howMany <= 0) break;
                    for (auto i : g.topMunOnlySameSorted) {
                        std::cout << "> " << i.first << " => " << i.second << "\n";
                        howMany--;
                        if (howMany == 0) break;
                    }
                    if (howMany != 0) {
                        std::cout << "(no more data).\n";
                    }

                    break;
                }
                std::cout << "> Invalid topic.\n"
                             "[1] Districts\n"
                             "[2] Municipalities\n"
                             "[3] Different districts\n"
                             "[4] Different municipalities\n"
                             "> ";
            }

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
            Graph g2(g);
            std::cout << "\nDo you want to remove something:\n"
                         "[1] Yes, remove\n"
                         "[2] No\n"
                         "> ";

            int removeTopic = 0;
            std::cin >> removeTopic;
            while (true) {
                if (removeTopic == 1) {
                    std::cout << "\nWhat do you want removed:\n"
                                 "[1] Station\n"
                                 "[2] Edge\n"
                                 "> ";

                    std::string src, dest, name;
                    Station stationSup;
                    int choiceTopic = 0;
                    std::cin >> choiceTopic;
                    while (true) {
                        if (choiceTopic == 1) {
                            std::cout << "\nWrite the name of the station:\n"
                                         "> ";

                            std::cin >> name;
                            while (!(g2.findVertex(name))) {
                                std::cout << "\nInvalid station.\n";
                                std::cout << "\nWrite the name of the station:\n"
                                             "> ";
                                std::cin >> name;
                            }

                            g2.removeVertex(name);
                            break;
                        }
                        else if (choiceTopic == 2) {
                            std::cout << "\nWrite the name of two stations:\n"
                                         "> ";
                            std::cin >> src;
                            std::cout << "> ";
                            std::cin >> dest;

                            while (!(g2.findVertex(src) && g2.findVertex(dest))) {
                                std::cout << "\nInvalid stations.\n";
                                std::cout << "\nWrite the name of two stations:\n"
                                             "> ";
                                std::cin >> src;
                                std::cout << "> ";
                                std::cin >> dest;
                            }

                            g2.removeEdge(src, dest);
                            break;
                        }
                        std::cout << "> Invalid topic.\n"
                                     "[1] Yes, remove\n"
                                     "[2] No\n"
                                     "> ";
                    }
                    break;
                }
                else if (removeTopic == 2) {
                    std::cout << "topic 4.1 or 4.2?\n"
                                 "[1] \n"
                                 "[2] \n"
                                 "> ";
                    int choiceTopic = 0;
                    std::cin >> choiceTopic;
                    while (true) {
                        if (choiceTopic == 1) {

                            break;
                        }
                        else if (choiceTopic == 2) {

                            break;
                        }
                        std::cout << "> Invalid topic.\n"
                                     "[1] \n"
                                     "[2] \n"
                                     "> ";
                    }
                }
                else {
                    std::cout << "> Invalid topic.\n"
                                 "[1] Yes, remove\n"
                                 "[2] No\n"
                                 "> ";
                }
            }

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



menu::menu() {
    fileReader fr("Project1Data");
    g = fr.g;
    mainMenu();
}


