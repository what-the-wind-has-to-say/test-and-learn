#include<bits/stdc++.h>
#include<functional>
using namespace std;
//普通函数
int f1(int a,int b)
{
    return a + b;
}
//函数对象
class f2
{
    public:
    int operator()(int a,int b)
    {
        return a + b;
    }
};
//类模板函数对象
template<class T>
class f3
{
    public:
    T operator()(T a,T b)
    {
        return a + b;
    }
};
//lambda表达式
auto f4 = [](const int a,const int b){return a + b;};
//类静态成员函数
class f5
{
    public:
    static int m_f5(int a,int b)
    {
        return a + b;
    }
};
//类成员函数
class f6
{
    public:
    int m_f6(int a,int b)
    {
        return a + b;
    }
};
//公有类数据成员
class f7
{
    public:
    int num;
    f7(int _num)
    {
        num = _num;
    }
};
int main()
{
    function<int(int,int)>func1 = f1;
    cout << "normal function " << func1(1,2) << endl;
    function<int(int,int)>func2 = f2();
    cout << "function object " << func2(2,3) << endl;
    function<int(int,int)>func3 = f3<int>();
    cout << "class template function object " << func3(3,4) << endl;
    function<int(int,int)>func4 = f4;
    cout << "lambda " << func4(4,5) << endl;
    //类成员函数需要取地址
    function<int(int,int)>func5 = &f5 :: m_f5;
    cout << "class static member function " << func5(5,6) << endl;
    f6 tmp6;
    function<int(f6&,int,int)>func6 = &f6 :: m_f6;
    cout << "class member function " << func6(tmp6,6,7) << endl;
    f7 tmp7(7 + 8);
    function<int(f7&)>func7 = &f7 :: num;
    cout << "class public member " << func7(tmp7) << endl;
    //bind函数
    function<int(int,int)>func8 = bind(&f6 :: m_f6,tmp6,placeholders :: _1,placeholders :: _2);
    cout << "bind " << func8(8,9) << endl;
    return 0;
}