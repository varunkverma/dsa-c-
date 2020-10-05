#include<iostream>

using namespace std;

double taylor_e(int x, int n){
    static double power=1;
    static double factorial=1;

    if(n==0){
        return 1;
    }

    double temp_res=taylor_e(x,n-1);
    power*=x;
    factorial*=n;

    return temp_res+(power/factorial);
}

int main(){

    int x=1;
    int n=10;

    cout<<taylor_e(x,n)<<endl;
    return 0;
}
