#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2)
{
    return a1 > a2;
}
class cmp2
{
    public:
    bool operator()(int i,int j)
    {
        return i > j;
    }
};
void pt(vector<int> &nums)
{
    for(int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    vector<int>nums{10,13,4,16,77,22};
    pt(nums);
    sort(nums.begin(),nums.end());
    pt(nums);
    sort(nums.begin(),nums.end(),cmp);
    pt(nums);
    reverse(nums.begin(),nums.end());
    sort(nums.begin(),nums.end(),cmp2());
    pt(nums);
    reverse(nums.begin(),nums.end());
    sort(nums.begin(),nums.end(),greater<int>());
    pt(nums);
    return 0;
}