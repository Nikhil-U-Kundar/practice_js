#include <iostream>
#include <algorithm>
using namespace std;

int minJump(int arr[], int n) {
    if (n <= 1) {
        return 0;  // No jumps needed if the array has one or no elements
    }

    if (arr[0] == 0) {
        return -1;  // Can't move anywhere if the first element is 0
    }

    int maxReach = arr[0];  // The maximum index we can currently reach
    int step = arr[0];      // The number of steps we can still take
    int jump = 1;           // Number of jumps needed to reach maxReach

    for (int i = 1; i < n; i++) {
        if (i == n - 1) {
            return jump;  // We have reached the last element
        }

        maxReach = max(maxReach, i + arr[i]);  // Update maxReach if possible
        step--;  // We use a step to get to the current index

        if (step == 0) {
            jump++;  // We must have used a jump

            if (i >= maxReach) {
                return -1;  // If we can't move further from this point
            }

            step = maxReach - i;  // Reinitialize the steps to the new maxReach
        }
    }

    return -1;  // If we exit the loop without reaching the last element
}

int main() {
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = minJump(arr, n);
    if (result == -1) {
        cout << "It's not possible to reach the end of the array." << endl;
    } else {
        cout << "Minimum number of jumps to reach the end is: " << result << endl;
    }

    return 0;
}
