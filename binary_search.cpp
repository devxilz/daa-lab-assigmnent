#include <iostream>
#include <vector>
using namespace std;

long long recursion_count = 0;


pair<int, long long> binary_search(vector<int>& arr, int low, int high, int x) {
    long long step_count = 0;
    int mid = low + (high - low) / 2;
    while(high >= low) {
        int mid = low + (high - low) / 2;
        step_count++;  // counting comparison
        if (arr[mid] == x)
            return {mid, step_count};
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return {-1, step_count};
}


int binary_search_recursive(vector<int>& arr, int low, int high, int x) {
    recursion_count++;

    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            return binary_search_recursive(arr, low, mid - 1, x);

        else
            return binary_search_recursive(arr, mid + 1, high, x);
    }

    return -1;
}


int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int x = 10;

    auto result = binary_search(arr, 0, arr.size() - 1, x);

    if (result.first != -1)
        cout << "Element is present at index " << result.first;
    else
        cout << "Element is not present in array";

    cout << "\nStep count: " << result.second << endl;

    int res = binary_search_recursive(arr, 0, arr.size() - 1, x);

    if (res != -1)
        cout << "\nElement is present at index " << res;
    else
        cout << "\nElement is not present in array";

    cout << "\nRecursion iteration count: " << recursion_count << endl;
    cout <<"name - dev , roll no - 2401730237"<<endl;

    return 0;
}
