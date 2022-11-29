#include<bits/stdc++.h>
using namespace std;

int power(int p){
    int l=1;
    for(int i=0;i<=p;i++){
        l*=2;
    }
    return l;
}

void StrassensMatrix(int* A,int* B,int* C,int m,int n){
    if(m==2){
        int P=(*A+*(A+n+1))*(*B+*(B+n+1));
        int Q=(*(A+n)+*(A+n+1))*(*B);
        int R=(*A)*(*(B+1)-*(B+n+1));
        int S=(*(A+n+1))*(*(B+n)-*B);
        int T=(*A+*(A+1))*(*(B+n+1));
        int U=(*(A+n)-*A)*(*(B+n+1));
        int V=(*(A+1)-*(A+n+1))*(*(B+n)+*(B+n+1));

        *C=*C+P+S-T+V;
        *(C+1)=*(C+1)+R+T;
        *(C+n)=*(C+n)+Q+S;
        *(C+n+1)=*(C+n+1)+P+R-Q+U;
    }else{
        m/=2;
        StrassensMatrix(A,B,C,m,n);
        StrassensMatrix(A,B+m,C+m,m,n);
        StrassensMatrix(A+m,B+m*n,C,m,n);
        StrassensMatrix(A+m,B+m*(n+1),C+m,m,n);
        StrassensMatrix(A+m*n,B,C+m*n,m,n);
        StrassensMatrix(A+m*n,B+m,C+m*(n+1),m,n);
        StrassensMatrix(A+m*(n+1),B+m*n,C+m*n,m,n);
        StrassensMatrix(A+m*(n+1),B+m*(n+1),C+m*(n+1),m,n);
    }
}

int main(){
    int n,n1,n2,n3;
    cout<<"Enter size of row of 1st matrix : ";
    cin>>n1;

    cout<<"Enter size of column of 1st matrix and size of row of 2nd matrix : ";
    cin>>n2;

    cout<<"Enter size of column of 2nd matrix : ";
    cin>>n3;

    int a[n1][n2];
    int b[n2][n3];

    // vector<vector<int>> a(n1,vector<int> (n2));
    // vector<vector<int>> b(n2,vector<int> (n3));

    cout<<"Enter elements of 1st matrix : "<<endl;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin>>a[i][j];
        }
    }

    cout<<"Enter elements of 1st matrix : "<<endl;
    for(int i=0;i<n2;i++){
        for(int j=0;j<n3;j++){
            cin>>b[i][j];
        }
    }

    // creating a matrix of order 2^n
    if(n1>=n2 && n1>=n3){
        n=n1;
    }else if(n2>=n1 && n2>=n3){
        n=n2;
    }else{
        n=n3;
    }

    int o=1;
    while(n>power(o)){
        o+=1;
    }

    int m=power(o);
    int A[m][m],B[m][m],C[m][m];
    // vector<vector<int>> A(m,vector<int> (m));
    // vector<vector<int>> B(m,vector<int> (m));
    // vector<vector<int>> C(m,vector<int> (m));

    for(int i=0;i<m;i++){
        for(int j=0;j<m;i++){
            A[i][j]=0;
            B[i][j]=0;
            C[i][j]=0;
        }
    }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;i++){
            A[i][j]=a[i][j];
        }
    }

    for(int i=0;i<n2;i++){
        for(int j=0;j<n3;i++){
            B[i][j]=b[i][j];
        }
    }

    StrassensMatrix(A,B,C,m,m);
}