#include<iostream>
#include<stdlib.h>

using namespace std;

int* increase_array_size(int* p, int size=1, int newSize=1){
    int *q=new int[newSize];
    for(int i=0;i<newSize;i++){
        int temp=i<size?p[i]:0;
        q[i]=temp;
    }

    delete []p;
    p=q;
    q=nullptr;
    return p;
}

int main(){
    int size=4;
    int *p=new int[size]{1,2,3,4};
    for(int i=0;i<size;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    int newSize=size*2;
    p=increase_array_size(p,size,newSize);
    for(int i=0;i<newSize;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return 0;
}
