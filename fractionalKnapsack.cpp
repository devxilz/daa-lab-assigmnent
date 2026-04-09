#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double value, weight;
};

// Comparator: sort by value/weight ratio descending
bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(double capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto& item : items) {
        if (capacity == 0) break;

        if (item.weight <= capacity) {
            // Take the whole item
            totalValue += item.value;
            capacity   -= item.weight;
        } else {
            // Take a fraction
            double fraction = capacity / item.weight;
            totalValue += item.value * fraction;
            capacity = 0;
        }
    }
    return totalValue;
}

int main() {
    double capacity = 50;
    vector<Item> items = {{60,10}, {100,20}, {120,30}};

    cout << "Max value: " << fractionalKnapsack(capacity, items) << endl;
    // Output: Max value: 240
    return 0;
}