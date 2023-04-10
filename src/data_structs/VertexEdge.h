// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_VERTEX_EDGE
#define DA_TP_CLASSES_VERTEX_EDGE

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "Station.h"

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

//the classes for vertex, edge and graph given by the teachers were used, as such some variables are left unused in this project

class Vertex {
public:
    Vertex(int id, Station s);
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue

    /**
     * @brief Returns ID
     * Complexity O(1)
     * @return int
     */
    int getId() const;

    /**
     * @brief Returns edges
     * Complexity O(1)
     * @return std::vector<Edge*>
     */
    std::vector<Edge *> getAdj();
    /**
     * @brief Returns visited
     * Complexity O(1)
     * @return bool
     */
    bool isVisited() const;
    /**
     * @brief Returns processing
     * Complexity O(1)
     * @return bool
     */
    bool isProcesssing() const;
    /**
     * @brief Returns indegree
     * Complexity O(1)
     * @return unsigned int
     */
    unsigned int getIndegree() const;
    /**
     * @brief Returns dist
     * Complexity O(1)
     * @return double
     */
    double getDist() const;
    /**
     * @brief Returns path
     * Complexity O(1)
     * @return Edge*
     */
    Edge *getPath() const;
    /**
     * @brief Returns incoming edges
     * Complexity O(1)
     * @return std::Vector<Edge*>
     */
    std::vector<Edge *> getIncoming() const;
    Station s;


    /**
     * @brief sets id
     * Complexity O(1)
     * @param int id
     */
    void setId(int info);
    /**
     * @brief sets visited
     * Complexity O(1)
     * @param bool visited
     */
    void setVisited(bool visited);
    /**
     * @brief sets processing
     * Complexity O(1)
     * @param bool processing
     */
    void setProcesssing(bool processing);
    /**
     * @brief sets indegree
     * Complexity O(1)
     * @param unsigned_int id
     */
    void setIndegree(unsigned int indegree);
    /**
     * @brief sets dist
     * Complexity O(1)
     * @param double dist
     */
    void setDist(double dist);
    /**
     * @brief sets path
     * Complexity O(1)
     * @param Edge*
     */
    void setPath(Edge *path);
    /**
     * @brief adds edge
     * Complexity O(1)
     * @param Vertex* the destination
     * @param double the max flow of the edge
     * @param std::string the type (either "STANDARD" or other)
     */
    Edge * addEdge(Vertex *dest, double w, std::string type);
    /**
     * @brief removes an edge
     * Complexity O(N)
     * @param int the id of the edge to be removed
     */

    /**
     * @brief finds whether there is an edge with destination on station dest
     * Complexity O(N)
     * @param std::string the name of the station to be found
     * @return bool true if found, false if not
     */
    bool findAdj(std::string dest);
    bool removeEdge(int destID);

protected:

    int id;                // identifier
    std::vector<Edge *> adj;  // outgoing edges

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge *path = nullptr;

    std::vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double w, std::string type);

    /**
     * @brief Returns destination vertex
     * Complexity O(1)
     * @return Vertex*
     */
    Vertex * getDest() const;
    /**
     * @brief Returns the capacity of the edge
     * Complexity O(1)
     * @return double
     */
    double getWeight() const;
    /**
     * @brief Returns whether edge is selected or not
     * Complexity O(1)
     * @return bool
     */
    bool isSelected() const;
    /**
     * @brief Returns the origin vertex
     * Complexity O(1)
     * @return Vertex*
     */
    Vertex * getOrig() const;
    /**
     * @brief Returns the opposite edge (from dest to origin)
     * Complexity O(1)
     * @return Edge*
     */
    Edge *getReverse() const;
    /**
     * @brief Returns the current flow in the edge
     * Complexity O(1)
     * @return double
     */
    double getFlow() const;
    /**
     * @brief Returns the type of the edge ("STANDARD" or other)
     * Complexity O(1)
     * @return std::string
     */
    std::string getType() const;


    /**
     * @brief Sets whether edge is selected or not
     * Complexity O(1)
     * @param bool
     */
    void setSelected(bool selected);
    /**
     * @brief Sets the opposite edge
     * Complexity O(1)
     * @param Edge*
     */
    void setReverse(Edge *reverse);
    /**
     * @brief Sets the current flow
     * Complexity O(1)
     * @param double
     */
    void setFlow(double flow);

protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity

    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    double flow; // for flow-related problems


    std::string type; // for some reason idk
};

#endif /* DA_TP_CLASSES_VERTEX_EDGE */