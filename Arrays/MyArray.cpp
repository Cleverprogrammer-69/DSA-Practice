#include <iostream>
using namespace std;

class MyArray {
private:
    int arr[100];
    int length;

public:
    MyArray() : length(0) {
        for (int i = 0; i < 100; i++) {
            arr[i] = -11223;
        }
    }

    int getLength() {
        return length;
    }

    void print() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void set(int a[], int l) {
        if (l > 100) {
            cout << "Array length exceeds maximum allowed size." << endl;
            return;
        }
        length = l;
        for (int i = 0; i < length; i++) {
            arr[i] = a[i];
        }
        print();
    }

    bool isFull() {
        return length == 100;
    }

    bool isEmpty() {
        return length == 0;
    }

    int max() {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
            return -1;
        }
        int maxVal = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    int min() {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
            return -1;
        }
        int minVal = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        return minVal;
    }

    bool insert(int index, int element) {
        if (index < 0 || index > length || isFull()) {
            return false;
        }
        for (int i = length - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        length++;
        print();
        return true;
    }

    bool removeByIndex(int index) {
        if (index < 0 || index >= length || isEmpty()) {
            return false;
        }
        for (int i = index; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
        length--;
        print();
        return true;
    }

    bool insertAtEnd(int element) {
        if (isFull()) {
            return false;
        }
        arr[length++] = element;
        print();
        return true;
    }

    bool insertAtStart(int element) {
        return insert(0, element);
    }

    int find(int element) {
        for (int i = 0; i < length; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    bool doesExist(int element) {
        return find(element) != -1;
    }

    int getFirstElement() {
        return isEmpty() ? -9999 : arr[0];
    }

    int getLastElement() {
        return isEmpty() ? -9999 : arr[length - 1];
    }

    int getElementAtPosition(int index) {
        if (index < 0 || index >= length) {
            return -9999;
        }
        return arr[index];
    }

    bool removeElement(int element) {
        int index = find(element);
        if (index == -1) {
            return false;
        }
        return removeByIndex(index);
    }

    bool removeFirstElement() {
        return removeByIndex(0);
    }

    bool removeLastElement() {
        return removeByIndex(length - 1);
    }
};

int main() {
    MyArray arr1;
    int numbers[5] = {2, 4, 1, 2, 90};

    
    cout << "Setting initial array:" << endl;
    arr1.set(numbers, 5);

   
    cout << "Is Empty: " << arr1.isEmpty() << endl;
    cout << "Is Full: " << arr1.isFull() << endl;

    
    cout << "Inserting 100 at index 2:" << endl;
    if (!arr1.insert(2, 100)) {
        cout << "Insert failed." << endl;
    }

   
    cout << "Length: " << arr1.getLength() << endl;

   
    cout << "Removing element at index 4:" << endl;
    if (!arr1.removeByIndex(4)) {
        cout << "Delete failed." << endl;
    }

    cout << "Length: " << arr1.getLength() << endl;

    
    cout << "Inserting 1000 at end:" << endl;
    if (!arr1.insertAtEnd(1000)) {
        cout << "Insert at end failed." << endl;
    }

    cout << "Length: " << arr1.getLength() << endl;

    
    int indexFound = arr1.find(1000);
    if (indexFound != -1) {
        cout << "Found at index: " << indexFound << endl;
    } else {
        cout << "Not Found" << endl;
    }

    
    cout << "Inserting 7 at start:" << endl;
    if (!arr1.insertAtStart(7)) {
        cout << "Insert at start failed." << endl;
    }

    
    cout << "Max value: " << arr1.max() << endl;
    cout << "Min value: " << arr1.min() << endl;

    
    cout << "Does 1000 exist: " << arr1.doesExist(1000) << endl;

   
    cout << "First element: " << arr1.getFirstElement() << endl;
    cout << "Last element: " << arr1.getLastElement() << endl;

    
    cout << "Element at position 3: " << arr1.getElementAtPosition(3) << endl;

    
    cout << "Removing element 1000:" << endl;
    if (!arr1.removeElement(1000)) {
        cout << "Remove element failed." << endl;
    }

    
    cout << "Removed first element:" << endl;
    if (!arr1.removeFirstElement()) {
        cout << "Remove first element failed." << endl;
    }

    cout << "Removed last element:" << endl;
    if (!arr1.removeLastElement()) {
        cout << "Remove last element failed." << endl;
    }

    return 0;
}
