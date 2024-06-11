#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> intersection(vector<int>& a1, vector<int>& a2){
    vector<int> newArray;
    int i=0,j=0;
    while(i<a1.size() && j<a2.size()){
        if(a1[i]==a2[j]){
            newArray.push_back(a1[i]);
            i++;
            j++;
        }else if(a1[i]<a2[j]){
            i++;
        }else{
            j++;
        }
    }
    sort(newArray.begin(), newArray.end());
    return newArray;
}
int main(){
    vector<int> arr1={4,75,1,-3,76,23};
    vector<int> arr2={3,4,76,6,34};
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