#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Array{
    int *A;
    //int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    printf("Elements of the array are: \n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void Append(Array *arr, int element){
    if(arr->length < arr->size){
        arr -> A[arr->length++]=element;
    }
}

void Insert(Array *arr, int index, int element){
    if(index>=0  && index<=arr->length){
        for(int i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=element;
        arr->length++;
    }
}

int Delete(Array *arr,int index){
    int deleted_value=0;
    if(index>=0 && index<arr->length){
        deleted_value=arr->A[index];
        for(int i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
    return deleted_value;
}

int Linear_Search(Array *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]==key){
            return i;
        }
    }
    return -1;
}

void swap(Array *arr, int i, int j ){
    int temp = arr->A[i];
    arr->A[i]=arr->A[j];
    arr->A[j]=temp;
}

int Linear_Search_Transposition(Array *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]==key){
            if(i!=0){
                swap(arr,i,i-1);
                return i-1;
            }
            return i;
        }
    }
    return -1;
}

int Linear_Search_Move_To_Head(Array *arr, int key){
    for(int i=0;i<arr->length;i++){
        if(arr->A[i]==key){
            if(i!=0){
                swap(arr,i,0);
                return 0;
            }
            return i;
        }
    }
    return -1;
}

int Binary_search_loop(Array *arr,int key){
    int left=0;
    int right= arr->length-1;
    int mid=int((left+right)/2);
    while(left<=right){
        if(arr->A[mid]==key){
            return mid;
        } else if (arr->A[mid]<key){
            left=mid+1;
        } else{
            right=mid-1;
        }
        mid=int((left+right)/2);
    }
    return -1;
}

int Binary_search_recursive(Array *arr, int left, int right, int key){
    if(left>right){
        return -1;
    }
    int mid =int((left+right)/2);
    if(arr->A[mid]==key){
        return mid;
    } else if (arr->A[mid]<key){
        return Binary_search_recursive(arr,mid+1,right,key);
    } else{
        return Binary_search_recursive(arr,left,mid-1,key);
    }
}

int get(Array *arr, int index){
    if(index>=0 && index <arr->length){
        return arr->A[index];
    }
    return -1;
}

void set(Array *arr, int index, int newValue){
    if(index>=0 && index <arr->length){
        arr->A[index]=newValue;
    }
}

int max(Array arr){
    int maxEle=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(maxEle<arr.A[i]){
            maxEle=arr.A[i];
        }
    }
    return maxEle;
}

int min(Array arr){
    int minEle=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(minEle>arr.A[i]){
            minEle=arr.A[i];
        }
    }
    return minEle;
}

int sum(Array arr){
    int total=0;
    for(int i=1;i<arr.length;i++){
        total+=arr.A[i];
    }
    return total;
}

float avg(Array arr){
    return (float)sum(arr)/arr.length;
}

void reverse_auxiliary(Array *arr){
    int *B;
    B=new int[arr->length];

    for(int i=arr->length-1,j=0;i>=0;i--,j++){
        B[j]=arr->A[i];
    }
    for(int i=0;i<arr->length;i++){
        arr->A[i]=B[i];
    }
}

void reverse(Array *arr){
    for(int i=0,j=arr->length-1;i<j;i++,j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j]=temp;
    }
}

void insert_in_sorted_array(Array *arr, int x){
    if(arr->length==arr->size){ // no free space
        return ; 
    }
    int i=arr->length-1;
    while( i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

bool is_sorted(Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return false;
        }
    }
    return true;
}

void rearrange_negative_and_positive(Array *arr){
    int i=0;
    int j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j--;}
        if(i<j){
            swap(arr,i,j);
        }
    }
}

struct Array* merge(Array *arr1, Array *arr2){
    int i=0;
    int j=0;
    int k=0;

    // int *C=new int[arr1->length+arr2->length];
    
     Array *C = new Array{{},arr1->size+arr2->size,arr1->length+arr2->length};
    //  Array *C = (&Array{{},arr1->size+arr2->size,arr1->length+arr2->length}) ; won't work, need to allocate memory in heap

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            C->A[k++]=arr1->A[i++];
        } else {
            C->A[k++]=arr2->A[j++];
        }
    }

    while(i<arr1->length){
        C->A[k++]=arr1->A[i++];
    }
    while(j<arr2->length){
        C->A[k++]=arr2->A[j++];
    }
    return C;
}

struct Array* union_array(Array *arr1, Array *arr2){
    int i=0;
    int j=0;
    int k=0;

    // int *C=new int[arr1->length+arr2->length];
    
     Array *C = new Array{{},arr1->size+arr2->size,0};
    //  Array *C = (&Array{{},arr1->size+arr2->size,arr1->length+arr2->length}) ; won't work, need to allocate memory in heap

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            C->A[k++]=arr1->A[i++];
        } else if( arr1->A[i]> arr2->A[j]){
            C->A[k++]=arr2->A[j++];           
        } else {
            C->A[k++]=arr1->A[i++];
            j++;
        }
    }

    while(i<arr1->length){
        C->A[k++]=arr1->A[i++];
    }
    while(j<arr2->length){
        C->A[k++]=arr2->A[j++];
    }
    C->length=k;
    return C;
}

struct Array* intersection(Array *arr1, Array *arr2){
    int i=0;
    int j=0;
    int k=0;

    // int *C=new int[arr1->length+arr2->length];
    
     Array *C = new Array{{},arr1->size+arr2->size,0};
    //  Array *C = (&Array{{},arr1->size+arr2->size,arr1->length+arr2->length}) ; won't work, need to allocate memory in heap

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            i++;
        } else if( arr1->A[i]> arr2->A[j]){
            j++;           
        } else {
            C->A[k++]=arr1->A[i++];
            j++;
        }
    }
    C->length=k;
    return C;
}

struct Array* array_difference(Array *arr1, Array *arr2){
    int i=0;
    int j=0;
    int k=0;

    // int *C=new int[arr1->length+arr2->length];
    
     Array *C = new Array{{},arr1->size+arr2->size,0};
    //  Array *C = (&Array{{},arr1->size+arr2->size,arr1->length+arr2->length}) ; won't work, need to allocate memory in heap

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j]){
            C->A[k++]=arr1->A[i++];
        } else if( arr1->A[i]> arr2->A[j]){
            j++;           
        } else {
            i++;
            j++;
        }
    }
    while(i<arr1->length){
        C->A[k++]=arr1->A[i++];
    }
    C->length=k;
    return C;
}

int main(){
    // Array arr = {{2,3,4,5,6},10,5};
    
    // // Initialisation
    // Array arr;
    // printf("Enter the size of the array: \n");
    // scanf("%d",&arr.size);
    // arr.A=(int *)malloc(arr.size * sizeof(int));
    // arr.length=0;

    // int n,i;
    // printf("Enter how many numbers, you want to insert: \n");
    // scanf("%d",&n);

    // printf("Enter all elements\n");
    // for(int i =0;i<n;i++){
    //     scanf("%d",&arr.A[i]);
    // }
    // arr.length=n;

    // Display(arr);
    // Append(&arr,10);
    // Display(arr);
    // Insert(&arr,4,8);
    // Display(arr);
    // printf("deleted element: %d \n",Delete(&arr,4));
    // Display(arr);

    // int key=5;
    // int linear_search_result = Linear_Search(&arr,key);
    // if(linear_search_result==-1){
    //     printf("Element: %d not found\n",key);
    // }
    // else{
    //     printf("Element: %d, found at index: %d\n",key,linear_search_result);
    // }

    // int linear_search_transposition_result = Linear_Search_Transposition(&arr,key);
    // if(linear_search_transposition_result==-1){
    //     printf("Element: %d not found\n",key);
    // }
    // else{
    //     printf("Element: %d, found at index: %d\n",key,linear_search_transposition_result);
    // }
    // int key2=0;
    // linear_search_transposition_result = Linear_Search_Transposition(&arr,key2);
    // if(linear_search_transposition_result==-1){
    //     printf("Element: %d not found\n",key2);
    // }
    // else{
    //     printf("Element: %d, found at index: %d\n",key2,linear_search_transposition_result);
    // }
    // key2=2;
    // linear_search_transposition_result = Linear_Search_Transposition(&arr,key2);
    // if(linear_search_transposition_result==-1){
    //     printf("Element: %d not found\n",key2);
    // }
    // else{
    //     printf("Element: %d, found at index: %d\n",key2,linear_search_transposition_result);
    // }
    
    // key2=6;
    // int linear_search_move_to_head_result = Linear_Search_Move_To_Head(&arr,key2);
    // if(linear_search_move_to_head_result==-1){
    //     printf("Element: %d not found\n",key2);
    // }
    // else{
    //     printf("Element: %d, found at index: %d\n",key2,linear_search_move_to_head_result);
    // }
    // Display(arr);
    
    // int key=3;
    // int binary_search_result = Binary_search_loop(&arr,key);
    // if( binary_search_result == -1){
    //     printf("Element %d, not found\n",key);
    // } else {
    //     printf("Element %d, found at: %d\n",key, binary_search_result);
    // }
    // key=1;
    // binary_search_result = Binary_search_loop(&arr,key);
    // if( binary_search_result == -1){
    //     printf("Element %d, not found\n",key);
    // } else {
    //     printf("Element %d, found at: %d\n",key, binary_search_result);
    // }

    // key=2;
    // binary_search_result = Binary_search_recursive(&arr,0,arr.length-1,key);
    // if( binary_search_result == -1){
    //     printf("Element %d, not found\n",key);
    // } else {
    //     printf("Element %d, found at: %d\n",key, binary_search_result);
    // }
    // key=1;
    // binary_search_result = Binary_search_recursive(&arr,0,arr.length-1,key);
    // if( binary_search_result == -1){
    //     printf("Element %d, not found\n",key);
    // } else {
    //     printf("Element %d, found at: %d\n",key, binary_search_result);
    // }

    // printf("element at index: %d, is: %d\n",2,get(&arr, 2));

    // set(&arr,2,10);
    // Display(arr);
    
    // printf("max number: %d\n",max(arr));
    // printf("min number: %d\n",min(arr));
    // printf("sum of numbers: %d\n",sum(arr));
    // printf("avg of numbers: %f\n",avg(arr));

    // reverse_auxiliary(&arr);
    // reverse(&arr);
    // Display(arr);

    // Display(arr);
    // insert_in_sorted_array(&arr,12);
    // insert_in_sorted_array(&arr,9);
    // insert_in_sorted_array(&arr,-3);
    // Display(arr);

    // printf("is array sorted: %s\n",is_sorted(arr)?"true":"false");

    // Array arr2 = {{-7,2,0,-3,3,-10,4,5,-6,-1},10,10};
    // Display(arr2);
    // rearrange_negative_and_positive(&arr2);
    // Display(arr2);

    // Array arr2 = {{1,3,5,7,9},10,5};
    // Array arr3 = {{2,4,6,8,10},10,5};

    // Array *arr2_arr3_merged;
    // arr2_arr3_merged=merge(&arr2,&arr3);
    // Display(*arr2_arr3_merged);

    // Array arr2 = {{2,6,10,15,25},10,5};
    // Array arr3 = {{3,6,7,15,20},10,5};

    // Array *arr2_arr3_union;
    // arr2_arr3_union=union_array(&arr2,&arr3);
    // Display(*arr2_arr3_union);

    // Array *arr2_arr3_intersection;
    // arr2_arr3_intersection=intersection(&arr2,&arr3);
    // Display(*arr2_arr3_intersection);
    
    // Array *arr2_arr3_difference;
    // arr2_arr3_difference=array_difference(&arr2,&arr3);
    // Display(*arr2_arr3_difference);

    struct Array arr1;
    int ch,x,index;

    printf("Enter size of array: ");
    scanf("%d",&arr1.size);
    arr1.A = new int[arr1.size];
    arr1.length=0;

    do{
        printf("Menu\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. search\n");
        printf("4. sum\n");
        printf("5. display\n");
        printf("6. exit\n");

        printf("enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter an element and index: ");
                scanf("%d%d",&x,&index);
                Insert(&arr1, index, x);
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d",&index);
                x=Delete(&arr1, index);
                printf("\nDeleted element: %d\n",x);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d",&x);
                index=Linear_Search(&arr1, x);
                printf("\nElement index: %d \n",index);
                break;
            case 4:
                printf("Sum is: %d\n",sum(arr1));
                break;
            case 5:
                Display(arr1);
        }
    } while(ch<6);

    return 0;
}
