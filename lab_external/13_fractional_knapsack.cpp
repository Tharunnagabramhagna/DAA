// 13. Greedy Approach: Implementation of Fractional Knapsack

// Algorithm
// 1. Start.
// 2. Read the number of items and knapsack capacity.
// 3. Read the profit and weight of each item.
// 4. Calculate the profit-to-weight ratio for each item.
// 5. Sort the items in descending order of their ratio.
// 6. Select items with the highest ratio first.
// 7. If the complete item fits, take it; otherwise, take the required fraction.
// 8. Calculate the total profit.
// 9. Display the maximum profit.
// 10. Stop.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item
{
public:
    int weight;
    int value;
    Item(int w, int v)
    {
        weight = w;
        value = v;
    }

    double valuePerWt() const
    {
        return (double)value / weight;
    }
};

class MaxProfit
{
    vector<Item> items;
    int capacity;

public:
    MaxProfit(int c)
    {
        capacity = c;
    }

    void addItems(int wt, int val)
    {
        items.push_back(Item(wt, val));
    }

    // Main Logic
    double maxProfit()
    { // O(n log n)
        // Step-1 : Sort the items in descending order of their ratioes
        sort(items.begin(), items.end(), [](const Item &a, const Item &b)
             {
                 return a.valuePerWt() > b.valuePerWt(); // a > b --> descending
             });

        // Step-2 : Initialize the totalProfit and remaining capacity
        double totalProfit = 0.0;
        int remCap = capacity;

        for (auto &item : items)
        {
            if (item.weight <= remCap)
            {
                totalProfit += item.value;
                remCap -= item.weight;
            }
            else
            { // if wt is greater than capacity --> fractional part
                totalProfit += item.valuePerWt() * remCap;
                break; // Knapsack is Full
            }
        }

        return totalProfit; // Final Result
    }
};

int main()
{
    int capacity;

    cout << "Enter the required capacity : ";
    cin >> capacity;

    MaxProfit mp(capacity);

    int wt, val;

    for (int i = 0; i < capacity; i++)
    {
        cout << "Enter the weight and value of item-" << i + 1 << " : ";
        cin >> wt >> val;
        mp.addItems(wt, val);
    }

    cout << "\nMax-Profit of the Items (Fractional Knapsack) : " << mp.maxProfit() << endl;

    return 0;
}