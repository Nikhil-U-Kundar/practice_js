#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sortedArray(vector<int>& ans, int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (ans[mid] == 0) {
            swap(ans[low], ans[mid]);
            mid++;
            low++;
        } else if (ans[mid] == 1) {
            mid++;
        } else {
            swap(ans[mid], ans[high]);
            high--;
        }
    }
    return ans;
}

int main() {
    vector<int> array = {1, 2, 0, 0, 2, 1, 0};
    int n = array.size();
    vector<int> answer = sortedArray(array, n);
    
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}
