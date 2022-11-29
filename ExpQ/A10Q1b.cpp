#include<bits/stdc++.h>
using namespace std;
#define N 8

bool solveNQUtil(vector<vector<int>>& board, int col,vector<int>& leftRow,
vector<int>& LeftDiagonal,vector<int>& RightDiagonal){

	if (col >= N)
		return true;

	for (int i = 0; i < N; i++) {
		if ((LeftDiagonal[i - col + N - 1] != 1 && RightDiagonal[i + col] != 1) && leftRow[i] != 1) {
			board[i][col] = 1;
			LeftDiagonal[i - col + N - 1] = RightDiagonal[i + col] = leftRow[i] = 1;

			if (solveNQUtil(board, col + 1,leftRow,LeftDiagonal,RightDiagonal))
				return true;

			board[i][col] = 0;
			LeftDiagonal[i - col + N - 1] = RightDiagonal[i + col] = leftRow[i] = 0;
		}
	}
	return false;
}

int main(){
    int q=8;
    vector<vector<int>> board={{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 0 }};
                        
    vector<int> leftrow(q,0);
    vector<int> LeftDiagonal(2*q-1,0);
    vector<int> RightDiagonal(2*q-1,0);

	if (solveNQUtil(board, 0,leftrow,LeftDiagonal,RightDiagonal) == false) {
		cout<<"Solution does not exist";
		return false;
	}

    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<" "<< board[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
