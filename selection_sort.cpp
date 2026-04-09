#include <iostream>
#include <vector>
using namespace std;

long long recursion_count = 0;

long long selection_sort(vector<int>& arr) {
    long long step_count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            step_count++;  // counting comparisons
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(arr[i], arr[min_idx]);
    }

    return step_count;
}

void selection_sort_recursive(vector<int>& arr, int n, int index = 0) {
    recursion_count++;

    if (index == n)
        return;

    int min_idx = index;

    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }

    swap(arr[index], arr[min_idx]);

    selection_sort_recursive(arr, n, index + 1);
}


int main() {
    vector<int> arr1 = {64, 25, 12, 22, 11};

    long long steps = selection_sort(arr1);

    cout << "Sorted array (Iterative): ";
    for (int num : arr1)
        cout << num << " ";

    cout << "\nStep count (comparisons): " << steps << endl;

    vector<int> arr2 = {64, 25, 12, 22, 11};

    selection_sort_recursive(arr2, arr2.size());

    cout << "\nSorted array (Recursive): ";
    for (int num : arr2)
        cout << num << " ";

    cout << "\nRecursion iteration count: " << recursion_count << endl;

    return 0;
}
