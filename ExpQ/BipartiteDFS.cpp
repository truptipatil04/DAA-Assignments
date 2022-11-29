#include<bits/stdc++.h>
using namespace std;

void APUtil(vector<int> adj[], int u, bool visited[],int disc[], 
            int low[], int& time, int parent, bool isAP[]){
    // Count of children in DFS Tree
    int children = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices adjacent to this
    for (auto it : adj[u]) {
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[it]) {
            children++;
            APUtil(adj, it, visited, disc, low, time, u, isAP);
 
            // Check if the subtree rooted with v has
            // a connection to one of the ancestors of u
            low[u] = min(low[u], low[it]);
 
            // If u is not root and low value of one of
            // its child is more than discovery value of u.
            if (parent != -1 && low[it] >= disc[u])
                isAP[u] = true;
        }
 
        // Update low value of u for parent function calls.
        else if (it != parent)
            low[u] = min(low[u], disc[it]);
    }
 
    // If u is root of DFS tree and has two or more children.
    if (parent == -1 && children > 1)
        isAP[u] = true;
}

void AP(vector<int> adj[], int v){
    int disc[v] = {0};
    int low[v];
    bool visited[v] = { false };
    bool isAP[v] = { false };
    int time = 0, par = -1;
 
    // Adding this loop so that the
    // code works even if we are given
    // disconnected graph
    for (int u = 0; u < v; u++)
        if (!visited[u])
            APUtil(adj, u, visited, disc, low,
                   time, par, isAP);
 
    // Printing the APs
    for (int u = 0; u < v; u++)
        if (isAP[u] == true)
            cout << u << " ";
}


bool BipartiteDFS(int node,vector<int> adj[],vector<int>& color){

    // iterate over adjacent nodes of particular node
    for(auto it: adj[node]){
        // if node is not colored
        if(color[it]==-1){
            // color it with opposite color of current node
            color[it]=1-color[node];

            // recursive call
            if(!BipartiteDFS(it,adj,color)){
                return false;
            }
        } // if color of adjacent node is same as that of curr node
        else if(color[it]==color[node]){
            return false;
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[],int v){
    // to store color of nodes
    vector<int> color(v,-1);

    // iterate over all vertices
    for(int i=0;i<v;i++){
        // if node not colored
        if(color[i]==-1){
            //color it with color1
            color[i]=1;
            // call the function which is recursive
            if(!BipartiteDFS(i,adj,color)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int v=4;
    // vector<int> adj[v]={{1,3},{0,2},{1,3},{0,2}};
    // vector<int> adj[v]={{0,1},{1,2},{2,3},{3,4},{4,0}};
    vector<int> adj[v]={{0,1},{0,2},{2,1},{0,3},{3,4}};
    AP(adj,v);
    cout<<endl;
    bool flag=checkBipartite(adj,v);

    if(flag){
        cout<<"The Graph is a Bipartite graph"<<endl;
    }else{
        cout<<"The Graph is not a Bipartite graph"<<endl;
    }


}