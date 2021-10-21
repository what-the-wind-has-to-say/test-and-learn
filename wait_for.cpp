#include<bits/stdc++.h>
using namespace std;
condition_variable cv;
int value;
void cin_val()
{
    cin >> value;
    cv.notify_one();
}
//主线程等待子线程输入一个数，未检测到输入每s打印信息
int main()
{
    thread t1(cin_val);
    mutex m1;
    unique_lock<mutex> mylock(m1);
    while(cv.wait_for(mylock,chrono :: seconds(1)) == cv_status :: timeout)
    {
        cout << "." << endl;
        cout.flush();
    }
    cout << "The value is" << value << endl;
    return 0;
}