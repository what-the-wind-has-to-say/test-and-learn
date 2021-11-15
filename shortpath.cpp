#include<bits/stdc++.h>
using namespace std;
class Bind
{
    public:
    int x;
    int y;
    int remain;
    Bind(int _x,int _y,int _remain):x(_x),y(_y),remain(_remain){};
};
int main()
{
    set<Bind*>myset;
    Bind* b = new Bind(0,0,1);
    myset.insert(&Bind(0,0,1));
    return 0;
}