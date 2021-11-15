#include<bits/stdc++.h>
using namespace std;
condition_variable cv;
int flag = 0;
mutex m1;
void consumer()
{
    unique_lock<mutex> mylock(m1);
    cv.wait(mylock,[]{return flag != 0;});
    cout << flag << endl;
    flag = 0;
}
void producer(int id)
{
    unique_lock<mutex> mylock(m1);
    flag = id;
    cv.notify_one();
}
int main()
{
    vector<thread>consumers;
    vector<thread>producers(10);
    for(int i = 0;i < 10;i++)
    {
        consumers.push_back(thread(consumer));
        producers[i] = thread(producer,i + 1);
    }
    for(int i = 0;i < 10;i++)
    {
        consumers[i].join();
        producers[i].join();
    }
    return 0;
}