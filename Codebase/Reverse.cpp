#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print(vector<int>& vec) {
	for (auto &elem : vec) {
		cout << elem << " ";
	}
	cout << endl;
}

void reverse(vector<int>& nums, int start, int end) {
	int val = start + end;
	int n = (val + 1) / 2;
	for (int i = start; i < n; i++) {
		int temp = nums[i];
		int j =  val - i;
		nums[i] = nums[j];
		nums[j] = temp;
	}
	print(nums);
}

void reverse_two_pointers(vector<int>& nums, int start, int end) {
     while (start < end) {
        int temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
     }
     print(nums);
}


int main(int argc, char *argv[]) {
	vector<int> v1;
	int l2[] = {2, 3, 4, 5, 6, 7};
	vector<int> v2(l2, l2+6);
	reverse(v2, 0, 5);
