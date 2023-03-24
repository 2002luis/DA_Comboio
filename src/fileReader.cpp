//
// Created by luism on 21/03/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "fileReader.h"

fileReader::fileReader() {
    this->g = fileReader("Project1Data").g;
}

fileReader::fileReader(std::string dir){
    dir = "../" + dir;
    this->readStations(dir+"/stations.csv");
    this->readNetwork(dir+"/network.csv");
}

void fileReader::readStations(std::string dir){
    std::ifstream ifs(dir);
    std::string line;
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = this->formatStr(line);
        std::string name,district,municipality,township,tline;
        std::istringstream iss(line);
        iss >> name >> district >> municipality >> township >> tline;

        name = this->unformatStr(name);
        district = this->unformatStr(district);
        municipality = this->unformatStr(municipality);
        township = this->unformatStr(township);
        tline = this->unformatStr(tline);

        Station s(name,district,municipality,township,tline);

        this->g.addVertex(s);
    }
}
void fileReader::readNetwork(std::string dir){
    std::ifstream ifs(dir);
    std::string line;
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = this->formatStr(line);
        std::string s1, s2, type;
        double cap;
        std::istringstream iss(line);
        iss >> s1 >> s2 >> cap >> type;

        s1 = this->unformatStr(s1);
        s2 = this->unformatStr(s2);
        type = this->unformatStr(type);

        this->g.addBidirectionalEdge(s1,s2,cap,type);
    }
}

std::string fileReader::formatStr(std::string in){
    bool invComma = false;
    std::string out = "";
    for(unsigned long int i = 0; i < in.size(); i++){
        if(in[i] == '"') invComma = !invComma;
        else if(invComma && in[i] == ',') out.push_back('#');
        else if(in[i] == ',') out.push_back(' ');
        else if(in[i] == ' ') out.push_back('_');
        else out.push_back(in[i]);
    }
    return out;
}

std::string fileReader::unformatStr(std::string in){
    std::string out = "";
    for(unsigned long int i = 0; i < in.size(); i++){
        if(in[i] == '#') out.push_back(',');
        else if(in[i] == '_') out.push_back(' ');
        else out.push_back(in[i]);
    }
    return out;
}