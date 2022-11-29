#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> a={{2, 2, 3, 1},{1, 4, 1, 2},{2, 3, 1, 1}, {1, 3, 1, 2}};
    vector<vector<int>> b={{2, 1, 2, 1},{3, 1, 2, 1},{3, 2, 1, 1}, {1, 4, 3, 2}};
    int n=a.size();

    vector<vector<int>> c(n, vector<int>(n));;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j]=0;
            for(int k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" \t";
        }cout<<endl;
    }
}