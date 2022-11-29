#include<bits/stdc++.h>
using namespace std;

int main(){
    // {weight,profit}
    vector<pair<int,int>> v={{18,25},{15,24},{10,15}};
    int capacity=20;
    float ans=0;

    // Sort according to increasing of weight
    sort(v.begin(),v.end());

    int i=0;
    while(capacity!=0){ 
        // if capacity of knapsack is more than or equal to current weight then add it in knapsack
        if(capacity>=v[i].first){
            ans+=v[i].second;
            capacity-=v[i].first;
            // cout<<ans<<" "<<capacity<<endl;
        }else{ // take the fractional part of it
            int c=capacity;
            float x=(float)capacity/v[i].first;
            float y=x*v[i].second;

            ans+=y;
            capacity-=c;
        }
        i++;
    }

    cout<<"The maximum profit is "<<ans<<endl;
}