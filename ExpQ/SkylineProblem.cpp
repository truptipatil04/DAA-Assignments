#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings){
    priority_queue<pair<int,int>> pq;
    vector<vector<int>> edges;

    for(int i=0;i<buildings.size();i++){
        int x=edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][0]);
        edges[x].push_back(buildings[i][1]);
    }

    for(int i=0;i<buildings.size();i++){
        int x=edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][2]);
        edges[x].push_back(-buildings[i][1]);
    }

    sort(edges.begin(),edges.end());

    int j=0,prevHeight=0;

    vector<vector<int>> skyline;

    while(j<buildings.size() && buildings[j][0]<=edge[i])
}

int main(){
    //{start, end, height}
    // vector<vector<int>> buildings={{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> buildings={{1,5,11},{2,7,6},{3,9,13},{12,16,7},{14,25,3},{19,22,18},
    {23,29,13},{24,28,4}};

    vector<vector<int>> ans=getSkyline(buildings);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}