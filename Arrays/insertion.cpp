#include<iostream>
using namespace std;
int insertion(int arr[], int &size, int element, int index){
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return size++;
    
}
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100] = {3,2,5,-3,13};
    int size = 5;
    int element = 1000;
    int index = 1;
    insertion(arr, size, element, index);
    cout<<size<<endl;
    display(arr, size);
    return 0;
}