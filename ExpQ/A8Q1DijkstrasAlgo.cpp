#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

void addEdge(vector<pair<int,int>> adj[],int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void ShortestPath(vector<pair<int,int>> adj[],int v,int src){
    // create min heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

    // at first the distance of every node from source is infinite
    vector<int> distance(v,INF);

    // push the src
    pq.push({0,src});
    distance[src]=0;

    while(!pq.empty()){
        int tempnode=pq.top().second;
        pq.pop();

        // traverse the adjacent nodes of tempnode
        for(auto it:adj[tempnode]){
            int node=it.first;
            int weight=it.second;

            // if there is shortest path to node via tempnode 
            // then update the distance
            if(distance[node] > distance[tempnode]+weight){
                distance[node]=distance[tempnode]+weight;
                pq.push({distance[node],node});
            }
        }
    }

    cout<<"Distance of every vertex from source "<<endl;
    cout<<"Vertex"<<"   "<<"Distance"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<"           "<<distance[i]<<endl;
    }
}

int main(){
    int v=6;
    vector<pair<int,int>> adj[v];

    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 2);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 3);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 2, 3, 1);
    addEdge(adj, 2, 4, 2);
    addEdge(adj, 3, 4, 4);
    addEdge(adj, 3, 5, 3);
    addEdge(adj, 4, 5, 3);

    // addEdge(adj, 0, 1, 5);
    // addEdge(adj, 0, 2, 2);
    // addEdge(adj, 1, 2, -10);

    ShortestPath(adj, v, 0);

    return 0;
}