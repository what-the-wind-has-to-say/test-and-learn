#include<bits/stdc++.h>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex m1;//全局互斥量
int index = 0;//标志位
condition_variable cv;//全局条件变量
//在线程里面按顺序消费不同的产品
vector<int>products = {9,8,7,6,5,4,3,2,1,0};
bool isValid()
{
    return index != 0;
}
void consume(int n)
{
    for(int i = 0;i < n;i++)
    {
        unique_lock<mutex> mylock(m1);
        cv.wait(mylock,isValid);
        cout << "thread id " << this_thread :: get_id() << " consume" << products[index - 1] << endl;
        index = 0;
    }
}
int main()
{
    thread t1(consume,10);
    for(int i = 0;i < 10;i++)
    {
        while(isValid())
        {
            this_thread :: yield();//不为0，则等待
        }
        index = i + 1;
        cv.notify_all();
    }
    t1.join();
    return 0;
}