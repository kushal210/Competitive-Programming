#include<iostream>
#include<map>
#include<list>
#include<queue>
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
    
    ////////////////////////////
    //////// D F S  ///////////
    //////////////////////////
    // TIME COMPLEXITY IS O(V+E) USING ADJACENCY LIST AND O(V^2) USING ADJ.MATRIX....
    // THIS IS BECAUSE IN THE WORST CASE FULL ADJACENCY LIST IS TRAVERSED....
    
    // SPACE COMPLEXITY O(V)....
    void dfsHelper(T node,map<T,bool> &visited){
        // Whenever come to a node mark it visited...
        visited[node] = true;
        cout << node << " ";
        for(auto neighbour: adjList[node]){
            if(!visited[neighbour])
                dfsHelper(neighbour,visited);
        }
    }

    void connected_component(){
        map<T,bool> visited;
        int component = 0;
        for(auto i: adjList){
            T city = i.first;
            if(!visited[city]){
                dfsHelper(city,visited);
                component++;
                cout << endl;
            }
        }
        cout << "The connected graph has " << component << " components"<< endl;
        //dfsHelper(src,visited);
    }
    
    
};
int main() {
    
    Graph<string> g;
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Delhi","Jaipur");
    g.addEdge("Mumbai","Jaipur");
    g.addEdge("Delhi","Bhopal");
    g.addEdge("Bangalore","Mumbai");
    g.addEdge("Agra","Delhi");
    g.addEdge("Nicobar","Andaman");
    g.addEdge("Singapore","Malayasia");

    g.connected_component();
    
    return 0;
}
