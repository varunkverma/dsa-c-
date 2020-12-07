#include<iostream>
using namespace std;

int main(){

    int a[5];
    int b[5] = {1,2,3,4,5};
    int c[5]={0};
    int d[5]={1,2};
    int e[]={0,1,2,3,4,5};

    for(int i =0;i<5;i++){
        printf("%u \n",&a[i]);
    }

    return 0;
}


