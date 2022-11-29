#include<bits/stdc++.h>
using namespace std;

struct job{
    char jobId;
    int deadline;
    int profit;
};

bool compare(job a,job b){
    return (a.profit > b.profit);
}

int main(){
    job jobs[] = {{'a',2,100},{'b',1,19},{'c',2,27},{'d',1,25},{'e',3,15}};
    int n=sizeof(jobs)/sizeof(jobs[0]);

    // sort according to increasing order of 
    sort(jobs,jobs+n,compare);

    int result[n]={0};
    bool slot[n]={false};

    for(int i=0;i<n;i++){
        for(int j=min(jobs[i].deadline,n)-1;j>=0;j--){
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }

    cout<<"The jobs that can be performed within deadline to maximize the profit :"<<endl;
    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<jobs[result[i]].jobId<< " ";}
    }

}