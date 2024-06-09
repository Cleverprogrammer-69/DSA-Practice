#include<iostream>
using namespace std;
int main(){
    int arr[100]={20,10,40,30,60};
    int size = 5;
    if(size%2==0){
        for(int i=0;i<size;i=i+2){
            swap(arr[i], arr[i+1]);
        }
    }else{
        for(int i=0;i<size;i=i+2){
            if(arr[i]!=arr[size-1]){
                swap(arr[i], arr[i+1]);
            }else break;
            
        }
    }
    
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}