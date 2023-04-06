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

    /**
     * @brief Copies another graph
     * Complexity O(V+E)
     * @param Graph* graph to copy
     */
    Graph(Graph* copy);
    /**
    * @brief Auxiliary function to find a vertex with a given ID.
     *
     * Complexity O(V+E)
     * @param int id
     * @return Vertex*
    */
    Vertex *findVertex(const int &id) const;
    /**
    * @brief Auxiliary function to find a vertex with a given ID.
     *
     * Complexity O(1)
     * @param std::string name of the station in the vertex
     * @return Vertex*
    */
    Vertex *findVertex(const std::string name) const;
    /**
     *  @brief Adds a vertex with a given content or info (in) to a graph (this).
     *
     *  Complexity O(1)
     *  @param Station s
     *  @return Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(Station s);

    /**
     * @brief Adds an edge to a graph (this), given the contents of the source and destination vertices and the edge weight (w).
     *
     * Complexity O(1)
     * @param std::string source station name
     * @param std::string destination station name
     * @param double max capacity between stations
     * @param std::string type (either "STANDARD" or other)
     * @return Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const std::string &sourc, const std::string &dest, double w, std::string type); //A principio n se vai usar

    /**
     * @brief Adds two edges to a graph (this), one in each direction, given the contents of the source and destination vertices and the edge weight (w).
     *
     * Complexity O(1)
     * @param std::string source station name
     * @param std::string destination station name
     * @param double max capacity between stations
     * @param std::string type (either "STANDARD" or other)
     * @return Returns true if successful, and false if the source or destination vertex does not exist.
     */

    bool addBidirectionalEdge(const std::string &sourc, const std::string &dest, double w, std::string type);

    /**
     * @brief Adds two edges to a graph (this), one in each direction, given the contents of the source and destination vertices and the edge weight (w).
     *
     * Complexity O(1)
     * @param Station source station
     * @param Station destination station
     * @param double max capacity between stations
     * @param std::string type (either "STANDARD" or other)
     * @return Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addBidirectionalEdge(Station s1, Station s2, double w, std::string type); //Funcao pq sou preguiçoso

    /**
     * @brief Returns vertex set.
     * @return std::vector<Vertex*>
     */
    std::vector<Vertex *> getVertexSet() const;


    /**
     * @brief Calculates maximum flow between two stations
     *
     * The flow variables of each edge are changed, and the result can be used by other functions
     * Complexity O(V+E)
     * @param std::string origin station name
     * @param std::string destination station name
     */
    void fordFulkerson(std::string src, std::string dest); //A funcao q importa
    /**
     * @brief Calculates maximum flow between two stations
     *
     * The flow variables of each edge are changed, and the result can be used by other functions
     * Complexity O(V+E)
     * @param Vertex* origin station
     * @param Vertex* destination station
     */
    void fordFulkerson(Vertex* src, Vertex* dest);
    /**
     * @brief Finds a path between two stations
     *
     * Sets nodes path variable so that it can be used by other functions
     * Complexity O(V+E)
     * @param Vertex* origin station
     * @param Vertex* destination station
     * @return bool true if path was found otherwise false
     */
    bool dfs(Vertex* src, Vertex* dest);
    /**
     * @brief Finds a path between two stations
     *
     * Sets nodes path variable so that it can be used by other functions
     * Complexity O(V+E)
     * @param std::string origin station name
     * @param std::string destination station
     * @return bool true if path was found otherwise false
     */
    bool dfs(std::string src, std::string dest);

    /**
     * @brief Sets the path variable of all vertices to nullptr
     *
     * Complexity O(V)
     */
    void removePaths();
    /**
     * @brief Sets the flow variable of all edges to 0
     *
     * Complexity O(V+E)
     */
    void removeFlow();
    /**
     * @brief Sets the visited variable of all vertices to false
     *
     * Complexity O(V)
     */
    void removeVisited();

    /**
     * @brief Calculates the maximum flow from src to dest (EX T2.1)
     *
     * The function calls fordFelkurson(src,dest) and then sums the contents of the edges incoming to dest
     *
     * Complexity O(V+E)
     * @param std::string src
     * @param std::string dest
     * @return double
     */
    double maxInPath(std::string src, std::string dest); //T2.1 3.5 valores
    /**
     * @brief Calculates the maximum flow from src to dest (EX T2.1)
     *
     * The function calls fordFelkurson(src,dest) and then sums the contents of the edges incoming to dest
     * Complexity O(V+E)
     * @param Vertex* src
     * @param Vertex* dest
     * @return double
     */
    double maxInPath(Vertex* src, Vertex* dest);


    /**
     * @brief Finds pairs of stations from which most trains can travel at once (EX T2.2)
     *
     *
     * Complexity O(V+E)
     * @param std::string src
     * @param std::string dest
     * @return std::vector<std::pair<Vertex*,Vertex*>> returns all stations that have the same max flow
     */
    std::vector<std::pair<Vertex*,Vertex*>> maxPairs(); //T2.2 2 valores

    std::unordered_map<std::string, int> stList;

    /**
     * @brief Sorts the lists of top municipalities and districts, both counting and not counting inter district/municipality travel
     *
     *
     *
     * Complexity O(n * log(n))
     * @return double
     */
    void sortTopList(); //T2.3
    std::vector<std::pair<std::string,double>> topDistSorted, topMunSorted, topDistOnlySameSorted, topMunOnlySameSorted;

    /**
     * @brief Finds the cheapest way to send the most trains from src to dest
     *
     * Considers "STANDARD" type edges to cost 2€ per train and any other type edges to cost 4€ per train.
     *
     * Complexity O(V+E)
     * @param std::string source station name
     * @param std::string destination station name
     * @return std::pair<int,int> first is the number of trains, the second is the cost
     */
    std::pair<int,int> costOptimization(std::string src, std::string dest);
    /**
     * @brief Finds the cheapest way to send the most trains from src to dest
     *
     * Considers "STANDARD" type edges to cost 2€ per train and any other type edges to cost 4€ per train.
     *
     * Complexity O(V+E)
     * @param Vertex* source station
     * @param Vertex* destination station
     * @return std::pair<int,int> first is the number of trains, the second is the cost
     */
    std::pair<int,int> costOptimization(Vertex* src, Vertex* dest);
    /**
     * @brief Finds the lowest cost path to get from src to dest
     *
     * Considers "STANDARD" type edges to cost 2€ per train and any other type edges to cost 4€ per train.
     * Sets nodes path variable so that it can be used by other functions
     *
     * Complexity O(V+E)
     * @param Vertex* source station
     * @param Vertex* destination station
     * @return int the cost, returns -1 if no path found
     */
    int djikstra(Vertex* src, Vertex* dest);

    /**
     * @brief Removes edge starting in a and ending in b (also starting in b and ending in a)
     *
     * Complexity O(V+E)
     * @param std::string source station name
     * @param std::string destination station name
     */
    void removeEdge(std::string a, std::string b); //T4.1
    /**
     * @brief Removes edge starting in a and ending in b (also starting in b and ending in a)
     *
     * Complexity O(E)
     * @param Vertex* source station
     * @param Vertex* destination station
     */
    void removeEdge(Vertex* a, Vertex* b);
    /**
     * @brief Removes edge and reverse edge from graph
     *
     * Complexity O(1)
     * @param Edge*
     */
    void removeEdge(Edge* e);

    /**
     * @brief Removes vertex from graph
     *
     * Complexity O(1)
     * @param Vertex* vertex to remove
     */
    void removeVertex(Vertex* a); //tudo 4.1
    /**
     * @brief Removes vertex from graph
     *
     * Complexity O(1)
     * @param std::string name of station in vertex to remove
     */
    void removeVertex(std::string n);
    /**
     * @brief Removes vertex from graph
     *
     * Complexity O(1)
     * @param int id of vertex to remove
     */
    void removeVertex(int n);

    /**
     * @brief Compares differences between edges of two graphs,
     *
     * Complexity O(V+E)
     * @param Graph* graph to compare
     * @param int number of edges to output
     * @return std::vector<std::pair<Edge*,int>> edges of the different graphs and their difference in flow
     */
    std::vector<std::pair<Edge*,int>> getDiffs(Graph* g, int n); // 4.2????
protected:
    std::vector<Vertex *> vertexSet;    // vertex set
    std::unordered_map<std::string, double> topDist, topMun, topDistOnlySame, topMunOnlySame;

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /**
     * @brief Finds the index of the vertex with a given content.
     * @param int content
     * @return id
     */
    int findVertexIdx(const int &id) const;

    /**
     * @brief Returns the numbers of vertices in the graph
     * @return int
     */
    int getNumVertex() const;
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);



#endif /* DA_TP_CLASSES_GRAPH */