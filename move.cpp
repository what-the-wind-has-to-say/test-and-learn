#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> up(vector<vector<int>> vec,int x,int y)
    {
        int tmp = vec[x][y];
        vec[x][y] = vec[x - 1][y];
        vec[x - 1][y] = tmp;
        return vec;
    }
    vector<vector<int>> down(vector<vector<int>> vec,int x,int y)
    {
        int tmp = vec[x][y];
        vec[x][y] = vec[x + 1][y];
        vec[x + 1][y] = tmp;
        return vec;
    }
    vector<vector<int>> left(vector<vector<int>> vec,int x,int y)
    {
        int tmp = vec[x][y];
        vec[x][y] = vec[x][y - 1];
        vec[x][y - 1] = tmp;
        return vec;
    }
    vector<vector<int>> right(vector<vector<int>> vec,int x,int y)
    {
        int tmp = vec[x][y];
        vec[x][y] = vec[x][y + 1];
        vec[x][y + 1] = tmp;
        return vec;
    }
    pair<int,int> find_zero(vector<vector<int>> &vec)
    {
        for(int i = 0;i < vec.size();i++)
        {
            for(int j = 0;j < vec[0].size();j++)
            {
                if(vec[i][j] == 0)
                {
                    pair<int,int> res = {i,j};
                    return res;
                }
            }
        }
        return {-1,-1};
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>>q;
        int step = 0;
        vector<vector<int>>target(2,vector<int>(3));
        target[0] = {1,2,3};
        target[1] = {4,5,0};
        q.push(board);
        set<vector<vector<int>>>myset;//避免回头
        myset.insert(board);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0;i < sz;i++)
            {
                auto cur = q.front();
                q.pop();
                if(cur == target)
                {
                    return step;
                }
                pair<int,int>zero = find_zero(cur);
                //向上交换
                if(zero.first > 0)
                {
                    vector<vector<int>>tmp1 = up(cur,zero.first,zero.second);
                    if(myset.find(tmp1) == myset.end())
                    {
                        myset.insert(tmp1);
                        q.push(tmp1);
                    }
                }
                //向下交换
                if(zero.first < 1)
                {
                    vector<vector<int>>tmp2 = down(cur,zero.first,zero.second);
                    if(myset.find(tmp2) == myset.end())
                    {
                        myset.insert(tmp2);
                        q.push(tmp2);
                    }
                }
                //向左交换
                if(zero.second > 0)
                {
                    vector<vector<int>>tmp3 = left(cur,zero.first,zero.second);
                    if(myset.find(tmp3) == myset.end())
                    {
                        myset.insert(tmp3);
                        q.push(tmp3);
                    }
                }
                //向右交换
                if(zero.second < 2)
                {
                    vector<vector<int>>tmp4 = right(cur,zero.first,zero.second);
                    if(myset.find(tmp4) == myset.end())
                    {
                        myset.insert(tmp4);
                        q.push(tmp4);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    int main()
    {
        vector<vector<int>>board(2,vector<int>(3));
        board[0] = {1,2,3};
        board[1] = {4,0,5};
        int res = slidingPuzzle(board);
        cout << res << endl;
    }