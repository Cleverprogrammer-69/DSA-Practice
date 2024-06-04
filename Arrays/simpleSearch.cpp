#include<iostream>
using namespace std;
int arrayFindIndex(int arr[], int size, int element){
    int foundIndex=-1;
    for(int i=0; i<size; i++){
        if(arr[i] == element){
            foundIndex = arr[i];
            break;
        }
    }
    return foundIndex;
}
int main(){
    int arr[10] = {1,2,34,4,523,-6,27,8,9,10};
    int size=10, element = 8;
    cout << "Element " << element << " found at index " << arrayFindIndex(arr, size, element);
    return 0;
}