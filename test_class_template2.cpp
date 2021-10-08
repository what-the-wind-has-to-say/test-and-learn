#include<bits/stdc++.h>
using namespace std;
template <class T>
class MyArray
{
    private:
    int size;
    T* ptr;//模板数组的指针
    public:
    MyArray(int _size);
    MyArray(MyArray &copy);//另一个模板数组直接初始化
    int length()
    {
        return size;
    }
    void push_back(const T &e);
    //重载=运算符，方便模板数组间赋值
    MyArray & operator=(MyArray &copy);
    //重载[]运算符,方便以下标形式查找元素
    T & operator[](int i)
    {
        return ptr[i];
    }
};
template <typename T>
//构造函数1
MyArray<T> :: MyArray(int _size):size(_size)
{
    if(size == 0)
    {
        ptr = NULL;
    }
    else
    {
        //分配内存
        ptr = new T[size];
    }
}
template <typename T>
//构造函数2
MyArray<T> :: MyArray(MyArray &copy)
{
    if(copy.ptr == NULL)
    {
        ptr = NULL;
        return;
    }
    //调用内存拷贝函数
    ptr = new T[copy.size];
    memccpy(ptr,copy.ptr,sizeof(T)*copy.size);
    size = copy.size;
}
//成员函数形式重载=
template <typename T>
MyArray<T> & MyArray<T> :: operator=(MyArray &copy)
{
    if(copy.ptr == NULL)
    {
        ptr = NULL;
        size = 0;
        return *this;
    }
    else if(copy.size < size)
    {
        //若赋值数组容量小于原数组容量，则不需要重新分配内存
        memcpy(ptr,copy.ptr,sizeof(T)*copy.size);
        size = copy.size;
        return *this;
    }
    if(ptr)
    {
        delete []ptr;
    }
    ptr = new T[copy.size];
    memcpy(ptr,copy.ptr,sizeof(T)*copy.size);
    size = copy.size;
    return *this;    
}
template <typename T>
void MyArray<T> :: push_back(const T &e)
{
    if(!ptr)
    {
        //数组本来为空
        ptr = new T[1];
        ptr[1] = e;
        return;
    }
    else
    {
        T* tmpptr = new T[size + 1];
        memcpy(tmpptr,ptr,sizeof(T)*size);
        ptr = tmpptr;
        ptr[size++] = e;
    }
}  
int main()
{
    MyArray<int>p(5);
    for(int i = 0;i < p.length();i++)
    {
        p[i] = i;
    }
    p.push_back(5);
    for(int i = 0;i < p.length();i++)
    cout << p[i] << " ";
    cout << endl;
    return 0;
}