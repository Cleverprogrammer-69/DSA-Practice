#include<iostream>
using namespace std;
void display(int arr[], int length){
    for(int i=0; i<length; i++){
        cout<<arr[i]<<" ";
    }
}
void zeroOneSort(int arr[], int length){
    int left=0,right=length-1;
    while(left<right){
        while(arr[left]==0 && left<right){
            left++;
        }
        while(arr[right]==1 && left<right){
            right--;
        }
        if(arr[left]==1 && arr[right]==0 && left<right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}
int main(){
    cout<<"hello "<<endl;
    int arr[6]={1,0,1,0,0,1};
    zeroOneSort(arr, 6);
    display(arr, 6);
}