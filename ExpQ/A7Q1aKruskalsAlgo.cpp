#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
public:
    // constructor 
    // initializes array of rank with 0 and parent with itself
    DisjointSet(int v){
        rank.resize(v+1,0);
        parent.resize(v+1);
        for(int i=0;i<=v;i++){
            parent[i]=i;
        }
    }

    // function to find the ultimate parent of node takes constant time
    int findUparent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUparent(parent[node]);
    }

    // Function to find Union 
    void findUnionByRank(int u,int v){
        // find the ultimate parents of nodes
        int ultimateP_u=findUparent(u);
        int ultimateP_v=findUparent(v);

        // if same parents than return
        if(ultimateP_u==ultimateP_v){
            return;
        }

        // To connect the nodes check the rank
        // node with smaller rank is connected to node with larger rank
        // if ranks are same then connect any one 
        if(rank[ultimateP_u] < rank[ultimateP_v]){
            parent[ultimateP_u]=ultimateP_v;
        }else if(rank[ultimateP_u] > rank[ultimateP_v]){
            parent[ultimateP_v]=ultimateP_u;
        }else{
            parent[ultimateP_u]=ultimateP_v;
            rank[ultimateP_v]++;
        }
    }
};

class Graph{
    vector<vector<int>> edges;
    int V;
public:

    Graph(int V){
        this->V=V;
    }

    void addEdge(int u,int v,int w){
        edges.push_back({w,u,v});
    }

    void KruskalsMST(){
        // Sort the edges
        sort(edges.begin(),edges.end());

        DisjointSet ds(V);
        int cost=0;

        cout<<"The edges present in MST are: "<<endl;

        for(auto it: edges){
            int weight=it[0];
            int node1=it[1];
            int node2=it[2];

            // if Ultimate parents are not same means the nodes are not in 
            // same component and edge between them do not form cycle
            // include these nodes in MST
            if(ds.findUparent(node1)!=ds.findUparent(node2)){
                ds.findUnionByRank(node1,node2);
                cost+=weight;

                cout<<"{ "<<node1<<", "<<node2<<", "<<weight<<" }"<<endl;
            }
        }

        cout<<"Cost of MST : "<<cost<<endl;
    }
};

int main(){
    Graph g(10);

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

    g.KruskalsMST();
}