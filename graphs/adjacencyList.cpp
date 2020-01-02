#include<iostream>
#include<list>
using namespace std;
class Graph {
    int V;
    list<int> * l;
public:
    Graph(int v){
        V = v;
        // Array of Linked list
        l = new list<int>[V];
    }
    void addEdge(int u,int v,bool bidir = true){
        l[u].push_back(v);
        if(bidir)
            l[v].push_back(u);
    }
    void printAdjList(){
        for(int i=0;i<V;i++){
            cout << i << "-> "; 
            // l[i] is a linked list...
            for(int vertex: l[i])
                cout << vertex << ",";
            cout << endl;
        }
    }

};
int main() {
    // Graph has 5 vertices from 0-5..
    // 0 -> 1,4
    // 1 -> 2,3,4,0
    // 2 -> 1,3
    // 3 -> 2,1,0
    // 4 -> 1,0,3 
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3); 
    g.addEdge(1,3); 


    g.printAdjList();

    return 0;
}