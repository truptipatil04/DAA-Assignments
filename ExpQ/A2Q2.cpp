#include<bits/stdc++.h>
using namespace std;
//0 0 1 2 4 4 3 3 3 3 0 1 1
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    int maxVotes=INT_MIN,winner=INT_MIN;
    for(auto it: m){
        if(it.second > maxVotes){
            maxVotes=it.second;
            winner=it.first;
        }
    }

    cout<<"Winner of election : "<<winner<<endl;
    cout<<"Maximum votes : "<<maxVotes<<endl;
}