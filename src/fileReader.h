//
// Created by luism on 21/03/2023.
//

#ifndef DA_QUIMBOIO_FILEREADER_H
#define DA_QUIMBOIO_FILEREADER_H

#include <string>
#include "data_structs/Graph.h"
#include "data_structs/Station.h"

class fileReader {
public:
    fileReader();
    fileReader(std::string dir);
    std::string formatStr(std::string in);
    std::string unformatStr(std::string in);
    void readStations(std::string dir);
    void readNetwork(std::string dir);
    Graph g;
};


#endif //DA_QUIMBOIO_FILEREADER_H
