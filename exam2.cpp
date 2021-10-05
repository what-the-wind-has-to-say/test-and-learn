#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream in("test.txt");
    int N;//丢包数量
    while(in >> N)
    {
        if(N != 0)
        {
            vector<int>loss(N);
            for(int i = 0;i < N;i++)
            {
                in >> loss[i];
            }
            int M;//修复数量
            in >> M;
            sort(loss.begin(),loss.end());
            
            
            //必须连续不间断补包，不然失去意义
            int res = 0;
            int end = N - M ;//补包起点的终点
            if(N == M)
            {
                res = 10000;
            }
            //从第一个开始修
            for(int i = 0;i <= end;i++)
            {
                vector<int>isValid(N,0);//是否被修复
                for(int j = i;j < i + M;j++)
                {
                    isValid[j] = 1;
                }
                vector<int>true_loss;
                for(int l = 0;l < N;l++)
                {
                    if(isValid[l] == 0)
                    {
                        true_loss.push_back(loss[l]);
                    }
                }
                //算首尾
                int shou = true_loss[0] - 1;
                int wei = 10000 - true_loss[true_loss.size() - 1];
                int tmp = max(shou,wei);
                if(tmp > res)
                {
                    res = tmp;
                }
                //算间隔
                if(true_loss.size() >= 2)
                {
                    for(int l = 0;l < true_loss.size() - 1;l++)
                    {
                        if(true_loss[l + 1] - true_loss[l] - 1 > res)
                        {
                            res = true_loss[l + 1] - true_loss[l] - 1;
                        }
                    }
                }
            }
            cout << res << endl;
        }
        else
        {
            cout << 10000 << endl;
        }
    }
    return 0;
}