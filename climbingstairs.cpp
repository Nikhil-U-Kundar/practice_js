#include <iostream>
using namespace std;

int climbingStairs(int n) {
    if (n == 1) return 1; // Base case: if there's only 1 step
    if (n == 2) return 2; // Base case: if there are 2 steps

    // Array to store the number of ways to reach each step
    int dp[n + 1];
    
    // Initialize base cases
    dp[1] = 1;
    dp[2] = 2;

    // Fill the dp array for all steps from 3 to n
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // The answer is the number of ways to reach the nth step
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    
    int result = climbingStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << result << endl;

    return 0;
}
