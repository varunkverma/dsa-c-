#include<iostream>

using namespace std;

void tower_of_hanoi(int n, char A, char B, char C){
    if(n>0){
        tower_of_hanoi(n-1,A,C,B);
        cout<<A<<" -> "<<C<<endl;
        tower_of_hanoi(n-1,B,A,C);
    }
}

int main(){

    int n=3;
    tower_of_hanoi(n,'A','B','C');
    return 0;
}