#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};
struct Complex{
    int real;
    int imag;

    Complex operator+(Complex a){
        Complex res;
        res.real=real+a.real;
        res.imag=imag+a.imag;
        return res;
    }
};

int main(){
    Rectangle rect;
    Rectangle rect2 ={12,15};
    rect.length=10;
    rect.breadth=12;
    cout<<"Area 1: "<<rect.length*rect.breadth<<endl; 
    cout<<"Area 2: "<<rect2.length*rect2.breadth<<endl;

    Complex a{10,20};
    Complex b{30,55};
    Complex c=a+b;
    cout<<c.real<<"+"<<c.imag<<"i"<<endl; 
    return 0;
}