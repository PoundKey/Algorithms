#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int array[], int len) {
	cout<< "[ ";
	for (int i=0; i<len; i++) {
		cout << array[i] << ", ";
	}
	cout << "]" << endl;
}

void bubbleSort(int array[], int len) {
	for (int j=len-1; j>0; j--) {
		int i = 0;
		while (i < j) {
			if (array[i] > array[i+1]) {
				swap(array[i], array[i+1]);
			}
			i++;
		}
	}
}

void insertionSort(int array[], int len) {
	
	for (int i=1; i<len; i++) {
		int j = i;
		while(array[j] < array[j-1] && j>0) {
			swap(array[j], array[j-1]);
			j--;
		}
	}
	
}

void selectionSort(int array[], int len) {
	
	for (int i=0; i<len-1; i++) {
		int min = i;
		int j = i+1;
		while (j < len) {
			if (array[min] > array[j]) {
				min = j;
			}
			j++;
		}
		if (min != i) {
			swap(array[i], array[min]);
		}
	}
	
}

void merge(int array[], int lo, int mid, int hi, int temp[]) {
	int a = lo;
	int b = mid+1;
	
	for (int i=lo; i<=hi; i++) {
		if (a <= mid && (b > hi || array[a] < array[b])) {
			temp[i] = array[a++];
		} else {
			temp[i] = array[b++];
		}
	}
	
	for (int j=lo; j<=hi; j++) {
		array[j] = temp[j];
	}
}

void msort(int array[], int lo, int hi, int temp[]) {
	if (lo >= hi) return;
	int mid = (lo + hi)/2;
	msort(array, lo, mid, temp);
	msort(array, mid+1, hi, temp);
	merge(array, lo, mid, hi, temp);
}


void mergesort(int array[], int n) {
	int *temp = new int[n];
	msort(array, 0, n-1, temp);
	delete[] temp;	
}
int main(int argc, char *argv[]) {
	int arr[] = {5, 3, 9, 21, 10, 2};
	printArray(arr, 6);
	//insertionSort(arr, 6);
	//bubbleSort(arr, 6);
	//selectionSort(arr, 6);
	mergesort(arr, 6);
	printArray(arr, 6);
}