#include<iostream>
#include<vector>
using namespace std;
int findUnique(int arr[], int size){
    int uniqueElem=0;
    for(int i = 0; i<size; i++){
        uniqueElem = uniqueElem ^ arr[i];
    }
    return uniqueElem;
}
int main(){
    int arr[100] = {2,3,1,5,1,3,2};
    int size=7;
    cout<<"Unique element in given array is : "<<findUnique(arr, size)<<endl;
    cout<<arr;
}