#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;

    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int key;
    cin>>key;

    int i=0,j=m-1;
    if(key<arr[0][0] || key>arr[n-1][m-1]){
        return -1;
    }

    bool ans=false;
    while(i<n && j>=0){
        if(arr[i][j]==key){
            ans=true;
            cout<<key<<" found at index : ("<<i<<", "<<j<<")"<<endl;
            break;
        }else if(arr[i][j]>key){
            j--;
        }else{
            i++;
        }
    }

    if(ans==false){
        cout<<key<<" not found "<<endl;
    }
}