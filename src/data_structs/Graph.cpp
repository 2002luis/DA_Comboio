// By: Gonçalo Leão

#include "Graph.h"
#include <queue>
#include <unordered_map>

Graph::Graph(){

}

Graph::Graph(Graph* copy){
    for(auto v : copy->vertexSet){
        this->addVertex(v->s);
    }
    for(auto v: copy->vertexSet) for(auto e: v->getAdj()){
        this->addBidirectionalEdge(e->getOrig()->s.name,e->getDest()->s.name,e->getWeight(),e->getType());
    }
}

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
    if(this->topDist.find(s.district)==this->topDist.end()) topDist.insert({s.district,0});
    if(this->topMun.find(s.municipality)==this->topMun.end()) topMun.insert({s.municipality,0});
    if(this->topDistOnlySame.find(s.district)==this->topDistOnlySame.end()) topDistOnlySame.insert({s.district,0});
    if(this->topMunOnlySame.find(s.municipality)==this->topMunOnlySame.end()) topMunOnlySame.insert({s.municipality,0});
    this->stList.insert({s.name,id});
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
    topDist.find(v1->s.district)->second+=w;
    topMun.find(v1->s.municipality)->second+=w;
    if(v1->s.district == v2->s.district) topDistOnlySame.find(v1->s.district)->second+=w;
    if(v1->s.municipality == v2->s.municipality) topMunOnlySame.find(v1->s.municipality)->second+=w;
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

void Graph::fordFulkerson(std::string src, std::string dest, bool clear = true){
    this->fordFulkerson(this->findVertex(src),this->findVertex(dest),clear);
}

void Graph::fordFulkerson(Vertex* src, Vertex* dest, bool clear = true){
    if(clear) this->removeFlow();
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

void Graph::removeVisited(){
    for(auto &i : this->vertexSet) i->setVisited(false);
}

double Graph::maxInPath(std::string src, std::string dest, bool clear = true){
    return this->maxInPath(this->findVertex(src),this->findVertex(dest), clear);
}

double Graph::maxInPath(Vertex *src, Vertex *dest, bool clear = true) {
    this->fordFulkerson(src,dest,clear);
    double out = 0.0;
    for(auto &i : dest->getIncoming()) if(i->getFlow()>0) out+=i->getFlow();
    return out;
}


bool sortBy2nd(std::pair<std::string,double> p1, std::pair<std::string,double> p2){
    return p1.second>p2.second; //biggest goes first
}

bool sortEdgesBy2nd(std::pair<Edge*,int> p1, std::pair<Edge*,int> p2){
    return p1.second > p2.second;
}

void Graph::sortTopList() {
    topDistSorted.clear();
    topDistOnlySameSorted.clear();
    topMunSorted.clear();
    topMunOnlySameSorted.clear();
    for (auto p: topDist) topDistSorted.push_back(p);
    for (auto p: topMun) topMunSorted.push_back(p);
    for (auto p: topDistOnlySame) topDistOnlySameSorted.push_back(p);
    for (auto p: topMunOnlySameSorted) topMunOnlySameSorted.push_back(p);

    std::sort(topDistSorted.begin(), topDistSorted.end(), sortBy2nd);
    std::sort(topMunSorted.begin(), topMunSorted.end(), sortBy2nd);
    std::sort(topDistOnlySameSorted.begin(), topDistOnlySameSorted.end(), sortBy2nd);
    std::sort(topMunOnlySameSorted.begin(), topMunOnlySameSorted.end(), sortBy2nd);

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

void Graph::removeEdge(std::string a, std::string b) {
    this->removeEdge(this->findVertex(a),this->findVertex(b));
}

void Graph::removeEdge(Vertex *a, Vertex *b) {
    a->removeEdge(b->getId());
    b->removeEdge(a->getId());
}

void Graph::removeEdge(Edge *e) {
    this->removeEdge(e->getOrig(),e->getDest());
}

void Graph::removeVertex(Vertex *a) {
    for(auto e : a->getAdj()) this->removeEdge(e);
    for(unsigned long int i = 0; i < this->vertexSet.size(); i++){
        if(this->vertexSet[i] == a){
            this->vertexSet.erase(this->vertexSet.begin()+i,this->vertexSet.begin()+i+1);
            i = this->vertexSet.size();
        }
    }
}

void Graph::removeVertex(std::string n) {
    this->removeVertex(this->findVertex(n));
}

void Graph::removeVertex(int n) {
    this->removeVertex(this->findVertex(n));
}

std::vector<std::pair<Edge*,int>> Graph::getDiffs(Graph* g, int n){
    std::vector<std::pair<Edge*,int>> tmp;

    for(auto i : g->vertexSet){
        auto j = this->findVertex(i->s.name);
        if(j!= nullptr){
            for(auto e : i->getAdj()){
                for(auto e2: j->getAdj()){
                    if(e->getDest() == e2->getDest()){
                        tmp.push_back({e,std::abs(e->getFlow()-e2->getFlow())});
                    }
                }
            }
        }
    }

    std::sort(tmp.begin(),tmp.end(),sortEdgesBy2nd);

    std::vector<std::pair<Edge*,int>> out;

    for(int i = 0; i < n; i ++){
        if(i > tmp.size()) return out;

        out.push_back(tmp[i]);
    }

    return out;
}

std::pair<int,int> Graph::costOptimization(std::string src, std::string dest){
    return this->costOptimization(this->findVertex(src),this->findVertex(dest));
}

std::pair<int,int> Graph::costOptimization(Vertex* src, Vertex* dest){
    this->removeFlow();
    this->removePaths();
    std::pair<int,int> out = {0,0};

    dest->setPath(dest->getAdj()[0]);

    while(dest->getPath() != nullptr){
        int curCap = djikstra(src,dest);
        auto i = dest;
        while(i->getPath() != nullptr){
            i->getPath()->setFlow(i->getPath()->getFlow()+1);
            i = i->getPath()->getOrig();
        }
        out.first++;
        out.second+=curCap;
    }
    return out;
}


class Compare{
public:
    bool operator()(std::pair<Vertex*,int> p1, std::pair<Vertex*,int> p2){
        return p2.second < p1.second;
    }
};

int Graph::djikstra(Vertex *src, Vertex *dest) {
    this->removePaths();
    std::priority_queue<std::pair<Vertex*,int>,std::vector<std::pair<Vertex*,int>>,Compare> q;
    q.push({src,0});
    while(!q.empty()){
        auto cur = q.top().first;
        auto curName = cur->s.name;
        auto curC = q.top().second;
        if(cur == dest) return curC;
        q.pop();
        for(auto e : cur->getAdj()){
            if(e->getFlow()<e->getWeight() && e->getDest()->getPath()== nullptr && e->getDest() != src){
                e->getDest()->setPath(e);
                int newC = curC;
                if(e->getType() == "STANDARD") newC+=2;
                else newC+=4;
                q.push({e->getDest(),newC});
            }
        }
    }
    return -1;
}