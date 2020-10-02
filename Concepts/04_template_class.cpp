#include<iostream>

using namespace std;

template <class T>
class Arithematic{
    private:
    T a;
    T b;
    public:
    Arithematic(T a, T b):a(a),b(b){}

    T Sum(){
        return a+b;
    }
    T Subtract(){
        return a-b;
    }
};

int main(){

    int a=10,b=20;
    Arithematic<int> arith= Arithematic<int>(10,20);
    cout<<"Sum: "<<arith.Sum()<<endl<<"Subtract: "<<arith.Subtract()<<endl;
    Arithematic<float> arith2= Arithematic<float>(10.65,20.80);
    cout<<"Sum: "<<arith2.Sum()<<endl<<"Subtract: "<<arith2.Subtract()<<endl;
    return 0;
}