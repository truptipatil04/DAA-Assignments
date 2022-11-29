#include<bits/stdc++.h>
using namespace std;

int Search(string arr[],int n,int l,int r,string str){
    if(l>r){
        return -1;
    }

    int mid=l+(r-l)/2;

    if(arr[mid]==""){
        int l1=mid-1,r1=mid+1;

        while(l1>=l && r1<=r){
            if(l1<l && r1>r){
                return -1;
            }

            if(r1<=r && arr[r1]!=""){
                mid=r1;
                break;
            }

            if(l1>=l && arr[l1]!=""){
                mid=l1;
                break;
            }
            l1--;
            r1++;
        }
    }

    if(str.compare(arr[mid])==0){
        return mid;
    }else if(str.compare(arr[mid])<0){
        return Search(arr,n,l,mid-1,str);
    }
    return Search(arr,n,mid+1,r,str);
}

int main(){
    int n=12;
    string arr[n]={"at","","","ball","","","car","","","dad","",""};

    string str;
    cout<<"Enter string to be found : ";
    cin>>str;

    int l=0,r=n-1;
    int index=Search(arr,n,l,r,str);
    cout<<str<<" found at index : "<<index+1<<endl;
}