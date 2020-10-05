#include<iostream>

using namespace std;

int factorial_of_number(int n){
    if(n>1){
        return n*factorial_of_number(n-1);
    }
    return 1;
}

int main(){
    int n=5;
    cout<<"Factorial of n: "<<n<<", is: "<<factorial_of_number(n)<<endl;
    return 0;
}