#include<bits/stdc++.h>
using namespace std;
class Address;
class Student
{
    private:
    char* name;
    int age;
    float score;
    public:
    Student(char *_name,int _age,float _score):name(_name),age(_age),score(_score)
    {}
    void show(Address *address);
};
class Address
{
    private:
    char* province;//省份
    char* city;//城市
    char* district;//街区
    public:
    Address(char* _province,char* _city,char* _district)
    {
        province = _province;
        city = _city;
        district = _district;
    }
    //friend void Student :: show(Address *address);
    friend class Student;
};

void Student :: show(Address *address)
{
    cout << "The student " << name << " is from " << address->province << " " << address->city << " " << address->district << endl;
}

int main()
{
    Student stu("小明", 16, 95.5f);
    Address addr("陕西", "西安", "雁塔");
    stu.show(&addr);
   
    Student *pstu = new Student("李磊", 16, 80.5);
    Address *paddr = new Address("河北", "衡水", "桃城");
    pstu -> show(paddr);
    return 0;
}