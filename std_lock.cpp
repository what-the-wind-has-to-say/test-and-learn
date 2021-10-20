#include<bits/stdc++.h>
#include<thread>
#include<mutex>
using namespace std;
void Swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}
class vec_A
{
    private:
    vector<int>vec;
    int size;
    mutex m1;
    public:
    vec_A(int _size = 0):size(_size)
    {
        vector<int>_vec(size,0);
        vec = _vec;
    }
    void function1(int num)
    {
        if(num > size)
        {
            return;
        }
        for(int i = 0;i < num;i++)
        {
            vec[i] = i;
        }
        return;
    }
    friend void Swap_vec_A(vec_A &a,vec_A &b,int index1,int index2)
    {
        if(&a == &b)
        {
            //同一个对象
            return;
        }
        lock(a.m1,b.m1);//同时锁住两个对象的互斥量
        lock_guard<mutex> lock_a(a.m1,adopt_lock);//将第一个对象的锁交给lock_guard管理
        lock_guard<mutex> lock_b(b.m1,adopt_lock);//将第二个对象的锁交给lock_guard管理
        Swap(a.vec[index1],b.vec[index2]);
    }
    void show()
    {
        for(int i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};
int main()
{
    vec_A *v1 = new vec_A(20);
    vec_A *v2 = new vec_A(20);
    thread t1(&vec_A :: function1,ref(v1),20);
    thread t2(&vec_A :: function1,ref(v2),20);
    //Swap_vec_A(*v1,*v2,15,5);
    t1.join();
    t2.join();
    Swap_vec_A(*v1,*v2,15,5);
    v1->show();
    v2->show();
    return 0;
}