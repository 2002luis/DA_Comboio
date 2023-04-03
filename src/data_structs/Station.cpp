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

Station::Station(std::string n){
    this->name="s"+n;
    this->district="d"+n;
    this->municipality="m"+n;
    this->township="t"+n;
    this->line="l"+n;
}

Station::Station(){
    this->name="";
    this->district="";
    this->municipality="";
    this->township="";
    this->line="";
}

Station Station::get_station(std::string &name) {

    return Station();
}
