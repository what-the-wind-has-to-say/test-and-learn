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
            
            //m1.lock();
            unique_lock<mutex> mylock(m1,try_to_lock);
            if(mylock.owns_lock())
            {
                //拿到了锁
                req.push_back(i);
                cout << "write in " << i << endl;
            }
            else
            {
                cout << "lock fail do other things" << endl;
            }
            //m1.unlock();
            mutex *ptr = mylock.release();
            m1.unlock();//解除关系后，需要手动unlock
        }
    }
    void read_out(int &command)
    {
        //lock_guard<mutex> mylock(m1);
        //unique_lock<mutex> mylock(m1);

        //m1.lock();
        //unique_lock<mutex> mylock(m1,adopt_lock);//会检查是否上锁

        unique_lock<mutex> mylock(m1,defer_lock);
        mylock.lock();
        //处理共享内存代码
        chrono :: milliseconds dura(2000);
        this_thread :: sleep_for(dura);//sleep 20s
        command = req.empty();
        if(!command)
        {
            cout << "read out " << req.front() << endl;
            req.pop_front();
        }
        mylock.unlock();
        //中途处理非共享内存代码
        mylock.lock();
        //返回处理共享代码
        //unique_lock,会在析构时自动解锁
        unique_lock<mutex> mylock2(move(mylock));//转移m1的所有权
    }
    void out_list()
    {
        for(int i = 0;i < 10000;i++)
        {
            int command = 0;
            read_out(command);
            if(command)
            {
                cout << "list is empty" << endl;
                i--;
            }
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