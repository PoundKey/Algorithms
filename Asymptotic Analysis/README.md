## Asymptotic Analysis
#### Proof by...
- __Counterexample__
	- show an example which does not fit with the theorem
	- Thus, the theorem is false.
- __Contradiction__
	- assume the opposite of the theorem
	- derive a contradiction
	- Thus, the theorem is true.
- __Induction__
	- prove for a base case (eg. n = 1)
	- assume for all n <= k (for arbitrary k)
	- prove for the next value (n = k + 1)
	- Thus, the theorem is true

- - -

### Induction (Format)
- Prove: 1 + 2 + 3 + ... + n = n(n+1)/2
- Step before: Identify the variable (eg. var is __n__ in this case)
- Base case: n = 1, 1 = 1
- Induction hypothesis: Assume true for n=k, 1+2+3+...+k = k(k+1)/2, show that it's true for n=k+1
- Induction steps: ...
- This concludes our inductive proof. Therefore 1 + 2 + 3 + ... + n = n(n+1)/2

QED

### Induction Example
Suppose you begin with a pile of n stones, and split this pile into n piles of one stone each by successively splitting a pile of stones into two smaller piles. Each time you split a pile you multiply the number of stones in each of the two smaller piles you form, so that if these piles have r and s stones in them, respectively, you compute r x s. Show that no matter how you split the pile, the sum of the products computed at each step equals n(n-1)/2. Here is an example that shows how the computation proceeds:

![Induction](img/tree.jpg)

The sum is 21+2+12+1+3+2+2+1+1 = 45, which is indeed 10 * 9 / 2

#### Proof By Induction
- Base case: n=1, Sum = 0
- Inductive Hypothesis: Let n=k, for all n=s that is smaller than k, it's true that the sum equals to s(s-1)/2
- inductive Steps: 
	- Let's split k into two piles, one contains x piles and another contains (k-x) piles
	- The sum of the two sub-piles: x(x-1)/2 + (k-x)(k-x-1)/2 + x(k-x) = k(k-1)/2
	- This concludes our inductive proof. Therefore for n stones, the sum is n(n-1)/2

- - -

### Analysis of Algorithms
- How long the program runs (Time complexity) and how much memory it uses (Space complexity)
- Input size n (a non-negative integer, sometimes multiple measure)
- Example of running time:
	- T(n) =  4n + 5
	- T(n) = 0.5nlog(n) - 2n + 7
	- T(n) = 2<sup>n</sup> + n<sup>3</sup> + 3n

![Rate of Growth](./img/rate.png)

- - -

### Big-O Notation
![Big O](./img/bigo.png)

#### Big-Omega and Big-Theta Notation
![Big Omega Theta](./img/bigt.png)

#### Little-Omega and Little-Theta Notation
![Little Omega Theta](./img/smallo.png)

#### Limits and Asymptotic Notation
![Limits and Asymptotic Notation](./img/lim.png)

__Note__: if f ∈ o(g), then f ∈ O(g), g ∈ ω(f) and g ∈ Ω(f). 

### Asymptotic Notations (Growth Rate)
- If we say that f(n) ∈ O(g(n)), we mean that the rate of growth of f(n) is less than or equal to (≤) the rate of growth of g(n).
- If we say that f(n) ∈ Θ(g(n)), we mean that the rate of growth of f(n) is equal (=) to the rate of growth of g(n).
- If we say that f(n) ∈ Ω(g(n)), we mean that the rate of growth of f(n) is greater than or equal to (≥) the rate of growth of g(n).
- If we say that f(n) ∈ o(g(n)), f(n) is in little-o of g(n), and we mean that f(n) grows strictly slower than g(n). This is analogous to using < to compare two functions.
- If we say that f(n) ∈ ω(g(n)), f(n) is in little-omega of g(n), and we mean that f(n) grows strictly faster than g(n). This is analogous to using > to compare two functions.

### L’Hospital’s Rule
![L’Hospital’s Rule](./img/lhrule.png)

### Typical Asymptotics
![Typical Asymptotics](./img/type.png)

#### Sample Asymptotic Relations
![Typical Asymptotics](./img/rel.png)

#### Runtime Example:
```python
	i = 1
	while i < n:
		for j = 1 to i:
			sum = sum + 1
		i += i
```
- For each 'while loop', the inner 'for loop' gets runned for i times
- i = 1, 2, 4, 8, 16...
- Hence in total, T(n) = 1 + 2 + 4 + 8 + 16...  => Sum(2^k) [k=0, ceil(__lg(n)__)-1]
- Formula that should be implanted as a computer scientiest:
- __Sum(2^k) [k=0, n] = 2^(n+1) - 1__
- Hence, T(n) = 2^ceil(lg(n)) - 1 <= 2^(lg(n)+1) - 1 <= 2n - 1
- Therefore, T(n) ∈ Θ(n)

- - -

### Arithmetic Sequences
Find value at term __n__, given initial term = __a__, and diff = __d__:

![Arithmetic Sequences](./img/arith.png)

Summation of Arithmetic Sequences:

![Arithmetic Sequences Sum](./img/asum.png)

### Geometric Sequences
Find value at term __n__, given initial term = __a__, and common ratio = __r__:

![Geometric Sequences](./img/geo.png)

Summation of Geometric Sequences:

![Geometric Sequences Sum](./img/geosum.png)

Special case when abs(r) < 1:

![Geometric Sequences Sum](./img/geosum2.png)

- - -

### [Summation of 2 to the power of n](http://math.stackexchange.com/questions/22599/how-do-i-prove-this-by-induction-sum-of-powers-of-2)
Prove that for every natural number __n__,

![2 to the power of n Sum](./img/2power.png)

### Solving Recurrence

#### Substitution:
![Recurrence](./img/recur.png)

__Mergesort__:

![Recurrence Mergesort](./img/merge.png)

__Note__:

- To avoid recursive calls:
  - store base case values in a table
	- before calculating the value for n
		- check if the value for n is in the table
		- if so, return it
		- if not, calculate it and store it in the table
- This strategy is called memoization and is closely related to __dynamic programming__.
- Generally, dynamic programming takes Θ(n)

__Tail Recursion__: <br>
In traditional recursion, the typical model is that you perform your recursive calls first, and then you take the return value of the recursive call and calculate the result.
In tail recursion, you perform your calculations first, and then you execute the recursive call, passing the results of your current step to the next recursive step. <br>

```python
# Normal recursion
def recsum(x):
 if x == 1:
  return x
 else:
  return x + recsum(x - 1)


"""
# Python interpreter would evaluate.
recsum(5)
5 + recsum(4)
5 + (4 + recsum(3))
5 + (4 + (3 + recsum(2)))
5 + (4 + (3 + (2 + recsum(1))))
5 + (4 + (3 + (2 + 1)))
15

"""

# Tail recursion
def tailrecsum(x, running_total=0):
  if x == 0:
    return running_total
  else:
    return tailrecsum(x - 1, running_total + x)


"""
# Python interpreter would evaluate.
tailrecsum(5, 0)
tailrecsum(4, 5)
tailrecsum(3, 9)
tailrecsum(2, 12)
tailrecsum(1, 14)
tailrecsum(0, 15)
15

"""

```

__Eliminating Tail Recursion__: <br>

```c
// Search A[i..j] for key (Binary Search)
// init: i=0, j=length(A)-1
// Return index of key or -1 if key not found.

int bSearch(int A[], int key, int i, int j) {
	if (j < i) return -1;
	int mid = (i + j) / 2;
	if (key < A[mid])
		return bSearch(A, key, i, mid-1);
	if (key > A[mid])
		return bSearch(A, key, i, mid+1);
	else
		return mid;
}

// To eliminate tail recursion, the key is to store the local variables
// bSearch without tail recursion

int bSearch(int A[], int key, int i, int j) {
	while ( j >= i) {
		int mid = (i + j) / 2;
		if (key < A[mid])
			j = mid - 1;
		else if (key > A[mid])
			i = mid + 1;
		else
			return mid;
	}
	return -1;
}

```

__Another Runtime Example:__ <br>
Find a tight bound on T(n) = lg(n!) <br>
Solution: Θ(nlog(n))

### Solving Common Recurrences
- Linear search
	- T(1) = b
	- T(n) = c + T(n-1)
	- T(n) = O(n)
- Quicksort
	- T(1) = b
	- T(n) = c·n + T(n-1)
	- T(n) = O(n<sup>2</sup>)
- Binary Search
	- T(1) = b
	- T(n) = c + T(n/2)
	- T(n) = O(lg(n))	
- Example 4
	- T(1) = b
	- T(n) = c·n + T(n/2)
	- T(n) = O(n)	
- Example 5
	- T(1) = b
	- T(n) = c + k·T(n/k)
	- T(n) = O(n)	
- Mergesort
	- T(1) = b
	- T(n) = c·n + 2T(n/2)
	- T(n) = O(nlg(n))
- Example 7
	- T(1) = b
	- T(n) = c·n + k·T(n/k)
	- T(n) = O(nlg(n))
- Fibonacci
	- T(1) = a
	- T(2) = b
	- T(n) = T(n-1) + T(n-2) + c
	- T(n) = O(2<sup>n</sup>)


#### Problem that cannot be expressed using asymptotic notations
Consider the following functions:

- f(n) = 1 if n is odd; f(n) = n if n is even.
- g(n) = n if n is odd; g(n) = 1 if n is even.

Such non-monotonic functions exist in applications such as prime number checking. The graphs of these functions look like upside-down Vs which expand as n increases. We cannot say that f(n) ∈ O(g(n)) because this would fail for even-valued n. Likewise, we cannot say that f(n) ∈ Ω(g(n)) because this would fail for odd valued n.

### Log Aside
![Log Aside](./img/log.png)


