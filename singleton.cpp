#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;
mutex lock1;//创建互斥量
//创建一个单例类
class Singleton
{
    private:
    int member1;
    float member2;
    Singleton(int m1 = 0,float m2 = 0.0):member1(m1),member2(m2){};
    static Singleton *my_instance;
    public:
    static Singleton *get_instance(int m1,float m2)
    {
        if(my_instance == NULL)
        {
            unique_lock<mutex> mylock(lock1);
            if(my_instance == NULL)
            {
                my_instance = new Singleton(m1,m2);
                static Singleton_delete tmp;//用于释放堆上内存
            }
        }
        return my_instance;
    }
    class Singleton_delete
    {
        public:
        ~Singleton_delete()
        {
            if(Singleton :: my_instance)
            {
                delete Singleton :: my_instance;
                Singleton :: my_instance = NULL;
                cout << "delete over" << endl;
            }
        }
    };
    void show()
    {
        cout << "member1 is " << member1 << endl;
        cout << "member2 is " << member2 << endl;
    }
};
Singleton * Singleton :: my_instance = NULL;//静态成员变量在类外初始化
void function1()
{
    cout << "thread " << this_thread :: get_id() << endl;
    Singleton *ptr = Singleton :: get_instance(1,60.5);
    if(ptr)
    {
        ptr->show();
    }
}
void function2()
{
    cout << "thread " << this_thread :: get_id() << endl;
    Singleton *ptr = Singleton :: get_instance(2,99.5);
    if(ptr)
    {
        ptr->show();
    }
}
int main()
{
    thread t1(function1);
    thread t2(function2);
    //只能创建一个对象
    t1.join();
    t2.join();
    //Singleton *ptr = Singleton :: get_instance(10,5.5);//创建单例类的对象
    //ptr->show();
    return 0;
}