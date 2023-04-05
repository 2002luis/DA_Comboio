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
    Graph();
    Graph(Graph* copy);
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



    void fordFulkerson(std::string src, std::string dest, bool clear); //A funcao q importa
    void fordFulkerson(Vertex* src, Vertex* dest, bool clear);
    bool dfs(Vertex* src, Vertex* dest);
    bool dfs(std::string src, std::string dest);


    void removePaths();
    void removeFlow();
    void removeVisited();

    double maxInPath(std::string src, std::string dest, bool clear); //T2.1 3.5 valores
    double maxInPath(Vertex* src, Vertex* dest, bool clear);

    std::vector<std::pair<Vertex*,Vertex*>> maxPairs(); //T2.2 2 valores

    std::unordered_map<std::string, int> stList;


    void sortTopList(); //T2.3
    std::vector<std::pair<std::string,double>> topDistSorted, topMunSorted, topDistOnlySameSorted, topMunOnlySameSorted;

    std::pair<int,int> costOptimization(std::string src, std::string dest);
    std::pair<int,int> costOptimization(Vertex* src, Vertex* dest);
    int djikstra(Vertex* src, Vertex* dest);

    void removeEdge(std::string a, std::string b); //T4.1
    void removeEdge(Vertex* a, Vertex* b);
    void removeEdge(Edge* e);

    void removeVertex(Vertex* a); //tudo 4.1
    void removeVertex(std::string n);
    void removeVertex(int n);

    std::vector<std::pair<Edge*,int>> getDiffs(Graph* g, int n); // 4.2????
protected:
    std::vector<Vertex *> vertexSet;    // vertex set
    std::unordered_map<std::string, double> topDist, topMun, topDistOnlySame, topMunOnlySame;

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