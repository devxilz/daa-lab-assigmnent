#include <iostream>
#include <vector>
using namespace std;

long long recursion_count = 0;

// Merge function
long long merge(vector<int>& arr, int left, int mid, int right) {
    long long step_count = 0;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        step_count++;   // counting comparison
        if (L[i] < R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return step_count;
}

// Merge Sort with step counting
long long merge_sort(vector<int>& arr, int left, int right) {
    long long step_count = 0;

    recursion_count++;   // counting recursion calls

    if (left < right) {
        int mid = left + (right - left) / 2;

        step_count += merge_sort(arr, left, mid);
        step_count += merge_sort(arr, mid + 1, right);
        step_count += merge(arr, left, mid, right);
    }

    return step_count;
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    long long steps = merge_sort(arr, 0, arr.size() - 1);

    cout << "Sorted array is: ";
    for (int num : arr)
        cout << num << " ";

    cout << "\nStep count (comparisons): " << steps;
    cout << "\nRecursion iteration count: " << recursion_count << endl;
    cout <<"name - dev , roll no - 2401730237"<<endl; 
    return 0;
}
