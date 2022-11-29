// Hamiltanion Cycle
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,vector<vector<bool>>& graph,vector<int>& path,int pos){
    // check if vertex is adjacent of previously added vertex
    if(graph[path[pos-1]][x]==0){
        return false;
    }

    // check if vertex is already added
    for(int i=0;i<pos;i++){
        if(path[i]==x){
            return false;
        }
    }
    return true;    
}

bool hamCycle(vector<vector<bool>>& graph,vector<int>& path,int pos){
    int v=graph[0].size();
    // base case
    if(pos==v){
        // check if there is edge between last vertex and first vertex
        if(graph[path[pos-1]][path[0]]==1){
            return true;
        }else{
            return false;
        }
    }

    for(int i=1;i<v;i++){
        if(isSafe(i,graph,path,pos)){
            path[pos]=i;

            // recursive call
            if(hamCycle(graph,path,pos+1)==true){
                return true;
            }

            // if adding vertex i does not given any solution then remove it
            path[pos]=-1;
        }
    }
    // if no vertex can be added to cycle constructed till now
    return false;
}

void HamiltonianCycle(vector<vector<bool>>& graph){
    int v=graph[0].size();
    vector<int> path(v,-1);

    path[0]=0;
    if(hamCycle(graph,path,1)==false){
        cout<<"Solution does not exist"<<endl;
        return;
    }
    
    cout<<"Hamiltonian Cycle : "<<endl;
    for(int i=0;i<v;i++){
        cout<<path[i]<<" ";
    }cout<<path[0]<<endl;
}

int main(){
    int v=5;
    vector<vector<bool>> graph={{0, 1, 0, 1, 0},
                {1, 0, 1, 1, 1},
                {0, 1, 0, 0, 1},
                {1, 1, 0, 0, 1},
                {0, 1, 1, 1, 0}};
    
    HamiltonianCycle(graph);
}