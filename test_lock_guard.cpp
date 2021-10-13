#include<bits/stdc++.h>
#include<thread>
using namespace std;
class Test_list
{
    private:
    mutex m1;
    int len;
    list<int> mylist;//互斥量通常会将需要保护的数据放在一个类中
    public:
    Test_list(int _len)
    {
        len = _len;
    }
    void add_to_list(int new_value)
    {
        //切勿将受保护数据的指针或引用传递到互斥锁作用域之外
        lock_guard<mutex> guard(m1);
        mylist.push_back(new_value);
        cout << "write in " << new_value << endl;
    }
    bool list_contains(int value_to_find)
    {
        lock_guard<mutex> guard(m1);
        return find(mylist.begin(),mylist.end(),value_to_find) != mylist.end();
    }
    void deal_req_list()
    {
        lock_guard<mutex> guard(m1);
        if(!mylist.empty())
        {
            cout << "deal with " << mylist.front() << endl;
            mylist.pop_front();
        }
    }
    void f1()
    {
        //写入线程入口
        for(int i = 0;i < len;i++)
        {
            add_to_list(i);
        }
    }
    void f2()
    {
        //读出线程入口
        for(int i = 0;i < len;i++)
        {
            deal_req_list();
        }
    }
};
int main()
{
    Test_list req(10000);
    //两个线程，一个写入一个读取
    thread t1(&Test_list :: f1,ref(req));
    thread t2(&Test_list :: f2,ref(req));
    t1.join();
    t2.join();
    cout << "t1 and t2 end" << endl;
    return 0;
}