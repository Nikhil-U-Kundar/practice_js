#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& A) {
    int n = A.size();
    if (n == 0) return 0;

    vector<int> left(n, 1);  // Initialize left array with 1s

    // Fill the left array (left to right pass)
    for (int i = 1; i < n; i++) {
        if (A[i] > A[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }

    // Right to left pass and compute the total candies
    int right = 1;
    int sum = left[n - 1];  // Start with the last element in left array
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] > A[i + 1]) {
            right++;
        } else {
            right = 1;
        }
        sum += max(left[i], right);  // Take the maximum of left[i] and right
    }

    return sum;
}

int main() {
    vector<int> ratings = {1,2,6,5,4,3,1};
    cout << "Total candies required: " << candy(ratings) << endl;
    return 0;
}
