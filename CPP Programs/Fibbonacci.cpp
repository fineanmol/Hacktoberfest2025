// Filename: fibonacci.cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 0;
    }

    long long first = 0, second = 1;
    cout << "Fibonacci sequence: ";

    for (int i = 1; i <= n; i++) {
        cout << first << " ";
        long long next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
    return 0;
}
