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

    catch (std::ios_base::failure &fail) {
        menu::error(fail.what());
        return 1;
    }
    catch (std::exception &ex) {
        menu::error(ex.what());
        return 1;
    }

    return 0;
}