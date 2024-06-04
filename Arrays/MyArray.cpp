#include<iostream>
using namespace std;
class MyArray{
    private:
        int arr[100];
        int size;
    public:
        MyArray(){
            size = 100;
            for(int i=0; i<100; i++){
                arr[i]=-1;
            }

        }
        int getSize(){
            return this->size;
        }
        void get(){
            for(int i = 0; i < size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        void set(int a[], int s){
            this->size=s;
            for(int i = 0; i < size; i++){
                arr[i]=a[i];
            }
        }
        int max(int a[], int s){
            int max=a[0];
            for(int i=0; i<s; i++){
                if(a[i]>max){
                    max=a[i];
                }
            }
            return max;
        }
        int min(int a[], int s){
            int min=a[0];
            for(int i=0; i < s; i++){
                if(a[i]<min){
                    min=a[i];
                }
            }
            return min;
        }
        int insert(int index, int element){
            for(int i=size-1;i>=index;i--){
                arr[i+1]=arr[i];
            }
            arr[index]=element;
            size++;
            get();
            return size;
        }
        int deleteElement(int index){
            for(int i=index; i<size; i++){
                arr[i]=arr[i+1];
            }
            size--;
            get();
            return size;
        }
        int push(int element){
            arr[size]=element;
            size++;
            return size;
        }
        int findIndex(int element){
            int foundIndex=-1;
            for(int i=0; i<size; i++){
                if(arr[i] == element){
                    foundIndex = i;
                    break;
                }
            }
            return foundIndex;
        }

};
int main(){
    MyArray arr1;
    int numbers[10]={2,4,1,2,90};
    arr1.set(numbers, 5);
    arr1.get();
    arr1.insert(2, 100);
    cout<< arr1.getSize()<<endl;
    arr1.deleteElement(4);
    cout<< arr1.getSize()<<endl;
    arr1.push(1000);
    cout<< arr1.getSize()<<endl;
    arr1.get();
    int indexFound = arr1.findIndex(40);
    indexFound != -1 ? cout<<"Found at :"<<indexFound : cout<<"Not Found";
}