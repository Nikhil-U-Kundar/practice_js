#include <iostream>
using namespace std;

// Function to reverse the words in a string
string reverseastring(string s) {
    string result;
    int i = 0;
    int n = s.length();
    
    while (i < n) {
        // Skip spaces
        while (i < n && s[i] == ' ') i++;
        if (i >= n) break;

        int j = i + 1;

        // Find the end of the current word
        while (j < n && s[j] != ' ') j++;

        // Extract the word
        string sub = s.substr(i, j - i);

        // If result is empty, just assign the substring
        if (result.empty()) {
            result = sub;
        } else {
            // Otherwise, add the substring to the front
            result = sub + " " + result;
        }

        // Move i to the start of the next word
        i = j + 1;
    }

    return result;
}

int main() {
    string s = "Nikhil kulal";
    string output = reverseastring(s);
    cout << output << " ";
    return 0;
}
