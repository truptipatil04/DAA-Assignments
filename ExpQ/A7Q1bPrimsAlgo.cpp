#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

class Graph{
public:
    int v;
    list< pair<int, int> > *adj;

    Graph(int v){
        this->v=v;
        // array of type list<pair<int,int>> of size v
        adj=new list<pair<int,int>> [v];
    }

    void addEdge(int u,int v,int w){
        // in adjency list {node,weight}
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void PrimsMST(){
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int src=0;

        vector<int> key(v,INF); //stores the weight of edge at particular index
        vector<int> parent(v,-1); //stores the parent node of particular node determined by index
        vector<int> visit(v,0); //stores info or node is visited or not

        // {weight,node} in priority queue
        pq.push({0,src});
        key[src]=0;
        

        while(!pq.empty()){
            int tempnode=pq.top().second;
            pq.pop();

            if(visit[tempnode]==1){
                continue;
            }

            visit[tempnode]=1;

            list<pair<int,int>> ::iterator itr;
            // traverse in adjency list
            for(itr=adj[tempnode].begin();itr!=adj[tempnode].end();itr++){
                // get the {node,weight} of adjacent node of present node tempnode
                int node=(*itr).first; //node
                int weight=(*itr).second; //weight

                if(visit[node]==0 && key[node]>weight){
                    key[node]=weight;
                    pq.push({key[node],node});
                    parent[node]=tempnode;
                }
            }
        }

        // Edges present in MST
        cout<<"The edges present in MST : "<<endl;
        for(int i=1;i<v;i++){
            cout<<"{ "<<parent[i]<<", "<<i<<" }"<<endl;
        }

        // cost of MST
        int cost=0;
        for(int i=0;i<v;i++){
            cost+=key[i];
        }
        cout<<"Cost of MST : "<<cost<<endl;
    }
};

int main(){
    int v=10;
    Graph g(v);

    g.addEdge(0, 1, 15);
    g.addEdge(0, 8, 19);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 8, 7);
    g.addEdge(1, 3, 17);
    g.addEdge(2, 8, 16);
    g.addEdge(2, 4, 14);
    g.addEdge(3, 1, 17);
    g.addEdge(3, 8, 12);
    g.addEdge(3, 9, 20);
    g.addEdge(3, 5, 13);
    g.addEdge(4, 2, 14);
    g.addEdge(4, 8, 6);
    g.addEdge(4, 9, 9);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 3, 13);
    g.addEdge(5, 9, 4);
    g.addEdge(5, 7, 2);
    g.addEdge(7, 6, 18);
    g.addEdge(6, 9, 1);
    g.addEdge(7, 9, 11);
    g.addEdge(9, 8, 3);

 
    g.PrimsMST();

    return 0;
}