#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph() {

    }
    void addEdge(T u,T v,bool bidir = true){
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);   
    }
    void print(){
        // Iterate over the map;
        for(auto i: adjList){
            cout << i.first << "->";
            for(auto entry: i.second){
                cout << entry <<",";
            }
            cout << endl;
        }
    }
};
int main() {
    Graph<string> g;
    g.addEdge("Putin","Modi",false);
    g.addEdge("Putin","Trump",false);
    g.addEdge("Putin","Pope",false);
    g.addEdge("Modi","Trump",true);
    g.addEdge("Modi","Yogi",true);
    g.addEdge("Yogi","Prabhu",true);

    g.print();

    return 0;
}
