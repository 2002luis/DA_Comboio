// By: Gonçalo Leão

#include "VertexEdge.h"

/************************* Vertex  **************************/

Vertex::Vertex(int id, Station s){
    this->id=id;
    this->s=s;
}

std::string Edge::getType() const{
    return this->type;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
Edge * Vertex::addEdge(Vertex *d, double w, std::string type) {
    auto newEdge = new Edge(this, d, w, type);
    adj.push_back(newEdge);
    d->incoming.push_back(newEdge);
    return newEdge;
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
bool Vertex::removeEdge(int destID) {
    Edge *edgToRemove;
    int toRemove = 0;
    for(unsigned long int i = 0; i < this->getAdj().size(); i++){
        Edge *edge = this->getAdj()[i];
        Vertex *dest = edge->getDest();
        if (dest->getId() == destID) {
            toRemove = i;
            edgToRemove = edge;
        }
    }
    delete edgToRemove;
    adj.erase(adj.begin()+toRemove,adj.begin()+toRemove+1);
    return true;
}

bool Vertex::operator<(Vertex & vertex) const {
    return this->dist < vertex.dist;
}

int Vertex::getId() const {
    return this->id;
}

std::vector<Edge*> Vertex::getAdj(){
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}

bool Vertex::isProcesssing() const {
    return this->processing;
}

unsigned int Vertex::getIndegree() const {
    return this->indegree;
}

double Vertex::getDist() const {
    return this->dist;
}

Edge *Vertex::getPath() const {
    return this->path;
}

std::vector<Edge *> Vertex::getIncoming() const {
    return this->incoming;
}

void Vertex::setId(int id) {
    this->id = id;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

void Vertex::setProcesssing(bool processing) {
    this->processing = processing;
}

void Vertex::setIndegree(unsigned int indegree) {
    this->indegree = indegree;
}

void Vertex::setDist(double dist) {
    this->dist = dist;
}

void Vertex::setPath(Edge *path) {
    this->path = path;
}

/********************** Edge  ****************************/

Edge::Edge(Vertex *orig, Vertex *dest, double w, std::string t): orig(orig), dest(dest), weight(w) , type(t){}

Vertex * Edge::getDest() const {
    return this->dest;
}

double Edge::getWeight() const {
    return this->weight;
}

Vertex * Edge::getOrig() const {
    return this->orig;
}

Edge *Edge::getReverse() const {
    return this->reverse;
}

bool Edge::isSelected() const {
    return this->selected;
}

double Edge::getFlow() const {
    return flow;
}

void Edge::setSelected(bool selected) {
    this->selected = selected;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}

void Edge::setFlow(double flow) {
    this->flow = flow;
}