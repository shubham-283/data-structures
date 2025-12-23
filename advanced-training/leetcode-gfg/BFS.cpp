#include<bits/stdc++.h>

using namespace std;

class Graph{
    vector<vector<int>> adj;
    int sz;
public:
    Graph(int sz) : sz(sz),adj(sz){}


    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printAdj(){
        for(int i=0;i<sz;i++){
            cout<<i<<": ";
            for(int l : adj[i]){
                cout<<l<<" ";
            }
            cout<<endl;
        }
    }

    void BFSTraversal(){
        queue<int> Q;
        vector<bool> visited(sz,false);
        Q.push(0);
        visited[0]= true;

        while(Q.size()>0){
            int u = Q.front();
            Q.pop();

            cout<<u<<" ";

            for(int nbr : adj[u]){
                if(!visited[nbr]){

                    visited[nbr] =true;
                    Q.push(nbr);
                }
            }
            
        }
        cout<<endl;

    }

};
int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.BFSTraversal();
}
