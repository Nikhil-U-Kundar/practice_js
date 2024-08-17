#include <iostream>
#define MAX_INT 500  // Maximum number of digits in the result

// Function to multiply a number with the factorial result so far
int multiply(int size, int res[], int n) {
    int carry = 0;

    // Multiply n with the current factorial result
    for (int x = 0; x < size; x++) {
        int product = res[x] * n + carry;
        res[x] = product % 10;  // Store last digit of 'product' in res
        carry = product / 10;    // Put the rest in carry
    }

    // Put the carry in res and increase the size
    while (carry) {
        res[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}

// Function to calculate factorial
void factorial(int n) {
    int res[MAX_INT];
    
    // Initialize the result with 1 (factorial of 0 and 1 is 1)
    res[0] = 1;
    int size = 1;

    // Apply the multiply function for every number from 2 to n
    for (int i = 2; i <= n; i++) {
        size = multiply(size, res, i);
    }

    // Print the factorial result in reverse order
    std::cout << "Factorial of " << n << " is: ";
    for (int i = size - 1; i >= 0; i--) {
        std::cout << res[i];
    }
    std::cout << std::endl;
}

int main() {
    int n = 10;  // Example to calculate factorial of 10
    factorial(n);
    return 0;
}
