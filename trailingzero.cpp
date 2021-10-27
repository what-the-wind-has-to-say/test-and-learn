#include<bits/stdc++.h>
using namespace std;
int trailing_zero(int n)
{
    int res = 0;
    for(int d = n;d/5 >0;d = d/5)
    {
        res += d/5;
    }
    return res;
}
int main()
{
    int n = INT_MAX;
    cout << trailing_zero(n) << endl;
    return 0;
}