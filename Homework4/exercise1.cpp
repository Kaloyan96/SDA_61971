#include "src\Graph.cpp"

using namespace std;

void constructFromFile(string const& , Graph<int> &);
void ex1_task2();//C:\\Users\\grade\\Desktop\\input.txt

int main(){
    ex1_task2();
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

    Graph<int> g;
    constructFromFile(fileName,g);
    //constructFromFile("C:\\Users\\grade\\Desktop\\input.txt",g);
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
