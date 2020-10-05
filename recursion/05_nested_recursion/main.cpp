#include<iostream>

using namespace std;

int nestedFun(int n){

    if(n>100){
        return n-10;
    }
    return nestedFun(nestedFun(n+11));
}

int main(){
    int x=95;
    cout<<"for "<<x<<": "<<nestedFun(x)<<endl;
    
    return 0;
}