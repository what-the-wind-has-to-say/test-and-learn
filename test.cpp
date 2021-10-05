#include<bits/stdc++.h>
using namespace std;
int main()
{
        int height[5] = {1,3,2,4,5};
        int res = 0;
        stack<int>st1;
        stack<int>st2;
        //找到从第一个非0数开始右边，更大的和更小下标，没有为-1
        vector<int>greater(5,-1);
        vector<int>smaller(5,-1);
        for(int i = 0;i < 5;i++)
        {
            while(!st1.empty() && height[i] > height[st1.top()])
            {
                greater[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
            while(!st2.empty() && height[i] < height[st2.top()])
            {
                smaller[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
        for(int i = 0;i < smaller.size();i++)
        {
            cout << greater[i] << " ";
        }
        cout << endl;
    return 0;
}