#include<iostream>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
int main(){
    int *p;
    p=(int*)malloc(2*sizeof(int));
    p[0]=10;
    p[1]=20;
    cout<<p[0]<<" "<<p[1]<<endl;

    Rectangle rect{10,12};
    Rectangle *rect_ptr=&rect;
    cout<<rect_ptr->length<<" "<<rect_ptr->breadth<<" "<<endl;

    // dynamic access
    Rectangle *rect_ptr_heap=(Rectangle*)malloc(sizeof(Rectangle));
    rect_ptr_heap->length=rect.length;
    rect_ptr_heap->breadth=rect.breadth;

    cout<<rect_ptr_heap->length<<" "<<rect_ptr_heap->breadth<<endl;

    return 0;
}