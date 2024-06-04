#include<iostream>
using namespace std;
void updateArray(int arr[], int index, int element){
    arr[index]=element;
}
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100] = {1,2,3,4,5};
    int size=5, index = 2, element = 20;
    updateArray(arr, index, element);
    display(arr, size);
    return 0;
}