#include <iostream>
#include <vector>
#include <string>
using namespace std;

// The Fibonacci Sequence is the series of numbers: 
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... The next number
// is found by adding up the two numbers before it. 
int fibReg(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return fibReg(n - 1) + fibReg(n - 2);
}

// Implementation with memorization:
// allocate array for memo; set all elements of memo to zero;
// if n is 1 or 2, return 1;
// if memo[n] is not zero, return memo[n];
// memo[n] = fib(n-1) + fib(n-2);
// return memo[n];

int fibMem(int n) {
	if (n == 0) return 0;
	vector<int> memo(n, 0);
	return fibHelper(n, memo);
}

int fibHelper(int n, vector<int>& memo) {
	if (n == 1 || n == 2) return 1;
	if (memo[n] != 0) return memo[n];
	memo[n] = fibHelper(n - 1) + fibHelper(n - 2);
	return memo[n];
}