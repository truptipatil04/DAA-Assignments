#include<bits/stdc++.h>
using namespace std;

int maxElement(int arr[],int n,int l,int r){
    while(l<=r){
        int mid=l+(r-l)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }else if(arr[mid]<arr[mid+1]){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return arr[r];
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int l=0,r=n-1;
    int ans=maxElement(arr,n,l,r);
    cout<<"Max Element in first decreasing and then decreasing array : "<<ans<<endl;
}