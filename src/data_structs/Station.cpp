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

Station::Station(Station* s){
    this->name=s->name;
    this->district=s->district;
    this->municipality=s->municipality;
    this->township=s->township;
    this->line=s->line;
}

Station::Station(){
    this->name="";
    this->district="";
    this->municipality="";
    this->township="";
    this->line="";
}