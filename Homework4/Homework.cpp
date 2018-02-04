#include "src\Graph.cpp"

using namespace std;

void constructFromFile(string const& , Graph<int> &);

void ex1_task2();//Monk at the Graph Factory

void ex1_task3();//Monk in the real estate

void ex2_task2();//Rhezo and HackerEarth
void getConnection(string const&,int&,int&,int&);

void ex2_task3();//Oliver and the Game
void printPath(LinkedList<Vertex<int>*>&);

int main(){
    //ex1_task2();
    //ex1_task3();
    //ex2_task2();
    //ex2_task3();
    return 0;
}

void constructFromFile(string const& fileName, Graph<int> &g){
    ifstream file;
    file.open(fileName.c_str(),ios::in);
    if(!file){
		std::cout<<"Error in opening file!!!\n";
		return ;
	}

    int n1,n2;
	while (1){
		file >> n1 >> n2;
		g.addEdge(n1,n2);
		//if a vertex does not exist getEdge adds it automatically
		if( file.eof() ){
            break;
		}
	}
	file.close();
}

void getConnection(string const& fileName,int& lineNumber,int& n1,int& n2){
    ifstream file;
    file.open(fileName.c_str(),ios::in);
    if(!file){
		std::cout<<"Error in opening file!!!\n";
		return ;
	}

    for(int i=1;i<=lineNumber;i++){
		file >> n1 >> n2;
		if( file.eof() ){
            break;
		}
	}
	file.close();
}

void ex1_task2(){
    string fileName;
    cout<<"Input file path, with doubled \\ symbol:\n";
    cin>>fileName;
    //fileName="C:\\Users\\grade\\Desktop\\input.txt";

    Graph<int> g;
    constructFromFile(fileName,g);
    g.print();
    cout<<endl;

    //The functions cyclic and connected are implemented with a variant of DFS in the class Graph.
    bool connected = g.connected();
    bool cyclic = g.cyclic();

    cout<<"The Graph is ";
    if(!connected)cout<<"not ";
    cout<<"connected ";

    if(connected!=cyclic)cout<<"but ";
    else cout<<"and ";

    if(!cyclic)cout<<"is not ";
    cout<<"cyclic so it is ";

    if(!(connected && !cyclic))cout<<"not ";
    cout<<"a tree.\n";
}

void ex1_task3(){//print already does what is requested
    string fileName;
    cout<<"Input file path, with doubled \\ symbol:\n";
    cin>>fileName;
    //fileName="C:\\Users\\grade\\Desktop\\input.txt";

    Graph<int> g;
    constructFromFile(fileName,g);
    g.print();
    cout<<endl;
}

void ex2_task2(){
    string fileName;
    cout<<"Input file path, with doubled \\ symbol:\n";
    cin>>fileName;
    //fileName="C:\\Users\\grade\\Desktop\\input2.txt";

    Graph<int> g;
    constructFromFile(fileName,g);
    g.print();
    cout<<endl;

    int numberOfDisruptions,connection;
    int n1,n2;
    cin>>numberOfDisruptions;

    for(int i=0;i<numberOfDisruptions;i++){
        cin>>connection;
        getConnection(fileName,connection,n1,n2);
        g.removeEdge(n1,n2);
        if(g.connected())cout<<"Happy\n";
        else cout<<"Unhappy\n";
        g.addEdge(n1,n2);
    }
}

const int MANSION_ADDR=1;
void ex2_task3(){
    string fileName;
    cout<<"Input file path, with doubled \\ symbol:\n";
    cin>>fileName;
    //fileName="C:\\Users\\grade\\Desktop\\input3.txt";

    Graph<int> g;
    constructFromFile(fileName,g);
    g.print();
    cout<<endl;


    int numOfGames;
    cout<<"Number of games: ";
    cin>>numOfGames;

    int type,target,start;
    cout<<"Game input format: 0/1 X Y\n";
    cout<<"0 - moves towards Mansion.\n1 - moves away from Mansion.\n";
    cout<<"X - target.\n";
    cout<<"Y - start.\n";
    for(int i=0;i<numOfGames;i++){
        cin>>type>>target>>start;
        if(type==0){
            Vertex<int>* targetV=g.getVertex(target);
            LinkedList<Vertex<int>*> path=g.getPath(MANSION_ADDR,start);
            if(path.hasElement(targetV))cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            Vertex<int>* Mansion=g.getVertex(MANSION_ADDR);
            LinkedList<Vertex<int>*> pathBetween=g.getPath(start,target);
            bool differentBranches=pathBetween.hasElement(Mansion)&&start!=MANSION_ADDR;
            if(differentBranches)cout<<"NO\n";
            else{
                Vertex<int>* targetV=g.getVertex(target);
                LinkedList<Vertex<int>*> path=g.getPath(MANSION_ADDR,start);
                if(!path.hasElement(targetV))cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }

    //LinkedList<Vertex<int>*> path=g.getPath(1,4);
    //printPath(path);
}

void printPath(LinkedList<Vertex<int>*> &path){
    cout<<"This path is:\n";
    path.iterStart();
    Node<Vertex<int>*>* p=path.iterate();
    while(p){
        cout<<p->data->getData()<<" ";
        p=p->next;
    }
    cout<<endl;
}
