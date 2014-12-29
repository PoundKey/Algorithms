## Definition

#### Algorithm
> A high level, language independent description of a step-by-step process for solving a problem

#### Data Structure
> A way of storing and organizing data so that it can be manipulated as described by an ADT.
> A data structure is defined by the algorithms that implement the ADT operations

## Circular Array Queue (FIFO)
![Circular Array Queue](./circularq.png)

```cpp
void enqueue(Object x) {
	Q[back] = x;
	back = (back + 1) % size;
}

bool is_empty() {
	return (front == back);
}

Object dequeue() {
	x = Q[front];
	front = (front + 1) % size;
	return x;
}

bool is_full() {
	return (front == (back + 1) % size);
}
```



```javascript

```
