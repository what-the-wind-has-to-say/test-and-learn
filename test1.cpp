#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//计算两个相同矩阵的最大重合数目
    int f(int x, int y, vector<vector<int>> &A, vector<vector<int>> &B){
        int m = A.size();
        int n = A[0].size();
        // A.右下角位于pos(x,y)
        int ansA = 0;
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                ansA += A[m-x-1+i][n-y-1+j]*B[i][j];
            }
        }
        // B.右下角位于pos(x,y)
        int ansB = 0;
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                ansB += A[i][j]*B[m-x-1+i][n-y-1+j];
            }
        }
        return max(ansA, ansB);
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int m = A.size(); if(m==0) return 0;
        int n = A[0].size(); if(n==0) return 0;
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, f(i, j, A, B));
            }
        }
        return ans;
    }



//包裹情况下计算
int package(vector<vector<int>> &v1,vector<vector<int>> &v2)
{
    int x1 = v1.size();
    int y1 = v1[0].size();
    int x2 = v2.size();
    int y2 = v2[0].size();
    int m1 = x1 - x2;//向下移动匹配次数
    int m2 = y1 - y2;//向右移动匹配次数
    int res = 0;
    for(int i = 0;i <= m1;i++)
    {
        for(int j = 0;j <= m2;j++)
        {
            vector<vector<int>>tmp(x2,vector<int>(y2,0));
            for(int k = 0;k < x2;k++)
            {
                for(int l = 0;l < y2;l++)
                {
                    tmp[k][l] = v1[i + k][j + l];
                }
            }
            int r = largestOverlap(tmp,v2);
            if(r > res)
            {
                res = r;
            }
        }
    }
    return res;
}
int cross(vector<vector<int>> &v1,vector<vector<int>> &v2)
{
    int x1 = v1.size();
    int y1 = v1[0].size();
    int x2 = v2.size();
    int y2 = v2[0].size();
    int cross_x = min(x1,x2);
    int cross_y = min(y1,y2);
    int m1 = x2 - cross_x;
    int m2 = y2 - cross_y;
    int res = 0;
    for(int i = 0;i <= m1;i++)
    {
        for(int j = 0;j <= m2;j++)
        {
            vector<vector<int>>tmp(cross_x,vector<int>(cross_y,0));//交叠的矩阵
            for(int k = 0;k < cross_x;k++)
            {
                for(int l = 0;l < cross_y;l++)
                {
                    tmp[k][l] = v2[i + k][j + l];
                }
            }
            int r = package(v1,tmp);
            if(r > res)
            {
                res = r;
            }
        }
    }
    return res;
}
int match(vector<vector<int>> &v1,vector<vector<int>> &v2)
{
    int x1 = v1.size();
    int y1 = v1[0].size();
    int x2 = v2.size();
    int y2 = v2[0].size();
    if(x1 <= x2 && y1 <= y2)
    {
        //2包裹1
        return package(v2,v1);
    }
    else if(x1 >= x2 && y1 >= y2)
    {
        //1包裹2
        return package(v1,v2);
    }
    else
    {
        //交叉情况
        return cross(v1,v2);
    }
}
//原地旋转矩阵90°
void rotate(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < (n + 1) / 2; ++j) 
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}
int horizontal(vector<vector<int>>& matrix)
{
    //水平翻转,返回1代表相同，即对称
    int flag = 1;
    int x = matrix.size();
    int y = matrix[0].size();
    vector<vector<int>>tmp(x,vector<int>(y,0));
    for(int i = 0;i < y/2;i++)
    {
        for(int j = 0;j < x;j++)
        {
            tmp[j][y - 1 - i] = matrix[j][i];
        }
    }
    for(int i = 0;i < x;i++)
    {
        for(int j = 0;j < y;j++)
        {
            if(tmp[i][j] != matrix[i][j])
            {
                flag = 0;
                matrix[i][j] = tmp[i][j];
            }
        }
    }
    return flag;
}
int vertical(vector<vector<int>>& matrix)
{
    //垂直翻转,返回1代表相同，即对称
    int flag = 1;
    int x = matrix.size();
    int y = matrix[0].size();
    vector<vector<int>>tmp(x,vector<int>(y,0));
    for(int i = 0;i < x/2;i++)
    {
        for(int j = 0;j < y;j++)
        {
            tmp[x - 1 - i][j] = matrix[i][j];
        }
    }
    for(int i = 0;i < x;i++)
    {
        for(int j = 0;j < y;j++)
        {
            if(tmp[i][j] != matrix[i][j])
            {
                flag = 0;
                matrix[i][j] = tmp[i][j];
            }
        }
    }
    return flag;
}
int rotate_match(vector<vector<int>> &v1,vector<vector<int>> &v2)
{
    int res = 0;
    int r = match(v1,v2);
    if(r > res)
    {
        res = r;
    }
    int num = 3;
    while(num--)
    {
        rotate(v1);
        int r1 = match(v1,v2);
        if(r1 > res)
        {
            res = r1;
        }
    }
    //转回去
    rotate(v1);
    return res;
}
int rotate2 (vector<vector<int>> &v1,vector<vector<int>> &v2)
{
    int x1 = v1.size();
    int y1 = v1[0].size();
    int x2 = y1;
    int y2 = x1;
    int res = match(v1,v2);
    //90°
    vector<vector<int>> r_90(x2,vector<int>(y2,0));
    for(int i = 0;i < x2;i++)
    {
        for(int j = 0;j < y2;j++)
        {
            r_90[i][j] = v1[x1 - 1 - j][i];
        }
    }
    int r1 = match(r_90,v2);
    if(r1 > res)
    {
        res = r1;
    }
    //180°
    vector<vector<int>> r_180(x1,vector<int>(y1,0));
    for(int i = 0;i < x1;i++)
    {
        for(int j = 0;j < y1;j++)
        {
            r_180[i][j] = v1[x1 - 1 - i][y1 - 1 - j];
        }
    }
    int r2 = match(r_180,v2);
    if(r2 > res)
    {
        res = r2;
    }
    //270°
    vector<vector<int>> r_270(x2,vector<int>(y2,0));
    for(int i = 0;i < x2;i++)
    {
        for(int j = 0;j < y2;j++)
        {
            r_270[i][j] = r_180[x1 - 1 - j][i];
        }
    }  
    int r3 = match(r_270,v2);
    if(r3 > res)
    {
        res = r3;
    }
    return res;
}
int main() {
    ifstream in("A.txt");
    vector<vector<int>>matrix1;
    vector<vector<int>>matrix2;
    int x;
    int y;
    int res_count;
    in >> res_count;
    while(res_count--)
    {
        in >> x >> y;
        vector<vector<int>>tmp(x,vector<int>(y,0));
        for(int i = 0;i < x;i++)
        {
            string str;
            in >> str;
            for(int j = 0;j < y;j++)
            {
                if(str[j] == '#')
                {
                    tmp[i][j] = 1;
                }
            }
        }
        matrix1 = tmp;
        in >> x >> y;
        vector<vector<int>>tmp2(x,vector<int>(y,0));
        for(int i = 0;i < x;i++)
        {
            string str2;
            in >> str2;
            for(int j = 0;j < y;j++)
            {
                if(str2[j] == '#')
                {
                    tmp2[i][j] = 1;
                }
            }
        }
        matrix2 = tmp2;
            int res = 0;
            int x1 = matrix1.size();
            int y1 = matrix1[0].size();
            if(x1 != y1)
            {
                res = rotate2(matrix1,matrix2);
            /* if(horizontal(matrix1) != 1)
            {
                //水平不对称
                int r1 = rotate2(matrix1,matrix2);
                if(r1 > res)
                {
                    res = r1;
                }
                horizontal(matrix1);//翻转回去
            }
            if(vertical(matrix1) != 1)
            {
                //垂直不对称
                int r2 = rotate2(matrix1,matrix2);
                if(r2 > res)
                {
                    res = r2;
                } 
                vertical(matrix1);//翻转回去
            }
            horizontal(matrix1);
            vertical(matrix1);
            int r3 = rotate2(matrix1,matrix2);
            if(r3 > res)
            {
                res = r3;
            } */
            }
            else
            {
            res = rotate_match(matrix1,matrix2);
/*             if(horizontal(matrix1) != 1)
            {
                //水平不对称
                int r1 = rotate_match(matrix1,matrix2);
                if(r1 > res)
                {
                    res = r1;
                }
                horizontal(matrix1);//翻转回去
            }
            if(vertical(matrix1) != 1)
            {
                //垂直不对称
                int r2 = rotate_match(matrix1,matrix2);
                if(r2 > res)
                {
                    res = r2;
                } 
                vertical(matrix1);//翻转回去
            }
            horizontal(matrix1);
            vertical(matrix1);
            int r3 = rotate_match(matrix1,matrix2);
            if(r3 > res)
            {
                res = r3;
            } */
            }

            

            cout << res << endl;

    }
}