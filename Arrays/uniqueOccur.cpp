#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool uniqueOccurences(vector<int>& arr){
  map<int, int> mp;
  vector<int> occurences;

  for(auto element:arr){
    mp[element]++;
  }
  for(auto element:mp){
    // cout << element.first<<"  "<< element.second<<endl;
    occurences.push_back(element.second);
  }
  for(int i = 0; i<occurences.size()-1; i++){
    for(int j = i+1; j<occurences.size(); j++){
      if(occurences[i]==occurences[j]){
        return false;
      }
    }
  }
  return true;
}
int main(){
  vector<int> numbers={1,2,2,3,3,3,44,44,44};
  if(uniqueOccurences(numbers)){
    cout << "Array's elements have unique occurences";
  }else {
        cout << "Array's elements do not have unique occurrences." << endl;
    }
}