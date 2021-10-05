#include<bits/stdc++.h>
using namespace std;
//基类
class People
{
    private:
    string hobby;
    protected:
    int age;
    string name;
    public:
    People(string &_name,int _age,string _hobby):name(_name),age(_age),hobby(_hobby)
    {
        cout << "People constructor" << endl;
    };

    ~People()
    {
        cout << "People destructor" << endl;
    }
    void set_hobby(string &_hobby);
    string get_hobby();
};

void People :: set_hobby(string &_hobby)
{
    hobby = _hobby;
}

string People :: get_hobby()
{
    return hobby;
}
//派生类1
class Student : public People
{
    protected:
    float score;
    public:
    Student(string _name,int _age,string &_hobby,float _score):People(_name,_age,_hobby),score(_score){};//调用基类的构造函数

    ~Student()
    {
        cout << "Student destructor" << endl;
    }

    void set_score(float _score)
    {
        score = _score;
    }

    float get_score()
    {
        return score;
    }

    void show()
    {
        cout << "The name is " << name << endl;
        cout << "The age is " << age << endl;
        cout << "The hobby is " << get_hobby() << " with the score is " << score << endl;
    }
};
//派生类2
class TopStudent : public Student
{
    protected:
    int awards;
    public:
    TopStudent(string _name,int _age,string &_hobby,float _score,int _awards):Student(_name,_age,_hobby,_score),awards(_awards)
    {
        cout << "TopStudent constructor" << endl;
    }

    ~TopStudent()
    {
        cout << "TopStudent destructor" << endl;
    }

    void set_awards(int _awards)
    {
        awards = _awards;
    }

    int get_awards()
    {
        return awards;
    }

    void Top_show()
    {
        show();
        cout << "The top student has " << awards << " awards" << endl;
    }
};
int main()
{
    string name = "nanoha";
    string hobby = "magic";
    //Student* st1 = new Student(name,12,hobby,59.9);
    //st1->show();
    TopStudent* st2 = new TopStudent(name,12,hobby,59.9,20);
    st2->Top_show();
    delete st2;
    return 0;
}