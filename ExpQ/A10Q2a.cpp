#include<bits/stdc++.h>
using namespace std;

bool BipartiteBFS(int v,vector<int> adj[]){
    // to store the color of node
    // 0-one color, 1-another color
    vector<int> color(v,-1);

    // {vertex,color}
    queue<pair<int,int>> q;

    // check for every vertex which is not visited 
    // works for both connected and disconnected graph
    for(int i=0;i<v;i++){

        // vertex not colored
        if(color[i]==-1){
            q.push({i,0});
            color[i]=0;


            while(!q.empty()){
                pair<int,int> p=q.front();
                q.pop();

                // vertex
                int n=p.first;
                // colore of vertex
                int c=p.second;

                // iterate for adjacent vertices of current vertex
                for(int it: adj[n]){
                    // if color of adjacent node is same as of current node
                    if(color[it]==c){
                        return false;
                    }// if adjacent node is not colored
                    else if(color[it]==-1){
                    // color adjacent node with color opposite to current node
                        color[it]=(c) ? 0 : 1;
                        q.push({it,color[it]});
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    int v=4,e=8;
    vector<int> adj[v]={{1,3},{0,2},{1,3},{0,2}};
    // vector<int> adj[v]={{0,1},{1,2},{2,3},{3,4},{4,0}};

    bool ans=BipartiteBFS(v,adj);

    if(ans){
        cout<<"The Graph is a Bipartite graph"<<endl;
    }else{
        cout<<"The Graph is not a Bipartite graph"<<endl;
    }

}