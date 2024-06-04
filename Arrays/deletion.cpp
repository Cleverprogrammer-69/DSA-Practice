#include<iostream>
using namespace std;
int indexDelete(int arr[], int &size, int index){
    for(int i = index; i<size; i++){
        arr[i]=arr[i+1];
    }
    return size--;
}
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100]={2,31,4,-4,13};
    int size=5, index = 3;
    indexDelete(arr, size, index);
    display(arr, size);
}