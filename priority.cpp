#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;  // Read the size of the array
        vector<int> arr(n);  // Initialize vector of size n
        for(int i = 0; i < n; i++) {
            cin >> arr[i];  // Read the elements of the array
        }
        int k;
        cin >> k;  // Read the value of k

        priority_queue<int,vector<int>,greater<int>> p;  // Max-heap

        for(int i = 0; i < n; i++) {
            p.push(arr[i]);  // Push elements into the priority queue
        }

        int ans = 0;
        for(int i = 1; i <= k; i++) {
            ans = p.top();  // Get the top element (largest)
            p.pop();  // Remove the top element
        }


        cout << ans << endl;  // Output the k-th largest element
    }
    return 0;
}
