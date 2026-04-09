#include <iostream>
#include <vector>
using namespace std;

long long recursion_count = 0;

// ------------------ Iterative Linear Search ------------------

pair<int, long long> linear_search(vector<int>& arr, int x) {
    long long step_count = 0;

    for (int i = 0; i < arr.size(); i++) {
        step_count++;  // counting comparison
        if (arr[i] == x) {
            return {i, step_count};
        }
    }

    return {-1, step_count};
}

// ------------------ Recursive Linear Search ------------------

int linear_search_recursive(vector<int>& arr, int x, int index = 0) {
    recursion_count++;

    if (index >= arr.size())
        return -1;

    if (arr[index] == x)
        return index;

    return linear_search_recursive(arr, x, index + 1);
}

// ------------------ Main ------------------

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int x = 10;

    auto result = linear_search(arr, x);

    if (result.first != -1)
        cout << "Element is present at index " << result.first;
    else
        cout << "Element is not present in array";

    cout << "\nStep count: " << result.second << endl;

    int res = linear_search_recursive(arr, x);

    if (res != -1)
        cout << "\nElement is present at index " << res;
    else
        cout << "\nElement is not present in array";

    cout << "\nRecursion iteration count: " << recursion_count << endl;
    cout <<"name - dev , roll no - 2401730237"<<endl; 

    return 0;
}
