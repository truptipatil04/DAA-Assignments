#include<bits/stdc++.h>
using namespace std;

// Complexity O(n^2)

bool isSafe(int row,int col,vector<string> board,int n){
    int duprow=row;
    int dupcol=col;

    while(row>=0 && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }

    row=duprow;
    col=dupcol;

    while(col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        col--;
    }

    row=duprow;
    col=dupcol;
    while(col>=0 && row<n){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
    }

    return true;
}

void solve(int col,vector<string> &board,vector<vector<string>> &ans,int q){
    if(col==q){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<q;row++){
        if(isSafe(row,col,board,q)){
            board[row][col]='Q';
            solve(col+1,board,ans,q);
            board[row][col]='*';
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

    solve(0,board,ans,q);

    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            cout<<ans[i][j]<<endl;
        }cout<<endl;
    }cout<<endl;
}