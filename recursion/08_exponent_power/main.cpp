#include<iostream>

using namespace std;

int simple_pow(int m, int n){
    if(n==0){
        return 1;
    }
    return m*simple_pow(m,n-1);
}

int better_pow(int m,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return better_pow(m*m, (n/2));
    }
    return m*better_pow(m*m,(n-1)/2);
}

int main(){

    int m=2;
    int n=9;
    cout<<"power of: "<<m<<" to the times, n: "<<n<<", is: "<<simple_pow(m,n)<<endl;
    cout<<"power of: "<<m<<" to the times, n: "<<n<<", is: "<<better_pow(m,n)<<endl;
    return 0;
}