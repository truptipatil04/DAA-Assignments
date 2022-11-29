#include<bits/stdc++.h>
using namespace std;

bool sorted(pair<int,int>& a,pair<int,int>& b){
    float d1=(float)a.first/a.second;
    float d2=(float)b.first/b.second;

    if(d1 > d2){
        return true;
    }
    return false;
}

int main(){
    // {profit,weight}
    vector<pair<int,int>> v={{25,18},{24,15},{15,10}};
    int capacity=20;
    float ans=0;

    // Sort according to decreasing order of profit/weight ratio 
    sort(v.begin(),v.end(),sorted);

    int i=0;
    while(capacity!=0){
        // if capacity of knapsack is more than or equal to current weight then add it in knapsack
        if(capacity>=v[i].second){
            ans+=v[i].first;
            capacity-=v[i].second;
        }else{ //take fractional part of it
            int c=capacity;
            float x=(float)capacity/v[i].second;
            float y=x*v[i].first;

            ans+=y;
            capacity-=c;
        }
        i++;
    }

    cout<<"The maximum profit is "<<ans<<endl;
}