#include<bits/stdc++.h>
using namespace std;

int main(){
    // {profit,weight}
    vector<pair<int,int>> v={{25,18},{24,15},{15,10}};
    int capacity=20;
    float ans=0;

    // Sort the according to decreasing order of profit
    sort(v.begin(),v.end(),greater<>());

    int i=0;
    while(capacity!=0){
        // if capacity of knapsack is more than or equal to current weight then add it in knapsack
        if(capacity>=v[i].second){
            ans+=v[i].first;
            capacity-=v[i].second;
        }else{ //take the fractional part of it
            float x=(float)v[i].first/v[i].second;
            float y=x*capacity;
            ans+=y;
            capacity-=x;
        }
        i++;
    }

    cout<<"The maximum profit is "<<ans<<endl;
}