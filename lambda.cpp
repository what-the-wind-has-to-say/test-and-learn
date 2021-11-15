#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums{1,8,9,45,12,37,99,101};
    sort(nums.begin(),nums.end(),[](const int &a,const int &b){return a > b;});
    for(int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}