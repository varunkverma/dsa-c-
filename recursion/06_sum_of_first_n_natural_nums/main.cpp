#include<iostream>

using namespace std;

int sum_of_first_n_natural_numbers(int n){
    if(n>=1){
        return n+sum_of_first_n_natural_numbers(n-1);
    }
    return n;
}

int main(){
    int n=5;
    cout<<"when n: "<<n<<", sum: "<<sum_of_first_n_natural_numbers(n)<<endl;
    n=1;
    cout<<"when n: "<<n<<", sum: "<<sum_of_first_n_natural_numbers(n)<<endl;
    n=0;
    cout<<"when n: "<<n<<", sum: "<<sum_of_first_n_natural_numbers(n)<<endl;
    
    // using, matematical formula, time complexity is O(1)
    n=5;
    cout<<"when n: "<<n<<", sum: "<<n*(n+1)/2<<endl;


    return 0;
}