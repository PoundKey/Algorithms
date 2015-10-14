#include <iostream>

using namespace std;

void printList(int *heap, int size) {
	for (int i=0; i < size; i++) {
		cout << heap[i] << ", ";
	}
	cout << endl;
}

void swap(int a,  int b) {
	int temp = a;
	a = b;
	b = temp;
}

void rswap(int &a,  int &b) {
	int temp = a;
	a = b;
	b = temp;
}


int main(int argc, char *argv[]) {
	int list[] = {56, 32, 21, 12, 3};
	printList(list, 5);
	
	rswap(list[0], list[2]);
	printList(list, 5);
}