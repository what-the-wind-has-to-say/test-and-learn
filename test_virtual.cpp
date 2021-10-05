#include<bits/stdc++.h>
using namespace std;
class People
{
    protected:
    int age;
    string name;
    public:
    People(string &_name,int _age)
    {
        name = _name;
        age = _age;
    }
    virtual void display()
    {
        cout << name << " is " << age << " years old" << endl;
    }
};
class Teacher : public People
{
    protected:
    string profession;
    public:
    Teacher(string _name,int _age,string _profession):People(_name,_age)
    {
        profession = _profession;
    }
    virtual void display()
    {
        cout << name << " is " << age << " years old" << " with the profession " << profession << endl;
    }
};

//测试纯虚函数
class Base
{
    //抽象类
    public:
    virtual float area() = 0;
    virtual float volume() = 0;
    //定义两个纯虚函数
};
//矩形
class Rec : public Base
{
    protected:
    float len;
    float width;
    public:
    Rec(float _len,float _width):len(_len),width(_width){};
    float area();
};
float Rec :: area()
{
    return len*width;
}
//长方体
class Cuboid : public Rec
{
    protected:
    float high;
    public:
    Cuboid(float _len,float _width,float _high):Rec(_len,_width)
    {
        high = _high;
    }
    float area();
    float volume();
};
float Cuboid :: area()
{
    return 2*((len*width) + (len*high) + (width*high));
}
float Cuboid :: volume()
{
    return len*width*high;
}
//正方体
class Cube : public Cuboid
{
    public:
    Cube(float _len):Cuboid(_len,_len,_len){};
    float area();
    float volume();
};
float Cube :: area()
{
    return 6*len*len;
}
float Cube :: volume()
{
    return len*len*len;
}
int main()
{
    string name = "nanoha";
    string profession = "magic_girl";
    People* p = new People(name,12);
    Teacher* t = new Teacher(name,12,profession);
    p = t;
    p->display();
    //形成多态，利用基类（抽象类）指针
    Base* p_b1 = new Cuboid(2.0,3.0,5.0);
    cout << "Cuboid's area is " << p_b1->area() << endl;
    cout << "Cuboid's volume is " << p_b1->volume() << endl;
    p_b1 = new Cube(2.0);
    cout << "Cube's area is " << p_b1->area() << endl;
    cout << "Cube's volume is " << p_b1->volume() << endl;
    return 0;
}