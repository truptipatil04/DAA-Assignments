#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
// 1 6 3 1 3 6 6
    for(int i=0;i<n;i++){
        if(arr[arr[i]%n]>0){
            arr[arr[i]%n]=arr[arr[i]%n]+n;
        }
    }

    bool ans=false;
    for(int i=0;i<n;i++){
        if(arr[i]>=n*2){
            // cout<<i<<" ";
            ans=true;
        }
    }cout<<endl;

    if(ans==true){
        cout<<"Repeated elements present in array"<<endl;
    }else{
        cout<<"Repeated elements not present in array"<<endl;
    }
}