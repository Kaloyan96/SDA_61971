#ifndef GRAPH_H
#define GRAPH_H
#include "..\src\LinkedList.cpp"
#include<fstream>

using namespace std;

template<typename T>
class Vertex{
private:
    T data;
    LinkedList<Vertex<T>*> adjacent;
public:
    Vertex(){};
    ~Vertex(){};
    bool operator==(Vertex<T> const&);

    void setData(T const&);
    T getData()const;
    LinkedList<Vertex<T>*>* getAdjacent();
    Vertex<T>* getAdjacentVertex(T const&);
    void addEdgeTo(Vertex<T>* const);
    void removeEdgeTo(Vertex<T>* const);
    void print();
};

template<typename T>
class Graph{
private:
    LinkedList<Vertex<T> > vertexes;
public:
    Graph(){};
    ~Graph(){};

    void addVertex(T const&);
    void addEdge(T const&,T const&);
    Vertex<T>* getVertex(T const&);
    LinkedList<T>* getVertexes();
    void removeVertex(T const&);
    void removeEdge(T const&,T const&);

    void connectionDFS(Vertex<T>*,LinkedList<Vertex<T>*>&);
    bool connected();
    void cycleDFS(Vertex<T>*,Vertex<T>*,LinkedList<Vertex<T>*>&,bool &);
    bool cyclic();

    void print();
};

#endif // GRAPH_H
