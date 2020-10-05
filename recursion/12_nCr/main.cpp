#include<iostream>

using namespace std;

int nCr(int n, int r){
    if(r==0 || n==r){
        return 1;
    }
    return nCr(n-1,r-1)+nCr(n-1,r);
}

int main(){

    int n=4,r=2;

    cout<<"combination of "<<n<<"C"<<r<<": "<<nCr(n,r)<<endl;

    return 0;
}