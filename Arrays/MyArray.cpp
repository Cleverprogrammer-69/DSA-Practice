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

    int getLength()   {
        return length;
    }

    void print()   {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void set(  int a[], int l) {
        if (l > 100) {
            cout << "Array length exceeds maximum allowed size." << endl;
            return;
        }
        length = l;
        for (int i = 0; i < length; i++) {
            arr[i] = a[i];
        }
    }

    bool isFull()   {
        return length == 100;
    }

    bool isEmpty()   {
        return length == 0;
    }

    int max()   {
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

    int min()   {
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
        return true;
    }

    bool insertAtEnd(int element) {
        if (isFull()) {
            return false;
        }
        arr[length++] = element;
        return true;
    }

    bool insertAtStart(int element) {
        return insert(0, element);
    }

    int find(int element)   {
        for (int i = 0; i < length; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    bool doesExist(int element)   {
        return find(element) != -1;
    }

    int getFirstElement()   {
        return isEmpty() ? -9999 : arr[0];
    }

    int getLastElement()   {
        return isEmpty() ? -9999 : arr[length - 1];
    }

    int getElementAtPosition(int index)   {
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
    MyArray arr1, arr2;
    int numbers[5] = {2, 4, 1, 2, 90};

    cout << "Is Empty: " << arr1.isEmpty() << endl;
    cout << "Is Full: " << arr1.isFull() << endl;

    arr1.set(numbers, 5);
    arr1.print();

    if (!arr1.insert(2, 100)) {
        cout << "Insert failed." << endl;
    }

    cout << "Length: " << arr1.getLength() << endl;

    if (!arr1.removeByIndex(4)) {
        cout << "Delete failed." << endl;
    }

    cout << "Length: " << arr1.getLength() << endl;

    if (!arr1.insertAtEnd(1000)) {
        cout << "Insert at end failed." << endl;
    }

    cout << "Length: " << arr1.getLength() << endl;
    arr1.print();

    int indexFound = arr1.find(1000);
    cout << (indexFound != -1 ? "Found at index: " + indexFound : "Not Found") << endl;

    if (!arr1.insertAtStart(7)) {
        cout << "Insert at start failed." << endl;
    }
    arr1.print();
    cout<<arr2.isEmpty();
    return 0;
}
