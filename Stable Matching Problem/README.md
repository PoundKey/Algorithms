## Stable Matching Problem
### Definitions
__Perfect matching__: So consider a set M = {mx<sub>1</sub>, . . . , mx<sub>n</sub>} of n men, and a set W = {w<sub>1</sub>, . . . , w<sub>n</sub>} of n women. A matching S is a set of ordered pairs, each from M × W, with the property that each member of M and each member of W appears in __at most__ one pair in S. (each man and each woman belong to at most one of the ordered pairs.) A perfect matching S′ is a matching with the property that each member of M and each member of W appears in __exactly one__ pair in S′. (each man and each woman belong to exactly one of the ordered pairs.)

__Instability__: There are two pairs (m,w) and (m′,w′) in S with the property that m prefers w′ to w, and w′ prefers m to m′. We’ll say that such a pair (m, w′) is an instability with respect to S.

__Stability__:  We’ll say that a matching S is stable if (i) it is perfect, and (ii) there is no instability with respect to S.

- - -
### Gale-Shapley algorithm
```python
Initially all m ∈ M and w ∈ W are free
while there is a man m who is free and hasn’t proposed to every woman
Choose such a man m
	Let w be the highest-ranked woman in m’s preference list to whom m has not yet proposed
	if w is free then
		(m, w) become engaged
	else w is currently engaged to m′
		if w prefers m′ to m then m remains free
		else w prefers m to m′ (m, w) become engaged m′ becomes free
Return the set S of engaged pairs
```
__Truth__: Gale-Shapley algorithm returns a stable and perfect matching.

- - -
### Example
```python
m prefers w to w′.
m′ prefers w′ to w.
w prefers m′ to m.
w′ prefers m to m′.
```
This example shows a certain “unfairness” in the G-S algorithm, favoring men. If the men’s preferences mesh perfectly (they all list different women as their first choice), then in all runs of the G-S algorithm all men end up matched with their first choice, independent of the preferences of the women. If the women’s preferences clash completely with the men’s preferences (as was the case in this example), then the resulting stable matching is as bad as possible for the women. So this simple set of preference lists compactly summarizes a world in which someone is destined to end up unhappy: women are unhappy if men propose, and men are unhappy if women propose.

__Question__: Do all executions of the G-S algorithm yield the same matching? <br>
Yes, All Executions Yield the Same Matching

---
__Fact__:
> The G-S algorithm terminates after at most n<sup>2</sup> iterations of the While loop.

__Proof__:

- find a measure of _progress_, in such case, each iteration consists of some man proposing (for the only time) to a woman he has never proposed to before.
- if we let P(t) denote the set of pairs (m, w) such that m has proposed to w by the end of iteration t, we see that for all t, the size of P(t + 1) is strictly greater than the size of P(t).
- But there are only n<sup>2</sup> possible pairs of men and women in total, so the value of P(·) can increase at most n<sup>2</sup> times over the course of the algorithm. It follows that there can be at most n<sup>2</sup> iterations.

QED

__Notes__: _Worse case scenario_: for n pairs, all men have the same preference from {w<sub>1</sub>... w<sub>n</sub>},  whereas all women have the same preference {m<sub>n</sub>... m<sub>1</sub>}. In such as, it takes n(n+1)/2 total matches.

---
__Fact__:
> If m is free at some point in the execution of the algorithm, then there is a woman to whom he has not yet proposed.

__Proof__: By contradiction

- Suppose there comes a point when m is free but has already proposed to every woman.
- Each of the n women is engaged at this point in time. Since the set of engaged pairs forms a matching, there must also be n engaged men at this point in time.
- But there are only n men total, and m is not engaged, so this establishes the contradiction.

QED

---
__Fact__:
> The set S returned at termination is a perfect matching.

__Proof__: By contradiction

- Suppose that the algorithm terminates with a free man m.
- At termination, it must be the case that m had already proposed to every woman, for otherwise the While loop would not have exited.
- This contradicts that there cannot be a free man who has proposed to every woman.

QED

---
__Fact__:
> Consider an execution of the G-S algorithm that returns a set of pairs S. The set S is a stable matching.

__Proof__:

- To prove S is a stable matching, we will assume that there is an instability with respect to S and obtain a contradiction.
- Define the instability: in S with the properties that
	- m prefers w′ to w, and
	- w′ prefers m to m′.
- In the execution of the algorithm that produced S, m’s last proposal was, by definition, to w.
- Did m propose to w′ at some earlier point in this execution?  If he didn’t, then w must occur higher on m’s preference list than w′, contradicting our assumption that m prefers w′ to w.
- If he did, then he was rejected by w′ in favor of some other man m′′, whom w′ prefers to m. m′ is the final partner of w′, so either m′′ = m′ or w′ prefers her final partner m′ to m′′.
- Either way this contradicts our assumption that w′ prefers m to m′.

QED: It follows that S is a stable matching.

---
__Fact__:
> Every execution of the G-S algorithm results in the set S<sup>∗</sup>.

__Fact__:
> In the stable matching S<sup>∗</sup>, each woman is paired with her worst valid partner.

- - -
