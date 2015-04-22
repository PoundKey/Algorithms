# NP-Complete

- __Introduction__: (NP-Complete) A problem which is both NP (verifiable in nondeterministic polynomial time) and NP-hard (any NP-problem can be translated into this problem). Examples of NP-hard problems include the Hamiltonian cycle and traveling salesman problems.

- What's NP?
	- NP is the set of all decision problems (question with yes-or-no answer) for which the 'yes'-answers can be verified in polynomial time (O(n^k) where n is the problem size, and k is a constant) by a deterministic Turing machine. Polynomial time is sometimes used as the definition of fast or quickly.
- What is P?
	- P is the set of all decision problems which can be solved in polynomial time by a deterministic Turing machine. Since it can solve in polynomial time, it can also be verified in polynomial time. Therefore P is a subset of NP.
- What is NP-Complete?
	- A problem X is NP-Complete if X is in NP, and
	- For any problem Y in NP, there is a "reduction" from Y to X: a polynomial-time algorithm that transforms any instance of Y into an instance of X such that the answer to the Y-instance is "yes" if and only if the answer X-instance is "yes".
	- If X is NP-complete and a deterministic, polynomial-time algorithm exists that can solve all instances of X correctly, then any problem in NP can be solved in deterministic-polynomial-time (by reduction to X).
	- If __NP = P__, then we can solve very hard problems much faster than we thought we could before. If we solve only one NP-Complete problem in P (polynomial) time, then it can be applied to all other problems in the NP-Complete category.
	- So far, nobody has come up with such a deterministic polynomial-time algorithm, but nobody has proven one doesn't exist. 

- What's NP-hard
	- NP-Hard are problems that are at least as hard as the hardest problems in NP. Note that NP-Complete problems are also NP-hard. However not all NP-hard problems are NP (or even a decision problem), despite having 'NP' as a prefix. That is the NP in NP-hard does not mean 'non-deterministic polynomial time'.

### Formal Definitions
- A __problem__ means something like 3-coloring or network flow, and an __instance__ means a specific instance of that problem: the graph to color, or the network and distinguished nodes s and t we want to find the flow between. 
- A __decision problem__ is just a problem where each instance is either a YES-instance or a NO-instance, and the goal is to decide which type your given instance is. For example, for the Traveling Salesman Problem, an instance consists of a graph G together with an integer k, and the pair (G, k) is a YES-instance iff G has a TSP tour of total length at most k.
- __P__: The class of decision problems Q that have polynomial-time algorithms. Q ∈ P if there exists a polynomial-time algorithm A such that A(I) = YES iff I is a YES-instance of Q.
- __NP__: The class of decision problems where at least the YES-instances have short proofs (that can be checked in polynomial-time). Q ∈ NP if there exists a verifier V (I, X) such that:
	- If I is a YES-instance, then there exists X such that V (I , X ) = YES,
	- If I is a NO-instance, then for all X, V (I,X) = NO,
	- and furthermore the length of X and the running time of V are polynomial in |I|.
- __NP-Complete__: A problem Q is NP-complete if: 
	1. Q ∈ NP, and
	2. Any other Q′ in NP is polynomial-time reducible to Q; that is, Q′ ≤<sub>p</sub> Q.
- If Q just satisfies (2) then it’s called __NP-hard__.

- __Reduction__: A Problem A is poly-time reducible to problem B (written as A ≤<sub>p</sub>  B) if we can solve problem A in polynomial time given a polynomial time black-box algorithm for problem B. Problem A is poly-time equivalent to problem B (A =<sub>p</sub> B) if A ≤<sub>p</sub> B and B ≤<sub>p</sub> A.

### Examples

#### Travelling Salesman Problem
-  “Given a weighted graph G and an integer k, does G have a tour that visits all the vertices and has total length at most k?”
- We may not know how to find such a tour quickly, but if someone gave such a tour to us, we could easily check if it satisfied the desired conditions
- if the answer is YES, then there exists a polynomial-length proof that can be checked in polynomial time — is called NP.

> __Wikipedia__: The travelling salesman problem (TSP) asks the following question: Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city? (NP-Hard Problem)

