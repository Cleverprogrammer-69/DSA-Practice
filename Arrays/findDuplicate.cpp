#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> findDuplicates(vector<int>& arr){
  unordered_map<int,int> mp;
  vector<int> duplicates;
  for(int x:arr){
    if(mp.count(x)>0){
      duplicates.push_back(x);
    }else{
      mp[x]=1;
    }
  }
  return duplicates;
}
int main(){
  vector<int> numbers={1,3,2,4,1,4,3,34};
  vector<int> duplicates=findDuplicates(numbers);
  if(!duplicates.empty()){
    for(int number:duplicates){
      cout << number <<" ";
    }
  }
}