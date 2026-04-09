#include<iostream>
using  namespace std;

void bubbleSort(int arr[], int n) {
    int step_count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
            step_count++;
        }
    }
    cout << "Number of steps taken: " << step_count << endl;
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout <<"name - dev , roll no - 2401730237"<<endl;
    return 0;
}