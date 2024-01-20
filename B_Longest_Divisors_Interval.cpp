#include <bits/stdc++.h>
using namespace std;
//HasahMap for memoization
map<int, int>mp;
int fibonacci(int n) {
    // Base case: The first two Fibonacci numbers are 0 and 1.
    if(mp[n]!=0)return mp[n];
    if (n <2)
        return n;
    // Recursive case: Calculate the n-th Fibonacci number by calling the function with (n-1) and (n-2).
    return mp[n]=fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    return 0;
}
