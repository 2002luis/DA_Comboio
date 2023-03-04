//
// Created by feld on 04-03-2023.
//

#include "Station.h"

Station::Station(std::string name, std::string district, std::string municipality, std::string township, std::string line){
    this->name=name;
    this->district=district;
    this->municipality=municipality;
    this->township=township;
    this->line=line;
}