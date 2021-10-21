#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x)
{
    for(int i = 2;i < x;i++)
    {
        if(x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int x = 444444443;
    future<bool> fut = async(is_prime,x);
    //do something to waiting for function to set future
    cout << "checking please wait" << endl;
    chrono :: milliseconds span(10);//10ms
    while(fut.wait_for(span) == future_status :: timeout)
    {
        cout << "." << endl;
    }
    bool res = fut.get();
    if(res)
    {
        cout << x << " is prime number" << endl;
    }
    else
    {
        cout << x << " is not prime number" << endl;
    }
    return 0;
}