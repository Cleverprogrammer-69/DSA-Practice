#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const vector<vector<int>>& arr) {  
    for (const auto& row : arr) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;  
    }
}

vector<vector<int>> pairSum(vector<int>& arr, int n) {
    vector<vector<int>> res;
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == n) {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                res.push_back(temp);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int sum = 7;
    display(pairSum(arr, sum));
    return 0;
}
