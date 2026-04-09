#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> knapsack01(int capacity,
                                   vector<int>& weights,
                                   vector<int>& values) {
    int n = weights.size();
    // dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i-1][w];   // don't take item i
            if (weights[i-1] <= w) {
                int take = dp[i-1][w - weights[i-1]] + values[i-1];
                dp[i][w] = max(dp[i][w], take);
            }
        }
    }

    // Backtrack to find selected items
    vector<int> selected;
    int w = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected.push_back(i-1);  // 0-based index
            w -= weights[i-1];
        }
    }
    reverse(selected.begin(), selected.end());
    return {dp[n][capacity], selected};
}

int main() {
    int capacity = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values  = {60, 100, 120};

    auto [maxVal, items] = knapsack01(capacity, weights, values);
    cout << "Max value: " << maxVal << endl;
    cout << "Items (0-based): ";
    for (int i : items) cout << i << " ";
    cout << endl;
    // Output: Max value: 220
    //         Items: 1 2
    cout<<"name - dev , roll no - 2401730237"<<endl;
    return 0;
}