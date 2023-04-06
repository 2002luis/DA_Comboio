//
// Created by feld on 04-03-2023.
//

#ifndef DA_QUIMBOIO_STATION_H
#define DA_QUIMBOIO_STATION_H

#include <string>

class Station {
public:
    std::string name, district, municipality, township, line;
    /**
     * @brief Sets the variables
     * Complexity O(1)
     * @param std::string name
     * @param std::string district
     * @param std::string municipality
     * @param std::string township
     * @param std::string line
     */
    Station(std::string name, std::string district, std::string municipality, std::string township, std::string line);
    /**
     * @brief Sets the variables based on one suffix, for testing purposes
     * Complexity O(1)
     * @param std::string n
     */
    Station(std::string n); //construtor da preguiça
    Station();
};


#endif //DA_QUIMBOIO_STATION_H
