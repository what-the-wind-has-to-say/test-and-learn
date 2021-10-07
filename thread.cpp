#include<bits/stdc++.h>
#include<thread>
using namespace std;
class TA
{
    public:
    int num;

    TA(int _num)
    {
        num = _num;
        cout << "The constructor is executed" << " The num is" << " " << num << endl;
    }

    TA(const TA &ta):num(ta.num)
    {
        cout << "The copy constructor is executed" << " The num is" << " " << num << endl;
    }

    ~TA()
    {
        cout << "The destructor is executed" << endl;
    }
    void operator()()
    {
        cout << "operator" << endl;
    }
};
void myprint()
{
    int count = 0;
    for(int i = 0;i < 10;i++)
    {
        count++;
        cout << "test" << " " << count << " "<< "another thread" << endl;
    }
}
int main()
{
    //thread myobj(myprint);
    int num = 6;
    TA ta(num);
    thread myobj(ta);
    //myobj.join();//阻塞等待子线程执行结束
    //myobj.detach();
    myobj.join();
    int count = 0;
    for(int j = 0;j < 5;j++)
    {
        count++;
        cout << "test" << " " << count << " " << "multithreading " << endl;
    }
    return 0;
}