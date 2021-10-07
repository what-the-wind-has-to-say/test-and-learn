#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>res;
    bool isValid(vector<string> &board,int row,int col)
    {
        int n = board.size();
        //判断皇后摆放是否合法
        //同一列是否有皇后
        for(int i = 0;i < n;i++)
        {
            if(board[i][col] == 'Q')
            {
                return false;
            }
        }
        //右上是否有皇后
        for(int i = row - 1,j = col + 1;i >= 0 && j < n;i--,j++)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        //左上是否有皇后
        for(int i = row - 1,j = col - 1;i >= 0 && j >= 0;i--,j--)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(vector<string> &board,int row)
    {
        int n = board.size();
        if(row == n)
        {
            res.push_back(board);
            return;
        }
        //DFS
        for(int j = 0;j < n;j++)
        {
            if(isValid(board,row,j))
            {
                board[row][j] = 'Q';
                backtracking(board,row + 1);
                board[row][j] = '.';
            }
        }
        return;
    }
    int main()
    {
        int n = 8;
        res.clear();
        vector<string>board(n,string(n,'.'));
        backtracking(board,0);
        cout << res.size() << endl;
        for(int i = 0;i < res.size();i++)
        {
            for(int j = 0;j < res[0].size();j++)
            {
                for(char c : res[i][j])
                {
                    cout << c << " ";
                }
                cout << endl;
            }
            cout << endl << endl;
        }
    }