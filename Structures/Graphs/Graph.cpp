#include "..\include\Graph.h"

template<typename T>
bool Vertex<T>::operator==(Vertex<T> const& target){
    return data==target.getData();
}

template<typename T>
void Vertex<T>::setData(T const& newData){
    data=newData;
}

template<typename T>
T Vertex<T>::getData()const{
    return data;
}

template<typename T>
LinkedList<Vertex<T>*>* Vertex<T>::getAdjacent(){
    return &adjacent;
}

template<typename T>
Vertex<T>* Vertex<T>::getAdjacentVertex(T const& target){
    adjacent.iterStart();
    Node<Vertex<T>*>* p=adjacent.iterate();
    while(p){
        if(p->data->getData()==target)break;
        p=p->next;
    }
    if(p)return p->data;
    else return NULL;
}

template<typename T>
void Vertex<T>::addEdgeTo(Vertex<T>* const newVertex){
    if(!getAdjacentVertex(newVertex->getData())){
        adjacent.pushToEnd(newVertex);
    }
}

template<typename T>
void Vertex<T>::removeEdgeTo(Vertex<T>* const target){
    if(target && getAdjacentVertex(target->getData())){
        adjacent.iterStart();
        Node<Vertex<T>*>* p=adjacent.iterate();
        while(p){
            if(p->data==target){
                Vertex<T>* probe;
                adjacent.deleteTarget(p,probe);
                //target->removeEdgeTo(this);
            }
            p=p->next;
        }
    }
}

template<typename T>
void Vertex<T>::print(){
    adjacent.iterStart();
    Node<Vertex<T>*>* p=adjacent.iterate();
    std::cout<<"Vertex "<<data<<" is adjacent to:\n";
    while(p){
        cout<<p->data->getData()<<" ";
        p=p->next;
    }
    cout<<endl;
}

template<typename T>
int Vertex<T>::connectivity(){
    return adjacent.length();
}

template<typename T>
void Graph<T>::addVertex(T const& newData){
    if(!getVertex(newData)){
        Vertex<T> newV;
        newV.setData(newData);
        vertexes.pushToEnd(newV);
    }
}

template<typename T>
void Graph<T>::addEdge(T const& first,T const& second){
    Vertex<T>* firstVertex = getVertex(first);
    if(!firstVertex){
        addVertex(first);
        firstVertex = getVertex(first);
    }

    Vertex<T>* secondVertex = getVertex(second);
    if(!secondVertex){
        addVertex(second);
        secondVertex = getVertex(second);
    }

    firstVertex->addEdgeTo(secondVertex);
    secondVertex->addEdgeTo(firstVertex);
}

template<typename T>
Vertex<T>* Graph<T>::getVertex(T const& target){
    vertexes.iterStart();
    Node<Vertex<T> >* p=vertexes.iterate();
    while(p){
        if(p->data.getData()==target)break;
        p=p->next;
    }
    return &p->data;
}


template<typename T>
LinkedList<T>* Graph<T>::getVertexes(){
    return &vertexes;
}


template<typename T>
void Graph<T>::removeVertex(T const& target){
    Vertex<T>* toRemove=getVertex(target);
    if(toRemove){
        LinkedList<Vertex<T>*>* adjacentToTarget=toRemove->getAdjacent();
        adjacentToTarget->iterStart();
        Node<Vertex<T>*>* adjacentIterator=adjacentToTarget->iterate();
        while(adjacentIterator){
            removeEdge(toRemove->getData(),adjacentIterator->data->getData());
            adjacentIterator=adjacentIterator->next;
        }

        vertexes.iterStart();
        Node<Vertex<T> >* q = vertexes.iterate();
        while(q){
            if(q->data.getData()==target){
                Vertex<T> probe;
                vertexes.deleteTarget(q,probe);
                break;
            }
            q=q->next;
        }
    }
}

template<typename T>
void Graph<T>::removeEdge(T const& first,T const& second){
    Vertex<T>* firstVertex = getVertex(first);
    Vertex<T>* secondVertex = getVertex(second);
    if(firstVertex && secondVertex){
        firstVertex->removeEdgeTo(secondVertex);
        secondVertex->removeEdgeTo(firstVertex);
    }
}

template<typename T>
void Graph<T>::connectionDFS(Vertex<T>* current,LinkedList<Vertex<T>*> &visited){
    visited.pushToEnd(current);//mark as visited

    current->getAdjacent()->iterStart();
    Node<Vertex<T>*>* p=current->getAdjacent()->iterate();
    while(p){
        if(!visited.hasElement(p->data)){
            connectionDFS(p->data,visited);
        }
        p=p->next;
    }
}

template<typename T>
bool Graph<T>::connected(){
    LinkedList<Vertex<T>*> visited;
    vertexes.iterStart();
    Vertex<T>* start=&vertexes.iterate()->data;
    connectionDFS(start,visited);

    if(visited.length()==vertexes.length())return true;
    return false;
}

template<typename T>
void Graph<T>::cycleDFS(Vertex<T>* current,Vertex<T>* parent,LinkedList<Vertex<T>*> &visited,bool &res){
    visited.pushToEnd(current);//mark as visited

    current->getAdjacent()->iterStart();
    Node<Vertex<T>*>* p=current->getAdjacent()->iterate();
    while(p && !res){
        if(p->data==parent){
            p=p->next;
            if(!p)break;
        }

        if(visited.hasElement(p->data)){
            res=true;
        }
        else cycleDFS(p->data,current,visited,res);
        p=p->next;
    }
}

template<typename T>
bool Graph<T>::cyclic(){
    LinkedList<Vertex<T>*> visited;
    vertexes.iterStart();
    Vertex<T>* start=&vertexes.iterate()->data;
    bool res=false;
    cycleDFS(start,start,visited,res);
    return res;
}

template<typename T>
void Graph<T>::findPath(Vertex<T>* current,Vertex<T>* to,LinkedList<Vertex<T>*> visited,LinkedList<Vertex<T>*> &path,bool &found){
    visited.pushToEnd(current);//mark as visited
    if(current==to){
        found=true;
        path=visited;
    }

    current->getAdjacent()->iterStart();
    Node<Vertex<T>*>* p=current->getAdjacent()->iterate();
    while(p && !found){
        if(!visited.hasElement(p->data)){
            connectionDFS(p->data,visited);
        }
        p=p->next;
    }
}

template<typename T>
LinkedList<Vertex<T>*> Graph<T>::getPath(T const& from,T const& to){
    Vertex<T>* fromV = getVertex(from);
    Vertex<T>* toV = getVertex(to);
    LinkedList<Vertex<T>*> visited;
    LinkedList<Vertex<T>*> path;
    bool found=false;
    findPath(fromV,toV,visited,path,found);
    return path;
}

template<typename T>
void Graph<T>::print(){
    int v=vertexCount();
    int e=edgeCount();
    cout<<"This graph has ";
    if(v==0)cout<<"no vertexes ";
    else if(v==1)cout<<v<<" vertex ";
    else cout<<v<<" vertexes ";
    cout<<"and ";
    if(e==0)cout<<"no edges.";
    else if(e==1)cout<<e<<" edge.";
    else cout<<e<<" edges.\n";
    cout<<"They are arranged as follows:\n";

    vertexes.iterStart();
    Node<Vertex<T> >* p=vertexes.iterate();
    while(p){
        p->data.print();
        p=p->next;
    }
}

template<typename T>
int Graph<T>::vertexCount(){
    return vertexes.length();
}

template<typename T>
int Graph<T>::edgeCount(){
    int sum=0;
    vertexes.iterStart();
    Node<Vertex<T> >* p=vertexes.iterate();
    while(p){
        sum+=p->data.connectivity();
        p=p->next;
    }
    return sum/2;
}
