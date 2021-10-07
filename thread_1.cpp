#include<bits/stdc++.h>
#include<thread>
using namespace std;
void thr_function1()
{
    for(int i = 0;i < 10;i++)
    {
        cout << "thread 1 print " << i << endl;
    }
    return;
}
void thr_function2(int num)
{
    cout << "thread 2 print " << num << endl;
}
int main()
{
    
    thread t1(thr_function1);
    thread t2(thr_function2,222);
    cout << "thread 1 and 2 now execute concurrently" << endl;
    t1.join();//等待线程1执行结束
    t2.join();//等待线程2执行结束
    
    cout << "thread 1 and 2 are finished" << endl;
    //线程之间存在竞争
}