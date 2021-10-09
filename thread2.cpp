#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;
//互斥量，写入和读出两个线程，同时运行，不能同时进行写入和读出操作
class Req
{
    private:
    list<int>req;
    mutex m1;
    public:
    void in_list()
    {
        for(int i = 0;i < 10000;i++)
        {
            
            m1.lock();
            req.push_back(i);
            cout << "write in " << i << endl;
            m1.unlock();
        }
    }
    void out_list()
    {
        for(int i = 0;i < 10000;i++)
        {
            m1.lock(); 
            if(!req.empty())
            {        
                auto command = req.front();
                cout << "read out " << command << endl;
                req.pop_front();
                m1.unlock();
                continue;
            }
            i--;
            m1.unlock();
        }
    }
};
int main()
{
    Req r;
    thread t1(Req :: in_list,ref(r));
    thread t2(Req :: out_list,ref(r));
    t1.join();
    t2.join();
    cout << "end" << endl;
    return 0;
}