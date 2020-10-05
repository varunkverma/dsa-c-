#include<iostream>
using namespace std;

int fibonacci_loop(int n){
    
    if(n<=1){
        return n;
    }
    
    int t0=0,t1=1,s=1;
    for(int i {2};i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

int fibonacci_recursion(int n){
    if(n<=1){
        return n;
    }
    return (fibonacci_recursion(n-2)+fibonacci_recursion(n-1));
}

int *fib_map=new int[10]{-1};
int fibonacci_memoized_recursion(int n){
    if(n<=1){
        fib_map[n]=n;
        return n;
    }
    if(fib_map[n-2]==-1){
        fib_map[n-2]=fibonacci_memoized_recursion(n-2);
    }
    if(fib_map[n-1]==-1){
        fib_map[n-1]=fibonacci_memoized_recursion(n-1);
    }
    return fib_map[n-2] + fib_map[n-1];    
}

int main(){
    int n=5;

    cout<<"fibonacci sum of "<<n<<" using loop: "<<fibonacci_loop(n)<<endl;
    cout<<"fibonacci sum of "<<n<<" using recursion: "<<fibonacci_recursion(n)<<endl;
    
    for(int i=0;i<n;i++){
        fib_map[i]=-1;
    }
    cout<<"fibonacci sum of "<<n<<" using memoized recursion: "<<fibonacci_memoized_recursion(n)<<endl;

    return 0;
}