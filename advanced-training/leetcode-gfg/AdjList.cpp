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

        while(!Q.empty()){
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
    
    
    void DFSTravesal(){
        stack<int> st;
        vector<bool> visited(sz,false);
        
        st.push(0);
        visited[0] = true;
        
        while(!st.empty()){
            int u = st.top();
            st.pop();
            
            cout<<u<<" ";
            for(int nbr :  adj[u]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    st.push(nbr);
                }
            }
        }
        cout<<endl;
    }
    
    void dfsHelper(int u,vector<bool> &visited){
        cout<<u<<" ";
        visited[u] =true;
        
        for(int nbr : adj[u]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
    }
    
    void dfsRecursive(){
        int src = 0;
        vector<bool> visited(sz,false);
        dfsHelper(src,visited);
    }

};
int main() {
    Graph g(7);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    
    g.BFSTraversal();
    // g.DFSTravesal();
    g.dfsRecursive();

}
