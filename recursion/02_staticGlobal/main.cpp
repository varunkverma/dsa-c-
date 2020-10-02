#include<iostream>

using namespace std;

int g=0;

int fun(int n){
    static int x=0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    return 0;
}
int fun2(int n){
    if(n>0){
        g++;
        return fun2(n-1)+g;
    }
    return 0;
}

int main(){
    int a=5;
    cout<<"result: "<<fun(a)<<endl;
    cout<<"result: "<<fun2(a)<<endl;
    return 0;
}
