#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings){
    vector<vector<int>> edges;

    //push start_point, height as negative ,end_point
    for(int i=0;i<buildings.size();i++){
        int x=edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][0]);
        edges[x].push_back(-buildings[i][2]);
        edges[x].push_back(buildings[i][1]);
    }
    
    //push end_points and their ending will be 0 and no height so 1e9
    for(int i=0;i<buildings.size();i++){
        int x=edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][1]);
        edges[x].push_back(0);
        edges[x].push_back(1e9);
    }

    // sort so that start point and end point are arranged correctly
    sort(edges.begin(),edges.end());

    //min heap of pair of integers
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> prevHighest;
    
    prevHighest.push({0,1e9});
    
    vector<vector<int>> skyline;

    for(int i=0;i<edges.size();i++){
        int start=edges[i][0];
        int currHeight=-1*edges[i][1];
        int end=edges[i][2];

        // if end point of prev building is less than start point of next 
        // building, then it will not be present in ans
        while(prevHighest.top().second<=start){
            prevHighest.pop();
        }

        // if it is not end point then push it in min heap
        if(currHeight>0){
            prevHighest.push({-currHeight,end});
        }

        if(skyline.size()==0){
            skyline.push_back(vector<int>());
            skyline[0].push_back(start);
            skyline[0].push_back(-prevHighest.top().first);
        }else if(skyline.back()[1] != -prevHighest.top().first){
            int x=skyline.size();
            skyline.push_back(vector<int>());
            skyline[x].push_back(start);
            skyline[x].push_back(-prevHighest.top().first);
        }
    }
    return skyline;
}

int main(){
    //{start, end, height}
    vector<vector<int>> buildings={{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    // vector<vector<int>> buildings={{1,5,11},{2,7,6},{3,9,13},{12,16,7},{14,25,3},{19,22,18},
    // {23,29,13},{24,28,4}};

    vector<vector<int>> ans=getSkyline(buildings);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}