// Implementing Insertion Sort using Transfer and Conquer Technique

#include<iostream>
using namespace std;
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        
       
        cout << "Step " << i << " (after inserting " << key << "): ";
        printArray(arr, n);
    }
}

int main() {
    int n;
    cout << "Enter no of elements: ";
    if (!(cin >> n) || n <= 0) return 0;

    int arr[n];
    cout << "Enter the " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nInitial array: ";
    printArray(arr, n);
    cout << "--------------------------" << endl;

    insertionSort(arr, n);

    cout << "--------------------------" << endl;
    cout << "Final Sorted array: ";
    printArray(arr, n);

    return 0;
}
