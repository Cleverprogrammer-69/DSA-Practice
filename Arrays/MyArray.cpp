#include <iostream>
using namespace std;

class MyArray {
private:
    int arr[100];
    int length;

public:
    MyArray() {
        length = 0;
        for (int i = 0; i < 100; i++) {
            arr[i] = -11223;
        }
    }

    int getLength() {
        return this->length;
    }

    void get() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void set(int a[], int l) {
        length = l;
        for (int i = 0; i < length; i++) {
            arr[i] = a[i];
        }
    }

    bool isFull() {
        return length == 100;
    }

    bool isEmpty() {
        return length == 0;
    }

    int max() {
        int max = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    int min() {
        int min = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    bool insert(int index, int element) {
        if (index >= 0 && index <= length && !isFull()) {
            for (int i = length - 1; i >= index; i--) {
                arr[i + 1] = arr[i];
            }
            arr[index] = element;
            length++;
            get();
            return true;
        }
        return false;
    }

    bool delIndex(int index) {
        if (index >= 0 && index < length && !isEmpty()) {
            for (int i = index; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
            get();
            return true;
        }
        return false;
    }

    bool insertAtEnd(int element) {
        if (!isFull()) {
            arr[length] = element;
            length++;
            get();
            return true;
        }
        return false;
    }

    bool insertAtStart(int element) {
        return insert(0, element);
    }

    int findIndexOf(int element) {
        int foundIndex = -1;
        for (int i = 0; i < length; i++) {
            if (arr[i] == element) {
                foundIndex = i;
                break;
            }
        }
        return foundIndex;
    }
};

int main() {
    MyArray arr1;
    int numbers[5] = {2, 4, 1, 2, 90};
    cout << arr1.isEmpty() << endl;
    cout << arr1.isFull() << endl;
    arr1.set(numbers, 5);
    arr1.get();
    if (!arr1.insert(2, 100)) {
        cout << "Insert failed." << endl;
    }
    cout << "Length: " << arr1.getLength() << endl;
    if (!arr1.delIndex(4)) {
        cout << "Delete failed." << endl;
    }
    cout << "Length: " << arr1.getLength() << endl;
    if (!arr1.insertAtEnd(1000)) {
        cout << "Insert at end failed." << endl;
    }
    cout << "Length: " << arr1.getLength() << endl;
    arr1.get();
    int indexFound = arr1.findIndexOf(1000);
    if (indexFound != -1) {
        cout << "Found at index: " << indexFound << endl;
    } else {
        cout << "Not Found" << endl;
    }
    if (!arr1.insertAtStart(7)) {
        cout << "Insert at start failed." << endl;
    }
    arr1.get();
}
