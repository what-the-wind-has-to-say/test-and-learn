#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream in_h("half_p.txt");//半周期时域数据
    ifstream in_s("single_p.txt");//单周期时域数据
    ifstream in_a("analog_V.txt");//模拟输入信号时域数据
    vector<double>half;
    vector<double>single;
    vector<double>analog;
    string t;
    double V_half;
    double V_single;
    double V_analog;
    while(in_h >> t)
    {
        in_h >> V_half;
        half.push_back(V_half);
    }
    in_h.close();
    while(in_s >> t)
    {
        in_s >> V_single;
        single.push_back(V_single);
    }
    in_s.close();
    while(in_a >> t)
    {
        in_a >> V_analog;
        analog.push_back(V_analog);
    }
    in_a.close();
    ofstream out_h("half_T.txt");
    ofstream out_s("single_T.txt");
    ofstream out_a("analog.txt");
    for(int i = 0;i < half.size();i++)
    {
        out_h << half[i] << endl;
        out_s << single[i] << endl;
        out_a << analog[i] << endl;
    }
    return 0;
}