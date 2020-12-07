#include<iostream>

using namespace std;

struct Array {
    int *A;
    int length;
    int size;
};

void findOneMissingElementInSortedArrayOfFirstNNaturalNumbers(Array *arr){
    int sum=0;
    for(int i=0;i<arr->length;i++){
        sum+=arr->A[i];
    }
    int lastElement=arr->A[arr->length-1];
    int sumOfFirstNNaturalNumbers = int((lastElement * (lastElement+1))/2);
    int missingElement = sumOfFirstNNaturalNumbers - sum;
    cout<<"Missing Element: "<<missingElement<<endl;
}

void findingOneMissingElementInSortedArray(Array *arr){
    int diff = arr->A[0];
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]-i != diff){
            cout<<"Missing Element: "<<i+diff<<endl;
            break;
        }
    }
}

int main(){
    Array arr={new int[15]{1,2,3,4,5,6,8,9,10},9,15};
    
    findOneMissingElementInSortedArrayOfFirstNNaturalNumbers(&arr);

    findingOneMissingElementInSortedArray(&arr);

    return 0;
}