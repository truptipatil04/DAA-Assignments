#include<bits/stdc++.h>
using namespace std;

bool sorted(pair<int,int>& a,pair<int,int>& b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main(){
    int n;
    cin>>n;
    
    int x,y;
    vector<pair<int,int>>v;

    for(int i=0;i<n;i++){
        cin>>x;
        cin>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),sorted);
    cout<<"Sorted height and weight"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    int start=0,end=0,maxPeople=0,ans=INT_MIN;
    for(int i=1;i<v.size();i++){
        if(v[i].second>v[i-1].second){
            end=i;
        }else{
            maxPeople=max(maxPeople,end-start+1);
            start=i;
            end=i;
        }
    }
    ans=maxPeople;
    cout<<ans<<endl;
}