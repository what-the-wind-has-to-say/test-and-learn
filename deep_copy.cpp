#include<bits/stdc++.h>
using namespace std;
class Array
{
    //如果一个类拥有指针类型成员变量，一般需要深拷贝
    private:
    int len;
    int* ptr;
    public:
    Array(int _len = 0):len(_len)
    {
        if(len == 0)
        {
            ptr = NULL;
        }
        else
        {
            ptr = new int[len];
        }
    }
    //Array(const Array &arr);
    int operator[](int i)const
    {
        return ptr[i];//读取
    }
    int &operator[](int i)
    {
        return ptr[i];//写入
    }
    int length()
    {
        return len;
    }
};
/*
Array :: Array(const Array &arr)
{
    if(arr.len == 0)
    {
        ptr = NULL;
        len = 0;
        return;
    }
    else
    {
        ptr = new int[arr.len];
        memcpy(ptr,arr.ptr,sizeof(int)*arr.len);
        len = arr.len;
    }
}
*/
void print_Array(Array &arr)
{
    for(int i = 0;i < arr.length();i++)
    {
        if(i == arr.length() - 1)
        {
            cout << arr[i] << endl;
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
}
int main()
{
    Array arr(10);
    for(int i = 0;i < 10;i++)
    {
        arr[i] = i;
    }
    Array arr2(arr);
    arr2[2] = 222;
    arr2[3] = 333;
    print_Array(arr);
    print_Array(arr2);
    return 0;
}