#include<iostream>
using  namespace std;
int recursion_count;
void bubbleSort(int arr[], int n) {
    recursion_count++;
    if (n == 1)
        return;

    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);

    bubbleSort(arr, n-1);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\nNumber of recursive calls: " << recursion_count << endl;
    cout <<"name - dev , roll no - 2401730237"<<endl;
    return 0;
}