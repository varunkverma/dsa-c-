#include<iostream>

using namespace std;

double taylor_homer_using_loop(int x, int n){
    double temp_result=1;
    for(int i {n}; i>0;i--){
        temp_result=1+ ((temp_result*x)/i);
    }
    return temp_result;
}

double taylor_homer_using_recursion_1(int x, int n){
    static double rec_result=1;
    if(n==0){
        return rec_result;
    }
    rec_result=1+((x*rec_result)/n);
    return taylor_homer_using_recursion_1(x,n-1);
}

double fun(int x, int i, int n){
        if(n-i==n){
            return 1;
        }
        return fun(x,i-1,n)*(((x*1.0)/(n-i+1))) + 1;
}
double taylor_homer_using_recursion_2(int x, int n){
    int i=n;
    return fun(x,i,n);
}

int main(){
    int x {1};
    int n {10};
    cout<<taylor_homer_using_loop(x,n)<<endl;
    cout<<taylor_homer_using_recursion_1(x,n)<<endl;
    cout<<taylor_homer_using_recursion_2(x,n)<<endl;

    return 0;
}