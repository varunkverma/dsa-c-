#include<iostream>
#include<stdlib.h>

using namespace std;


int main(){
    int A[3][3]={{1,2,3},{2,3,4},{4,5,6}};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    int *B[3];
    B[0]=new int[3];
    B[1]=new int[3];
    B[2]=new int[3];

    int **C;
    // C=(int**)malloc(3*sizeof(int));
    // C[0]=new int[3];
    // C[1]=new int[3];
    // C[2]=new int[3];
    C=new int*[3];
    C[0]=new int[3];
    C[1]=new int[3];
    C[2]=new int[3];
    
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}