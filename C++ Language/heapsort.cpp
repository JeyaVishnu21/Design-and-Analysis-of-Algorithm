// Implementing Heap Sort using Transfer and Conquer Technique

#include<iostream>
using namespace std;
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void heapify(int arr[], int n, int i) {
    int lar = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[lar])
        lar = left;
    if(right < n && arr[right] > arr[lar])
        lar = right;

    if(lar != i) {
        swap(arr[i], arr[lar]);
        heapify(arr, n, lar);
    }
}

void heapsort(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    cout << "\nInitial Max-Heap built: ";
    printArray(arr, n);
    cout << "--------------------------------\n";
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        cout << "Step " << (n - i) << " (swapped " << arr[i] << " to end): ";
        printArray(arr, n);
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    if (!(cin >> n) || n <= 0) return 0;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    heapsort(arr, n);
    cout << "--------------------------------\n";
    cout << "Final Sorted array: ";
    printArray(arr, n);

    return 0;
}
