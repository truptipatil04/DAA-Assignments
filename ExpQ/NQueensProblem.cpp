#include<bits/stdc++.h>
using namespace std;

void solve(int col,vector<string>& board,vector<vector<string>>& ans,
vector<int>& leftRow,vector<int>& UpperDiagonal,vector<int>& LowerDiagonal,
int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && LowerDiagonal[row+col]==0 
        && UpperDiagonal[n-1+col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            LowerDiagonal[row+col]=1;
            UpperDiagonal[n-1+col-row]=1;
            solve(col+1,board,ans,leftRow,LowerDiagonal,UpperDiagonal,n);
            board[row][col]='*';
            leftRow[row]=0;
            LowerDiagonal[row+col]=0;
            UpperDiagonal[n-1+col-row]=0;
        }
    }
    
}

int main(){
    int q;
    cin>>q;

    vector<vector<string>> ans;
    vector<string> board(q);
    string s(q,'*');

    for(int i=0;i<q;i++){
        board[i]=s;
    }

    vector<int> leftRow(q,0);
    vector<int> UpperDiagonal(2*q-1,0);
    vector<int> LowerDiagonal(2*q-1,0);

    solve(0,board,ans,leftRow,UpperDiagonal,LowerDiagonal,q);

    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}