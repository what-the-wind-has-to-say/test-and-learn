#include<bits/stdc++.h>
#include<thread>
using namespace std;
//向线程传递参数
void f1(int &i,const string &str)
{
    cout << "thread id is " << this_thread :: get_id() << endl;
    cout << i << " " << str << endl;
    i = 2*i;
}
class Tmp
{
    public:
    int num;
    Tmp(int _num):num(_num){};
    void f2(int i, string &str)
    {
        cout << "thread id is " << this_thread :: get_id() << endl;
        cout << i << " " << str << endl;
    }
};
int main()
{
    char c[80];
    sprintf(c,"magic girl's age is %i",12);
    string str = "nanoha";
    int age = 12;
    Tmp tmp1(2);
    //传递一个成员函数指针作为线程函数,且不使用隐式类型转换
    //thread t1(& Tmp :: f2,&tmp1,age,ref(str));
    thread t2(f1,ref(age),string(c));
    //t1.join();
    t2.join();
    cout << "age is " << age << endl;
    return 0;
}
