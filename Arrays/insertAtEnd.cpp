#include<iostream>
using namespace std;
int arrayPush(int arr[], int &size, int element){
    arr[size] = element;
    return size++;
}
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100] = {2,4,1,-2,100};
    int size = 5, element = 101;
    arrayPush(arr, size, element);

    display(arr, size);
    return 0;
}