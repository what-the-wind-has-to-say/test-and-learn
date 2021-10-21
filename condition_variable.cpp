#include<bits/stdc++.h>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex m1;//全局互斥锁
condition_variable cv;//全局条件变量
bool flag = false;//全局标志位

void do_print_id(int id)
{
    //线程入口函数
    unique_lock<mutex> mylock(m1);
    while(!flag)
    {
        cv.wait(mylock);//标志位不使能，则等待
    }
    cout << "thread id " << id << endl;
}

void go()
{
    //唤醒
    unique_lock<mutex> mylock(m1);
    flag = true;
    cv.notify_all();
}

int main()
{
    vector<thread> threads(10);
    for(int i = 0;i < threads.size();i++)
    {
        threads[i] = thread(do_print_id,i);
    }
    cout << "ready to print ..." << endl;
    go();
    for(auto &i : threads)
    {
        i.join();
    }
    return 0;
}