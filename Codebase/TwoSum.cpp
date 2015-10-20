#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
	cout << "[ ";
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << "]" << endl;
}

vector< vector<int> > twoSum(vector<int> num, int target) {
	//@param num: a sorted vector containing int
	vector< vector<int> > sol;
	int start = 0;
	int end = num.size() - 1;
	while (start < end) {
		int sum = num[start] + num[end];
		if (sum == target) {
			vector<int> entry;
			entry.push_back(num[start++]);
			entry.push_back(num[end--]);
			sol.push_back(entry);
			while (num[start] == num[start-1]) start++;
			while (num[end] == num[end+1]) end--;
		} else if (sum < target) {
			start++;
		} else {
			end --;
		}
	}
	for (int i=0; i < sol.size(); i++) {
		printVector(sol[i]);
	}
	return sol;
}
int main(int argc, char *argv[]) {
	int arr[] = {1, 2, 2, 2, 2, 3, 5};
	vector<int> req(arr, arr+7);
	twoSum(req, 4);
}