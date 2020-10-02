#include<iostream>
using namespace std;

void fun(int n){
    if(n>0){
        cout<<"n "<<n<<endl;
        fun(n-1);
    }
}

void fun2(int n){
    if(n>0){
        fun2(n-1);
        cout<<"n "<<n<<endl;
    }
} 

int main(){
    int x=3;

    fun(x);
    cout<<endl;
    fun2(x);

    return 0;
}