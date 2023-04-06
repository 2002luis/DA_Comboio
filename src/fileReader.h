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
    /**
     * @brief Reads the contents of the files in the directory ../dir into the variable g
     *
     * Complexity O(N)
     * @param dir the directory to be read (if left empty, reads "Project1Data"
     */
    fileReader(std::string dir);
    /**
     * @brief Formats the string into an easier to process form.
     *
     * Complexity O(N)
     * @param str The string to be processed
     * @return The processed string
     */
    std::string formatStr(std::string in);
    /**
     * @brief Formats the string back into normal
     *
     * Complexity O(N)
     * @param str The string to be processed
     * @return The processed string
     */
    std::string unformatStr(std::string in);
    /**
     * @brief Reads the stations (vertices) in ../dir/stations.csv and saves them in g
     *
     * Complexity O(N)
     * @param str The directory
     */
    void readStations(std::string dir);
    /**
     * @brief Reads the network (edges) in ../dir/network.csv and saves it in g
     *
     * Complexity O(N)
     * @param str The directory
     */
    void readNetwork(std::string dir);
    Graph g;
};


#endif //DA_QUIMBOIO_FILEREADER_H
