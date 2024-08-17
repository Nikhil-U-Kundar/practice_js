#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Returns maximum profit with two transactions on a given
// list of stock prices, price[0..n-1]
int maxProfit(const vector<int>& price) {
    int n = price.size();
    if (n == 0) return 0;

    // Array to store the maximum profit by doing one transaction
    // from day 0 to day i
    vector<int> profit(n, 0);

    int max_price = price[n - 1];
    
    // Fill the profit array with maximum profit for one transaction
    for (int i = n - 2; i >= 0; i--) {
        max_price = max(max_price, price[i]);
        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    int min_price = price[0];
    
    // Update the profit array with maximum profit for two transactions
    for (int i = 1; i < n; i++) {
        min_price = min(min_price, price[i]);
        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
    }

    // The last entry in profit[] will have the result
    return profit[n - 1];
}

// Driver code
int main() {
    vector<int> price = {2, 30, 15, 10, 8, 25, 80};
    cout << "Maximum Profit = " << maxProfit(price) << endl;
    return 0;
}
