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


### Examples

