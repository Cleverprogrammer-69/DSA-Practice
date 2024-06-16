#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void display(const vector<vector<int>>& numbers) {
    for(const auto& row : numbers) {
        for(int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> triplet(vector<int>& numbers, int sum) {
    vector<vector<int>> newArray;
    sort(numbers.begin(), numbers.end()); 
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            for(int k = j + 1; k < numbers.size(); k++) {
                if(numbers[i] + numbers[j] + numbers[k] == sum) {
                    vector<int> temp = {numbers[i], numbers[j], numbers[k]};
                   
                    if(find(newArray.begin(), newArray.end(), temp) == newArray.end()) {
                        newArray.push_back(temp);
                    }
                }
            }
        }
    }
    sort(newArray.begin(), newArray.end()); // Sort resulting triplets for consistent output
    return newArray;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, -1, -2, -3, -43};
    int sum = 14;
    display(triplet(numbers, sum));
    return 0;
}
