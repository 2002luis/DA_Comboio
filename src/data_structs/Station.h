//
// Created by feld on 04-03-2023.
//

#ifndef DA_QUIMBOIO_STATION_H
#define DA_QUIMBOIO_STATION_H

#include <string>

class Station {
public:
    std::string name, district, municipality, township, line;
    Station(std::string name, std::string district, std::string municipality, std::string township, std::string line);
};


#endif //DA_QUIMBOIO_STATION_H
