#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool backTracking(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(i,j,k,board)){
                            board[i][j]=k;
                            bool result=backTracking(board);
                            if(result==true)return true;
                            board[i][j]='.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row,int cal, char k,vector<vector<char>>& board){
        //判断行
        for(int i=0;i<9;i++){
            if(board[row][i]==k){
                return false;
            }
        }
        //判断列
        for(int j=0;j<9;j++){
            if(board[j][cal]==k){
                return false;
            }
        }
        //判断九宫格
        int startRow = (row / 3) * 3;
        int startCol = (cal / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == k ) {
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backTracking(board);
    }
};