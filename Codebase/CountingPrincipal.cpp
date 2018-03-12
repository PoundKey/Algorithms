// focusing on the basic counter principal: permutation and combination
// both can be implemented using classic backtracking template
// this the bottom line to solve complex problems, ofen leads to runtime 
// O(2^n) for combination and O(n!) for permutation, which is also known as NP-Complete problems

// some interesting formulas found while doing the practice:
// SUM( n Choose r) for r = 0 to n  == 2^n
// SUM( n Permute r) for r = 0 to n == e * n! when n and r become larger
// frankly, this is the first time that I 'found' the magical irrational number e

// CountingPrincipal.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

char A[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

static int counter = 0;

static int permuteCounter = 0;

template <class T>
void PrintArray(const T& in_container)
{
	cout << "[";
	for (const auto& val : in_container)
	{
		cout << val << " ";
	}
	cout << "]" << endl;
}

void Substring(char A[], int n)
{
	// substring combination
	for (int i = 0; i < n; i++)
	{
		string str = "";
		for (int j = i; j < n; j++)
		{
			str += A[j];
			cout << "A[" << i << ", " << j << "] = " << str << endl;
		}
	}
}

int64_t Factorial(int n, int end)
{
	if (end == 0) return 1;
	return n * Factorial(n - 1, end - 1);
}

int64_t PermuteFactorial(int n)
{
	int64_t sum = 0;
	for (int i = n; i >= 0; i--)
	{
		sum += Factorial(n, i);
	}
	cout << "Permutation Sum: " << sum << endl;
	return sum;
}

void PermuteFactorialRatio(int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "i = " << i << ": ";
		double sum = PermuteFactorial(i);
		cout << " >> Total: " << sum;
		double fac = Factorial(i, i);
		double ratio = sum / fac;
		cout << " >> Fab: " << fac;
		printf(" Ratio: %.12f \n", ratio);
	}
}

extern void PermuteHelper(const string& str, string res, vector<bool>& visited);
void Permute(const string& str)
{
	if (str.empty()) return;
	vector<bool> visited(str.size(), false);
	PermuteHelper(str, "", visited);
}

void PermuteHelper(const string& str, string res, vector<bool>& visited)
{
	cout << res << " | ";
	++permuteCounter;
	if (res.size() == str.size()) return;

	for (int i = 0; i < str.size(); i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		PermuteHelper(str, res + str[i], visited);
		visited[i] = false;
	}
}

int CombinationRecursion(int n, int k)
{
	if (k < 0 || k > n) return 0;
	if (k == 1) return n;
	if (k == n) return 1;
	return CombinationRecursion(n - 1, k - 1) + CombinationRecursion(n - 1, k);
}

extern void CombinationHelper(const vector<int>& v, vector<int>& temp, int pos);

// clearly, backtracking can do the job
void Combination(const vector<int>& v)
{
	if (v.empty()) return;
	vector<int> temp;
	CombinationHelper(v, temp, 0);
}

void CombinationHelper(const vector<int>& v, vector<int>& temp, int pos)
{
	PrintArray(temp);
	counter++;
	if (pos >= v.size()) return;

	for (int i = pos; i < v.size(); i++)
	{
		temp.push_back(v[i]);
		CombinationHelper(v, temp, i + 1);
		temp.pop_back();
	}
}

extern void CombinationStringHelper(const string& str, string res, int pos);

void CombinationString(const string& str)
{
	if (str.empty()) return;
	CombinationStringHelper(str, "", 0);
}

void CombinationStringHelper(const string& str, string res, int pos)
{
	cout << res << " | ";
	if (pos >= str.size()) return;
	for (int i = pos; i < str.size(); i++)
	{
		CombinationStringHelper(str, res + str[i], i + 1);
	}
}

int CombinationDP(int n, int k)
{
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j == 1)
			{
				dp[i][j] = i;
			}
			else if (j > i)
			{
				dp[i][j] = 0;
			}
			else if (j == i)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}
	return dp[n][k];
}

void TestCombination(int n, int k)
{
	cout << "CombinationDP: " << "C(" << n << ", " << k << ") = " << CombinationDP(n, k) << endl;
	cout << "CombinationRecursion: " << "C(" << n << ", " << k << ") = " << CombinationDP(n, k) << endl;
}

int main()
{
	cout << "Hello World, Hello Bloomberg!" << endl;
	
	const int n = sizeof(A) / sizeof(char);
	bool visited[n] = { false };
	Substring(A, n);
	
	cout << "<<<============== Combination =============>>>" << endl;
	int n1 = 10, n2 = 6;
	TestCombination(n1, n2);
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7};
	//PrintArray(v1);
	Combination(v1);
	CombinationString("abcde");
	cout << endl;
	cout << "<<<============== Permutation =============>>>" << endl;
	//PermuteFactorialRatio(20);
	Permute("abc");
	cout << "Permute Counter: " << permuteCounter << " = ";
	PermuteFactorial(3);
	return 0;
}

