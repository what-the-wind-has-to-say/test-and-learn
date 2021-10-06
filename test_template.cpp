#include<bits/stdc++.h>
using namespace std;
//template <typename T> void Swap(T &a,T &b)
template <class T> void Swap(T &a,T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
    return;
}
int main()
{
    vector<int>nums{1,2,3,4,5};
    swap(nums[0],nums[1]);
    for(int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<double>nums2{1.0,1.1,1.2,1.3,1.4};
    Swap(nums2[0],nums2[1]);
    for(auto i : nums2)
    {
        cout << i << " ";
    }
    cout << endl;
}