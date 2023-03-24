// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>

#include "VertexEdge.h"

class Graph {
public:
    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const int &id) const;
    Vertex *findVertex(const std::string name) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(Station s);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const std::string &sourc, const std::string &dest, double w, std::string type); //A principio n se vai usar
    bool addBidirectionalEdge(const std::string &sourc, const std::string &dest, double w, std::string type);

    bool addBidirectionalEdge(Station s1, Station s2, double w, std::string type); //Funcao pq sou preguiçoso

    int getNumVertex() const;
    std::vector<Vertex *> getVertexSet() const;



    void fordFulkerson(std::string src, std::string dest); //A funcao q importa
    void fordFulkerson(Vertex* src, Vertex* dest);
    bool dfs(Vertex* src, Vertex* dest);
    bool dfs(std::string src, std::string dest);

    double anyDfs(Vertex* src);  //funcao a ser chamada em loop para descobrir um caminho qualquer
    double anyDfs(std::string src);

    void removePaths();
    void removeFlow();
    void removeVisited();

    double maxInPath(std::string src, std::string dest); //4.1 T2.1 3.5 valores
    double maxInPath(Vertex* src, Vertex* dest);

    std::vector<std::pair<Vertex*,Vertex*>> maxPairs(); //4.2 T2.2 2 valores

    double maxArriveInStation(std::string dest); //4.4 1 valor
    double maxArriveInStation(Vertex* dest);

    std::unordered_map<std::string, int> stList;
protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;


};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */