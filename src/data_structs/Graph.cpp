// By: Gonçalo Leão

#include "Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}


Vertex* Graph::findVertex(const std::string name) const{
    if(this->stList.find(name)==this->stList.end()) return nullptr;
    return this->findVertex(this->stList.find(name)->second);
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(Station s) {
    int id = this->vertexSet.size();
    vertexSet.push_back(new Vertex(id, s));
    stList.insert({s.name,id});
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const std::string &sourc, const std::string &dest, double w, std::string type) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w, type);
    return true;
}

bool Graph::addBidirectionalEdge(const std::string &sourc, const std::string &dest, double w, std::string type) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w, type);
    auto e2 = v2->addEdge(v1, w, type);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

bool Graph::addBidirectionalEdge(Station s1, Station s2, double w, std::string type) {
    return this->addBidirectionalEdge(s1.name,s2.name,w, type);
}

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}

void Graph::fordFulkerson(std::string src, std::string dest){
    this->fordFulkerson(this->findVertex(src),this->findVertex(dest));
}

void Graph::fordFulkerson(Vertex* src, Vertex* dest){
    this->removeFlow();

    this->removePaths();
    while(this->dfs(src,dest)) {
        double flow = INF;
        auto cur = dest;
        while(cur!=src){
            flow = std::min(flow,(cur->getPath()->getWeight())-abs(cur->getPath()->getFlow()));
            cur = cur->getPath()->getDest();
        }

        cur = dest;
        while(cur!=src){
            cur->getPath()->setFlow(cur->getPath()->getFlow()-flow);
            cur->getPath()->getReverse()->setFlow(cur->getPath()->getReverse()->getFlow()+flow);
            cur = cur->getPath()->getDest();
        }


        this->removePaths();
    }
}

bool Graph::dfs(std::string src, std::string dest){
    Vertex *start = this->findVertex(src), *goal = this->findVertex(dest);
    return this->dfs(start,goal);
}

bool Graph::dfs(Vertex* src, Vertex* dest) {
    if(src==dest) return true;
    for(auto &i : src->getAdj()){
        if(i->getWeight()>abs(i->getFlow()) && i->getDest()->getPath() == nullptr)
        {
            i->getDest()->setPath(i->getReverse());
            if(this->dfs(i->getDest(),dest)) return true;
        }
    }
    return false;
}

void Graph::removePaths() {
    for(auto &i : this->vertexSet) i->setPath(nullptr);
}

void Graph::removeFlow(){
    for(auto &i : this->vertexSet) for(auto &j : i->getAdj()) j->setFlow(0.0);
}

double Graph::maxInPath(std::string src, std::string dest){
    this->maxInPath(this->findVertex(src),this->findVertex(dest));
}

double Graph::maxInPath(Vertex *src, Vertex *dest) {
    this->fordFulkerson(src,dest);
    double out = 0.0;
    for(auto &i : dest->getIncoming()) if(i->getFlow()>0) out+=i->getFlow();
    return out;
}

std::vector<std::pair<Vertex*,Vertex*>> Graph::maxPairs(){
    double n = 0;
    std::vector<std::pair<Vertex*,Vertex*>> out;

    for(unsigned long int i = 0; i < this->vertexSet.size(); i++) for(int j = i+1; j < this->vertexSet.size(); j++){
        if(i!=j){
            double cur = this->maxInPath(this->vertexSet[i],this->vertexSet[j]);
            if(cur > n){
                n = cur;
                out.clear();
                out.push_back({this->vertexSet[i],this->vertexSet[j]});
            }
            else if(cur == n){
                out.push_back({this->vertexSet[i],this->vertexSet[j]});
            }
        }
    }

    return out;
}