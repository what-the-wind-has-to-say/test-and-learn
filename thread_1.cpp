#include<bits/stdc++.h>
#include<thread>
using namespace std;
class Complex
{
    private:
    int real;
    int imag;
    public:
    Complex(int _real = 0,int _imag = 0):real(_real),imag(_imag)
    {
        cout << "constructor is used" << endl;
        cout << "this thread_id is " << this_thread :: get_id() << endl;
    }
    Complex(const Complex & com)
    {
        real = com.real;
        imag = com.imag;
        cout << "copy constructor is used" << endl;
        cout << "this thread_id is " << this_thread :: get_id() << endl;
    }
    friend ostream &operator<<(ostream &out,Complex &com);
    void show()const
    {
        cout << real << " + " << imag << "i" << endl;
    }
    void set_real(int _real)
    {
        real = _real;
    }
    void set_imag(int _imag)
    {
        imag = _imag;
    }
    void entrance(int num)
    {
        //以类的成员函数作为子线程的入口
        cout << "this thread_id is " << this_thread :: get_id() << endl;
        cout << num << endl;
        cout << real << " + " << imag << "i" << endl;
    }
    // mutable int real;
    // mutable int imag;
};
ostream &operator<<(ostream &out,Complex &com)
{
    out << com.real << " + " << com.imag << "i";
    return out;
}
void thr_function1()
{
    cout << "this thread_id is " << this_thread :: get_id() << endl;
    cout << "thread 1 print: " << endl;
    for(int i = 0;i < 10;i++)
    {
        if(i != 9)
        cout << i << " ";
        else
        cout << i << endl;
    }
    return;
}
void thr_function2(int num)
{
    cout << "this thread_id is " << this_thread :: get_id() << endl;
    cout << "thread 2 print " << num << endl;
}
/* void thr_function3(const Complex &com)
{
    cout << "this thread_id is " << this_thread :: get_id() << endl;
    com.real = 2;
    com.imag = 3;
    com.show();
} */
void thr_function4(Complex &com)
{
    cout << "this thread_id is " << this_thread :: get_id() << endl;
    com.set_real(2);
    com.set_imag(3);
    com.show();
}
int main()
{
    
    //thread t1(thr_function1);
    //thread t2(thr_function2,222);
    //cout << "thread 1 and 2 now execute concurrently" << endl;
    //t1.join();//等待线程1执行结束
    //t2.join();//等待线程2执行结束
    
    //cout << "thread 1 and 2 are finished" << endl;
    //线程之间存在竞争
    Complex com1(5,5);
    //thread t3(thr_function3,com1);
    //t3.join();
    // thread t4(thr_function4,ref(com1));
    // t4.join();
    thread t5(Complex :: entrance,com1,15);
    t5.join();
    cout << com1 << endl;
    return 0;
}