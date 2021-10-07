#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a = 3;
    int b = 4;
    int *p = &a;//指针作为对象存储的是数据的地址
    int &c = b;//引用看作数据的别名
    cout << "value a is " << *p << endl;//访问数据的值需要解引用操作符
    cout << "value b is " << c << endl;
    c = 0;
    cout << "value b is " << c << endl;
}