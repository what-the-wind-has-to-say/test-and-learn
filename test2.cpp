#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>path;

bool backtracking(vector<vector<int>> &p,int ceng,int N,set<int> &myset)
{
    if(ceng == N)
    {
        return true;
    }
    for(int i = 0;i < p[ceng].size();i++)
    {
        if(myset.find(p[ceng][i]) == myset.end())
        {
            path.push_back(p[ceng][i]);
            myset.insert(p[ceng][i]);
            if(backtracking(p,ceng + 1,N,myset))
            {
                return true;
            }
            path.pop_back();
            myset.erase(p[ceng][i]);
        }
    }
    return false;
}
void print_path()
{
    for(int i = 0;i < path.size();i++)
    {
        if(i == path.size() - 1)
        {
            cout << path[i];
        }
        else
        {
            cout << path[i] << " ";
        }
    }
}
int main() {
    ifstream in("A.txt");
    int count;
    in >> count;
    while(count--)
    {
        path.clear();
        set<int>myset;
        int N;//看病天数
        in >> N;
        vector<vector<int>>p;
        int n = N;
        while(n--)
        {
            int s;
            int e;
            in >> s >> e;
            int len = e - s + 1;
            vector<int>tmp(len);
            for(int j = 0;j < len;j++)
            {
                tmp[j] = s + j;
            }
            p.push_back(tmp);
        }
        if(backtracking(p,0,N,myset))
        {
            print_path();
        }
        else
        {
            cout << "impossible";
        }
        cout << endl;
    }
    return 0;
}