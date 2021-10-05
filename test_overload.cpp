#include<bits/stdc++.h>
using namespace std;
//重载复数运算
class Complex
{
    private:
    double real;
    double imag;
    public:
    Complex(double _real,double _imag):real(_real),imag(_imag){}
    //全局函数的重载
    friend Complex operator+(const Complex A,const Complex B);
    friend Complex operator-(const Complex A,const Complex B);
    friend Complex operator*(const Complex A,const Complex B);
    friend Complex operator/(const Complex A,const Complex B);
    friend bool operator==(const Complex A,const Complex B);
    friend bool operator!=(const Complex A,const Complex B);
    //成员函数重载
    Complex & operator+=(const Complex &A);
    Complex & operator-=(const Complex &A);
    Complex & operator*=(const Complex &A);
    Complex & operator/=(const Complex &A);

    double get_real()
    {
        return real;
    }
    double get_imag()
    {
        return imag;
    }
};
Complex operator+(const Complex A,const Complex B)
{
    return Complex(A.real + B.real,A.imag + B.imag);
}
Complex operator-(const Complex A,const Complex B)
{
    return Complex(A.real - B.real,A.imag - B.imag);
}
Complex operator*(const Complex A,const Complex B)
{
    return Complex(A.real*B.real - A.imag*B.imag,A.real*B.imag + A.imag*B.real);
}
Complex operator/(const Complex A,const Complex B)
{
    double tmp = pow(B.imag,2) + pow(B.real,2);
    return Complex((A.real*B.real + A.imag*B.imag)/tmp,(A.imag*B.real - A.real*B.imag)/tmp);
}
bool operator==(const Complex A,const Complex B)
{
    return (A.real == B.real) && (A.imag == B.imag);
}
bool operator!=(const Complex A,const Complex B)
{
    return !(A == B);
}
Complex & Complex :: operator+=(const Complex &A)
{
    
    this->real += A.real;
    this->imag += A.imag;
    return *this;
}
Complex & Complex :: operator-=(const Complex &A)
{
    
    this->real -= A.real;
    this->imag -= A.imag;
    return *this;
}
Complex & Complex :: operator*=(const Complex &A)
{
    
    this->real = this->real*A.real - this->imag*A.imag;
    this->imag = this->real*A.imag + this->imag*A.real;
    return *this;
}
Complex & Complex :: operator/=(const Complex &A)
{
    double tmp = pow(A.imag,2) + pow(A.real,2);
    this->real = (this->real*A.real + this->imag*A.imag)/tmp;
    this->imag = (this->imag*A.real - this->real*A.imag)/tmp;
    return *this;
}
int main()
{
    Complex c1(25, 35);
    Complex c2(10, 20);
    Complex c3(1, 2);
    Complex c4(4, 9);
    Complex c5(34, 6);
    Complex c6(80, 90);
   
    Complex c7 = c1 + c2;
    Complex c8 = c1 - c2;
    Complex c9 = c1 * c2;
    Complex c10 = c1 / c2;
    cout<<"c7 = "<<c7.get_real()<<" + "<<c7.get_imag()<<"i"<<endl;
    cout<<"c8 = "<<c8.get_real()<<" + "<<c8.get_imag()<<"i"<<endl;
    cout<<"c9 = "<<c9.get_real()<<" + "<<c9.get_imag()<<"i"<<endl;
    cout<<"c10 = "<<c10.get_real()<<" + "<<c10.get_imag()<<"i"<<endl;
   
    c3 += c1;
    c4 -= c2;
    c5 *= c2;
    c6 /= c2;
    cout<<"c3 = "<<c3.get_real()<<" + "<<c3.get_imag()<<"i"<<endl;
    cout<<"c4 = "<<c4.get_real()<<" + "<<c4.get_imag()<<"i"<<endl;
    cout<<"c5 = "<<c5.get_real()<<" + "<<c5.get_imag()<<"i"<<endl;
    cout<<"c6 = "<<c6.get_real()<<" + "<<c6.get_imag()<<"i"<<endl;
   
    if(c1 == c2){
        cout<<"c1 == c2"<<endl;
    }
    if(c1 != c2){
        cout<<"c1 != c2"<<endl;
    }
   
    return 0;
}