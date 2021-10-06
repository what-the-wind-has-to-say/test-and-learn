#include<bits/stdc++.h>
using namespace std;
template <typename T1,typename T2>
class Point
{
    private:
    T1 x;
    T2 y;
    public:
    Point(T1 _x,T2 _y):x(_x),y(_y){};
    void set_x(T1 _x);
    void set_y(T2 _y)
    {
        y = _y;
    }
    T1 get_x() const
    {
        return x;
    }
    T2 get_y() const
    {
        return y;
    }
};
template <typename T1,typename T2>
void Point<T1,T2> :: set_x(T1 _x)
{
    x = _x;
}
int main()
{
    Point<int,int>p1(10,10);
    Point<int,float> *p2 = new Point<int,float>(10,10.5);
    cout << p1.get_x() << " " << p1.get_y() << endl;
    cout << p2->get_x() << " " << p2->get_y() << endl;
}