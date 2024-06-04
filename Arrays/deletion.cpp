#include<iostream>
using namespace std;
void indexDelete(int arr[], int size, int index){
   for(int i = index; i<size; i++){
        arr[i]=arr[i+1];
   }
}
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[100]={2,31,4,-4,13};
    int size=5, index = 2;
    indexDelete(arr, size, index);
    size--;
    display(arr, size);
}