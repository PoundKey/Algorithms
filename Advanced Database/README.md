# CPSC 404 Advanced Database

### Relationships among Files, Disks, RAM, Buffer Pool(s), DBMS, OS

#### Typical Memory Hierarchy:
![Memory Hierarchy](http://cse1.net/recaps/img/4-hierarchy.jpg)

#### Components of a Disk Drive
- The platters spin (e.g., 7200 rpm)
- The whole arm assembly is moved in, or out, to position a head on a desired __track__, k.
- All tracks with the same track # (e.g., track k) make up __cylinder__ k.
- Block size is a multiple of sector size, the logical partition.
- Only one head reads/writes at any one time.

![Hard Drive Component](http://thewindowsclub.thewindowsclubco.netdna-cdn.com/wp-content/uploads/2012/10/diagram-of-hard-disk.png)

#### Accessing a Disk Page:
- Access time = Seek time + Rotational delay + Transfer time
- Access time: time to read or write a disk page
- Seek time: move arm to position the disk head at a cyl/track (1-20ms)
- Rotational delay: wait for block to rotate under head (0-10ms)
- Transfer time: move data between disk and RAM ( 1ms/4K page)

__Example__: //TODO


### Indexes
> An index can be created in a table to find data more quickly and efficiently. Updating a table with indexes takes more time than updating a table without (because the indexes also need an update). So only create indexes on columns (and tables) that will be frequently searched against.  
> SQL example: _CREATE INDEX index_name ON table_name (column_name)_

- DBMS = Data + Data Structure + Seaching Algorithm

### Buffer Manager
- The software layer responsible for bringing pages from disk to main memory as needed.
- The buffer manager manages the available main memory by partitioning it into a collection of pages, which we collectively refer to as the buffer pool.
- The main memory pages in the buffer pool are called frames. (slots that can hold a page)
- The goal is to provide access to more data than will fit in main memory, and the basic idea is to bring in pages from disk to main memory as needed, replacing pages no longer needed in main memory. (Similar in OS & Virtual Memory)
- The ability to predict reference patterns allows for a better choice of pages to replace and makes the idea of specialized buffer replacmnent policies more attractive in the DBMS environment.
- Being able to predict reference patterns enables the use of a simple and very effective strategy called __prefetching of pages__ (32-64 4KB pages in general.

### Buffer Replacement Policies
- least recently used (LRU)
- clock replacement
	- choose a page for replacement using a current variable that takes on values 1 through N, where N is the number of buffer frames, in circular order.
- Other replacement policies include first in first out (FIFO) and most recently used (MRU).
