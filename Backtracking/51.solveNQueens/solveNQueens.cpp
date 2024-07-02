#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    void backtracking (int n, int row, vector<string>& chessboard) {
        if(row==n){
            result.push_back(chessboard);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(row,i,chessboard,n)){
                chessboard[row][i]='Q';
                backtracking(n,row+1,chessboard);
                chessboard[row][i]='.';
            }
        }
    }

    bool isValid(int row, int col, vector<string>& chessboard, int n) {
        // 检查列
        for (int i = 0; i < row; i++) { // 这是一个剪枝
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};

int main(){
    Solution a;
    vector<vector<string>> ans=a.solveNQueens(4);
    for(auto row:ans){
        for(auto num:row){
            cout<<num<<endl;
        }
        cout<<'fucking cut line'<<endl;
    }
    return 0;
}