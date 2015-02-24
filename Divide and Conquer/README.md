# Divide and Conquer
### Introduction

### Master Theorem
![Divide and Conquer](img/master.png)

### Randomized-Select / QuickSelect.
 Finding the kth smallest element in an unsorted array.

- QuickSelect: Given array A of size n and integer k ≤ n,
	- Pick a pivot element p at random from A.
	- Split A into subarrays LESS and GREATER by comparing each element to p as in
Quicksort. While we are at it, count the number L of elements going in to LESS.
	- (a) If L = k−1,then output p.  
	   (b) If L > k − 1, output QuickSelect(LESS, k).  
		 (c) If L < k − 1, output QuickSelect(GREATER, k − L − 1)  

The expected number of comparisons for QuickSelect is O(n).

__Runtime__: T(n) ∈ Θ(n)

### Deterministic Select
- DeterministicSelect: Given array A of size n and integer k ≤ n,
	- Group the array into n/5 groups of size 5 and find the median of each group.
	- Recursively, find the true median of the medians. Call this p.
	- Use p as a pivot to split the array into subarrays LESS and GREATER.
	- Recurse on the appropriate piece.

DeterministicSelect makes O(n) comparisons to find the kth smallest in an array of size n.

__Runtime__: T(n) ∈ Θ(n)