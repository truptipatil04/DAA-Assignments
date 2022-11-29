#include<bits/stdc++.h>
using namespace std;

void BellmanFord(vector<vector<int>>& edges,int n,int src){
    // vector to store the distance for node from src
    vector<int> distance(n,1e8);

    // initially src distance is 0
    distance[src]=0;

    // iterate for n-1 times through all edges
    for(int i=0;i<n-1;i++){
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            // if u is reached and distancce[u]+w if less than distance[v]
            // then update distance[v]
            if(distance[u]!=1e8 && distance[u]+w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }

    bool flag=false;
    // Check for negative cycle 
    // Nth relaxation
    for(auto it: edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];

        if(distance[u]!=1e8 && distance[u]+w < distance[v]){
            flag=true;
        }
    }

    if(flag==true){
        cout<<"Negative cycle present"<<endl;
    }else{
        cout<<"Vertex   Distance from Source\n"<<endl;
        for (int i = 0; i < n; ++i)
            cout<<i<<"           "<< distance[i]<<endl;
    }
}

int main(){
    // n- no. of vertices
    // m- no. of edges
    int n=5,m=8;
    // cin>>n>>m;

    vector<vector<int>> edges={
        {0,1,6},{0,2,7},{1,3,5},{1,4,-4},{1,2,8},{2,3,-3},{2,4,9},{3,1,-2},
        {4,3,7},{4,0,2}
    };

    // for(int i=0;i<m;i++){
    //     vector<int> temp;
    //     for(int j=0;j<3;j++){
    //         int x;
    //         cin>>x;
    //         temp.push_back(x);
    //     }
    //     edges.push_back(temp);
    // }

    int src=0;
    // cin>>src;

    BellmanFord(edges,n,src);
}