# Sorting

### Measure Sorting Algorithms
- Computational __complexity__ (eg. Runtime)
	- Worst case, Average case, Best case
- __Stability__: What happens to elements with identical keys?
- __Memory Usage__: How much extra memory is used

### Bubble sort
>__Definition__: Repeatedly steps through the list to be sorted, compares each pair of adjacent items and swaps them if they are in the wrong order. The largest number bubbles up to the end of the array in each outter iteration.

![Bubble sort](./img/bubble.gif)
```python
for i=(n-1) to 1
	for j=0 to (i-1)
		if A[j] < A[j+1]
			swap(A[j], A[j+1])
```
__Runtime__: О(n<sup>2</sup>) Comparsions

### Selection sort
>__Definition__: 

```python
```
__Runtime__: О(n<sup>2</sup>) Comparsions  
__Stability__: Very stable  
__Memory__: 

### Insertion sort
>__Definition__: At the start of iteration i, the first i elements in the array are sorted, and we insert the (i+1)st element into its proper place. Insertion sort takes advantage of presorting, it only requires one comparsion per element for a presorted list.

![Insertion sort](./img/insertion.gif)
```python
for (i=1 to n-1)
	j = i 
	while (j > 0 and A[j] < A[j-1])
		swap(A[j], A[j-1])
		j--
```
__Runtime__: О(n<sup>2</sup>) Comparsions  
__Stability__: Very stable  
__Memory__: Sorting is done in-place, a constant number of extra memory locations are used.

### Heapsort (1964)
>__Definition__: Divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the smallest element and moving that to the sorted region

- Heapify input array
- Repeat n times: Perform deleteMin/Max

__Runtime__: О(n<sup>2</sup>) Comparsions  
__Stability__: Not stable, use index in input array to break down comparison ties. 
__Memory__: in-place. (Avoid using another array to store the result)

### Mergesort
>__Definition__: 

```cpp
void mergesort(int x[], int n) {
	int *tmp = new int[n];
	msort(x, 0, n-1, tmp);
	delete[] tmp;
}

void msort(int x[], int lo, int hi, int tmp[]) {
	if (lo >= hi) return;
	int mid = (lo+hi)/2;
	msort(x, lo, mid, tmp);
	msort(x, mid+1, hi, tmp);
	merge(x, lo, mid, hi, tmp);
}

void merge(int x[], int lo, int mid, int hi, int tmp[]) {
	int a=lo, b=mid+1;
	for (int k=lo; k<=hi; k++) {
		if (a <= mid && (b > hi || x[a] < x[b]))
			tmp[k] = x[b++];
		else 
			tmp[k] = x[b++];
	}
	for (int k=lo; k<=hi; k++)
		x[k] = tmp[k];
}

```
![Merge sort](./img/mergesort.png)

### Quicksort
__Definition__: A divide and conquer algorithm

- If the array has 0 or 1 element, it's sorted, stop. __T(n) = 1__
- Split the array into two approximately equal-sized halves.
- Sort each half recursively (using Mergesort). __2T(n/2)__
- Merge the sorted halves to produce one sorted result. __n__

```python
```
__Runtime__: О(n<sup>2</sup>) Comparsions  
__Stability__: Very stable  
__Memory__: 
