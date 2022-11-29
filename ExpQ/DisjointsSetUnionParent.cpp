#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
public:
    // constructor 
    // initializes array of rank with 0 and parent with itself
    DisjointSet(int v){
        rank.resize(v+1,0);
        parent.resize(v+1);
        size.resize(v+1);
        for(int i=0;i<=v;i++){
            parent[i]=i;
            size[i]=1;
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

    void findUnionBySize(int u,int v){
        int ultimateP_u=findUparent(u);
        int ultimateP_v=findUparent(v);

        if(ultimateP_u==ultimateP_v){
            return;
        }

        if(size[ultimateP_u] < size[ultimateP_v]){
            parent[ultimateP_u]=ultimateP_v;
            size[ultimateP_v] += size[ultimateP_u];
        }else{
            parent[ultimateP_v]=ultimateP_u;
            size[ultimateP_u] += size[ultimateP_v];
        }
    }
};

int main(){
    DisjointSet ds(7);

    // ds.findUnionByRank(1,2);
    // ds.findUnionByRank(2,3);
    // ds.findUnionByRank(4,5);
    // ds.findUnionByRank(6,7);
    // ds.findUnionByRank(5,6);

    ds.findUnionBySize(1,2);
    ds.findUnionBySize(2,3);
    ds.findUnionBySize(4,5);
    ds.findUnionBySize(6,7);
    ds.findUnionBySize(5,6);

    if(ds.findUparent(3)==ds.findUparent(7)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }

    ds.findUnionBySize(3,7);

    if(ds.findUparent(3)==ds.findUparent(7)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
}