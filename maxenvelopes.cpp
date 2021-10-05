#include<bits/stdc++.h>
using namespace std;

    bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0] < b[0])
        {
            return true;
        }
        else if(a[0] == b[0])
        {
            return a[1] > b[1];
        }
        else
        {
            return false;
        }
    }

int main()
{
    vector<vector<int>>envelopes(4,vector<int>(2));
    envelopes[0][0] = 5;
    envelopes[0][1] = 4;
    envelopes[1][0] = 6;
    envelopes[1][1] = 4;
    envelopes[2][0] = 6;
    envelopes[2][1] = 7;
    envelopes[3][0] = 2;
    envelopes[3][1] = 3;
    sort(envelopes.begin(),envelopes.end(),cmp);
    for(int i = 0;i < envelopes.size();i++)
    {
        cout << envelopes[i][0] << " " << envelopes[i][1] << endl;
    }
    return 0;
}