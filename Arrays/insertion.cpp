#include<iostream>
using namespace std;
bool insertion(int arr[], int size, int element, int index, int capacity){
    if(size >= capacity){
        return false;
    }
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return true;
    
}
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100] = {3,2,5,-3,13};
    int size = 100;
    int element = 1000;
    int index = 1;
    int capacity = 100;
    bool result = insertion(arr, size, element, index, capacity);
    if(result){
        size++;
        display(arr, size);
    }
    else{
        cout<<"No more element can be inserted in an array"<<endl;
    }
    return 0;
}