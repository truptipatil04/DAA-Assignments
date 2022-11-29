#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
	int largest=i;
	int l=2*i;
	int r=2*i+1;
	
	if(l<n && arr[l]>arr[largest])
	   largest=l;
	if(r<n && arr[r]>arr[largest])
	   largest=r;
	
	if(largest!=i){
		swap(arr[i],arr[largest]);
		
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	
	for(int i=n-1;i>0;i--){
		swap(arr[0],arr[i]);
	
	    heapify(arr,i,0);
    }
}

int binarySearch(int arr[],int n,int key){
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)/2;

        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
}

int main(){
    int n=5;
    int a[5]={2,1,4,6,3};
    int b[5]={3,1,5,2,6};

    int x=4;

    heapSort(a,n);
    heapSort(b,n);

    int index=-1;
    for(int i=0;i<n;i++){
        index=binarySearch(b,n,abs(a[i]-x));
        if(index!=-1){
            break;
        }
    }

    if(index!=-1){
        cout<<"Pair a,b such that a+b=k is present."<<endl;
    }else{
        cout<<"Pair a,b such that a+b=k is not present."<<endl;
    }

}