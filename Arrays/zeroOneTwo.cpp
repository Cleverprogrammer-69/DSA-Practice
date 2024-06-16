#include<iostream>
using namespace std;
void display(int arr[], int length){
    for(int i=0; i<length; i++){
        cout<<arr[i]<<" ";
    }
}
void zeroOneTwo(int arr[], int length){
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
    int arr[]={1,2,0,2,1,0,0,1,2,0};
    zeroOneTwo(arr, 10);
    display(arr, 10);
}