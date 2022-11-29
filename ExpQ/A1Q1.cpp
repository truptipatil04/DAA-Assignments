#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=9,m=4;
    int a[n]={9,11,15,24,50},b[m]={2,7,11,23};

    int i=n-m-1,j=m-1,l=n-1;
    
    while(j>=0){
        if(i>=0 && a[i]>b[j]){
            a[l]=a[i];
            i--;
        }else{
            a[l]=b[j];
            j--;
        }
        l--;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;

}