#include<iostream>
#include<vector>
using namespace std;
vector<int> intersection(vector<int>& a1, vector<int>& a2){
    vector<int> newArray;
    for(int i=0; i<a1.size(); i++){
        for(int j=0; j<a2.size(); j++){
            if(a1[i]==a2[j]){
                newArray.push_back(a1[i]);
                a2[j]=-112211;
                break;
            }
        }
    }
    return newArray;
}
int main(){
    vector<int> arr1={4,75,1,-3,76,23};
    vector<int> arr2={3,4,2,6,34};
    vector<int> result = intersection(arr1, arr2);
    if(!result.empty()){
        for(auto i:result){
            cout<<i<<" ";
        }
    }
    else{
        cout<<-1;
    }
    
}