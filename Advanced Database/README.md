# CPSC 404 Advanced Database

### Buffer Manager
- The software layer responsible for bringing pages from disk to main memory as needed.
- The buffer manager manages the available main memory by partitioning it into a collection of pages, which we collectively refer to as the buffer pool.
- The main memory pages in the buffer pool are called frames. (slots that can hold a page)

### Buffer Replacement Policies
- least recently used (LRU)
- clock replacement
	- choose a page for replacement using a current variable that takes on values 1 through N, where N is the number of buffer frames, in circular order.
- Other replacement policies include first in first out (FIFO) and most recently used (MRU).
