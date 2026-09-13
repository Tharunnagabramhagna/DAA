/* 4Q) Greedy Approach: Implementation of Fractional Knapsack */

// Ans)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    int weight;
    int value;

    Item(int w, int v) {
        weight = w;
        value = v;
    }

    double valuePerWeight() const {
        return (double)value / weight;
    }
};

class FractionalKnapsack {
private:
    vector<Item> items;
    int capacity;

public:
    FractionalKnapsack(int cap) {
        capacity = cap;
    }

    void addItem(int weight, int value) {
        items.push_back(Item(weight, value));
    }

    double getMaxValue() {
        // Sort items by value/weight ratio (descending)
        sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
            return a.valuePerWeight() > b.valuePerWeight();
        });

        double totalValue = 0.0;
        int remainingCapacity = capacity;

        for (auto &item : items) {
            if (item.weight <= remainingCapacity) {
                // Take whole item
                totalValue += item.value;
                remainingCapacity -= item.weight;
            } else {
                // Take fraction of item
                totalValue += item.valuePerWeight() * remainingCapacity;
                break; // Knapsack is full
            }
        }
        return totalValue;
    }
};

int main() {
    FractionalKnapsack knapsack(50); // capacity = 50

    // Add items (weight, value)
    knapsack.addItem(10, 60);
    knapsack.addItem(20, 100);
    knapsack.addItem(30, 120);

    cout << "Maximum value in Knapsack = " << knapsack.getMaxValue() << endl;

    return 0;
}
