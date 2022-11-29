#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<pair<string,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({arr[i],i});
    }

    for(int i=0;i<v.size();i++){
        sort(v[i].first.begin(),v[i].first.end());
    }

    sort(v.begin(),v.end());
    
    string ans[n];
    for(int i=0;i<n;i++){
        ans[i]=arr[v[i].second];
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}