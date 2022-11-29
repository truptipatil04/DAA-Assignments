#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    where 'N' denotes the number of buildings present in the given problem.
*/
vector<vector<int>> getSkyline(vector<vector<int>>& buildings){
    
    /*
        [start, -height, validUntil]
        height > 0: start edge
        height == 0: end edge
    */

    vector<vector<int>> edges;
    for(int i = 0; i < buildings.size(); i++){
        int x = edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][0]);
        edges[x].push_back(-buildings[i][2]);
        edges[x].push_back(buildings[i][1]);
    }
    // cout<<edges.size()<<endl;

    for(int i = 0; i < buildings.size(); i++){
        int x = edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][1]);
        edges[x].push_back(0);
        edges[x].push_back(1e9);
    }
    // cout<<edges.size()<<endl;

    sort(edges.begin(), edges.end());


    // for(int i=0;i<edges.size();i++){
    //     cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl;
    // }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> prevHighest;

    prevHighest.push({0, 1e9});

    vector<vector<int>> skyline;

    for(int i = 0; i < edges.size(); i++){
        
        int position = edges[i][0];
        int curHeight = -1*edges[i][1];
        int validUntil = edges[i][2];

        while(prevHighest.top().second <= position){
            /*
                The equal term guarantees that, for end edges, popping 
                from height to low still works.
            */
            prevHighest.pop();
        }
        
        if(curHeight > 0){
            // Start edge.
            prevHighest.push({-curHeight, validUntil});
        }
        
        // prevHighest is now the current highest.

        if(skyline.size() == 0){
            skyline.push_back(vector<int>());
            skyline[0].push_back(position);
            skyline[0].push_back(-prevHighest.top().first);
        }
        else if(skyline.back()[1] != -prevHighest.top().first){
            // cout<<skyline.back()[1]<<endl;
            int x = skyline.size();
            skyline.push_back(vector<int>());
            skyline[x].push_back(position);
            skyline[x].push_back(-prevHighest.top().first);   
        }
    }

    return skyline;
}

  
int main()
{
    vector<vector<int>> buildings={{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> ans=getSkyline(buildings);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    cout<<"Hello World";

    return 0;
}