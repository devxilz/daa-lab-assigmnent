#include<iostream>
using  namespace std;

void insertionSort(int arr[], int n){
    int step_count = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            step_count++;
        }
        arr[j + 1] = key;
    }
    cout << "Number of steps taken: " << step_count << endl;
}

int recursion_count = 0;
void insertionSortRecursive(int arr[], int n) {
    recursion_count++;
    if (n <= 1)
        return;

    insertionSortRecursive(arr, n - 1);

    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}


int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    insertionSortRecursive(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;


    cout << "Number of recursive calls: " << recursion_count << endl;
    cout <<"name - dev , roll no - 2401730237"<<endl; 

    return 0;
}