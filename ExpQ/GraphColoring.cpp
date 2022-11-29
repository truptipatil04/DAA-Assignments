#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> adj[],vector<int>& color,int v,int c,int node){
    // check the adjacent nodes
    for(int it: adj[node]){
        // if color of adjacent node is same as that of curr node
        if(color[it]==c){
            return false;
        }
    }
    return true;
}

bool graphColor(vector<int> adj[],vector<int>& color,int v,int m,int node){
    // if all nodes are colored than return true
    if(node==v){
        return true;
    }

    // iterate for all colors
    for(int i=1;i<=m;i++){
        // if node can be colored with the ith color
        if(isSafe(adj,color,v,i,node)){
            // than color it
            color[node]=i;

            // go for next node coloring
            if(graphColor(adj,color,v,m,node+1)){
                // if coloring of next node is possible
                return true;
            }
            // else backtrack
            color[node]=0;
        }
    }

    // if coloring of graph with m colors is not possible
    return false;
}

int main(){
    int v=4;
    // vector<int> adj[v]={{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<int> adj[v]={{1,3},{0,2},{1,3},{0,2}};
    int m=2; //number of colors

    // to store the color of node
    vector<int> color(v,0);

    bool flag=graphColor(adj,color,v,m,0);

    if(flag){
        cout<<"The graph with "<<v<<" vertices can be colored with "
        <<m<<" colors"<<endl;
    }else{
        cout<<"The graph with "<<v<<" vertices cannot be colored with "
        <<m<<" colors"<<endl;
    }
}