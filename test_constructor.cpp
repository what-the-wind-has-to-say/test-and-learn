#include<bits/stdc++.h>
using namespace std;
class Student
{
    private:
    char* name;
    int age;
    double score;
    public:
    Student(char* _name,int _age,double _score):name(_name),age(_age),score(_score)
    {};
    Student():name(NULL),age(0),score(0.0){};
    void set_name(char* _name);
    void set_age(int _age);
    void set_score(double _score);
    char* get_name()
    {
        return name;
    }
    int get_age()
    {
        return age;
    }
    double get_score()
    {
        return score;
    }
};
void Student :: set_name(char* _name)
{
    name = _name;
}
void Student :: set_age(int _age)
{
    age = _age;
}
void Student :: set_score(double _score)
{
    score = _score;
}
int main()
{
    char name[] = "KK";
    char *A = "KKZK";
    string name_str = "KKK";
    Student std1(name,10,60.0);
    Student* std2 = new Student(A,15,90.0);
    cout << std1.get_name() << " age is " << std1.get_age() << " score is " << std1.get_score() << endl;
    cout << std2->get_name() << " age is " << std2->get_age() << " score is " << std2->get_score() << endl;
    cout << A[2] << endl;
    delete std2;
    return 0;
}