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

__Example__:

- Megatron 747: disk rpm = 3840
- Block size = 4096 bytes (4K)
- 4 platters of 2 surfaces each 2<sup>13</sup> = 8192 cylinders
- Average # sectors/track = 2<sup>8</sup> = 256
- #bytes/sector = 2<sup>9</sup> = 512
- Moving head assembly between cylinders = 1 ms (setup time) + 1 ms/500 cylinders

1. What is the max/avg seek time?
	- Max: the entire #cylinders: 1 + 8192/500 x 1ms
	- Avg: __1/3__ of #cylinders: 1 + 8192/(3 x 500) x 1ms
2. What is the max/avg rotational latency time?
	- Max: the entire #sectors: 1/(3840/60) x 1000ms
	- Age: __1/2__ of #sectors: Max/2
3. What is the transfer time?
	- Max*4/256 = transfer time in ms/block 

#### Arranging Pages on Disk:
- Prefetching for a sequential scan of data pages. (e.g., read 32 or more pages at a time)
- Anticipatory prefetch - DBMS may be able to “predict” what the user wants to do next
- Key to lowering I/O costs: reduce seek and rotation time!
- __The “next block” concept__. We prefer to access: Blocks on same track > Blocks on same cylinder > Blocks on adjacent cylinders.
- Arrange blocks in a file sequentially can minimize seek and rotational delays.

#### Solid State Disks (SSDs)
- Flash memory is based on EEPROMs (e.g., MP3 players, cameras, cell phones)
- Advantages: No spinning disks or moving parts, lower power requirement and faster reads.
- Disadvantages: Costy, smaller capacity, slower random writes, limited write cycles (~100000)\

#### Ram vs. Disk:
- About 5 orders of magnitude difference in speeds (nanoseconds vs. milliseconds)


#### Indexes
> An index can be created in a table to find data more quickly and efficiently. Updating a table with indexes takes more time than updating a table without (because the indexes also need an update). So only create indexes on columns (and tables) that will be frequently searched against.  
> SQL example: _CREATE INDEX index_name ON table_name (column_name)_

- DBMS = Data + Data Structure + Seaching Algorithm

### Buffer Pool Management
- A DBMS buffer pool is part of RAM, and is managed independently of the OS.
- A page is the smallest unit of transfer between disk and main memory.
- Logical memory has __“pages”__, and physical memory (RAM) has __“frames”__.
- The Translation Lookaside Buffer (TLB), a fast L1 hardware cache used to determine whether or not a particular page is currently in memory.

![Buffer Pool Management](./img/bpool.png)

#### When a Page is Requested ...
- If requested page is not in buffer pool:
	- Choose a frame for replacement. If that frame is dirty, write it to disk, and read requested page into chosen frame.
- Pin the new page and return its address
	- __“Pin”__ = hold in memory & don’t allow another page to overwrite it; add 1 to the in-use count
- Requestor of page must unpin it, and indicate whether the page has been modified:
	- Maintain a dirty bit for the page
- Page may be requested many times
	- Maintain a pin count, and A page is a candidate for replacement iff: pin_count = 0
- Concurrency control and recovery mechanisms may entail additional I/O when a frame is chosen for replacement
	- e.g., Write-Ahead Log protocol

#### Force vs. Steal; ARIES:
- Related to __crash recovery__
- __Force__: At transaction commit time, force (i.e., write) the transaction’s updated pages to disk (after writing the
log records to disk.)
- __Steal__: When the BP desperately needs a free page, we can write a dirty page for an uncommitted transaction to disk (i.e., we steal a frame from an in-flight transaction).

#### Page fault occurs ...
 when a program accesses a page that is mapped in the virtual address space, but not loaded in physical memory.

### Buffer Manager
- The software layer responsible for bringing pages from disk to main memory as needed.
- The buffer manager manages the available main memory by partitioning it into a collection of pages, which we collectively refer to as the buffer pool.
- The main memory pages in the buffer pool are called frames. (slots that can hold a page)
- The goal is to provide access to more data than will fit in main memory, and the basic idea is to bring in pages from disk to main memory as needed, replacing pages no longer needed in main memory. (Similar in OS & Virtual Memory)
- The ability to predict reference patterns allows for a better choice of pages to replace and makes the idea of specialized buffer replacmnent policies more attractive in the DBMS environment.
- Being able to predict reference patterns enables the use of a simple and very effective strategy called __prefetching of pages__ (32-64 4KB pages in general.

### Page Replacement Algorithms
- FIFO: Victim = oldest page
- Least Recently Used (LRU): Victim = page that hasn’t been referenced for the longest time
- MRU: Victim = page that has been most recently used
- Clock Replacement:
	- Each page is given a “second chance”. We’ll cycle through the pages, as necessary, looking for a victim.
	- Idea: If a page is referenced often enough, its reference bit (RB) will stay set, and it won’t be a victim.

#### Clock Algorithm (One Version):
We assume that an existing page in the BP that is reused has its RB set to 1 upon reuse (the RB can also reflect the pin count).

```python
If an empty frame exists in the BP:
	- Use it to store the new page’s data
	- Set its RB to 1 and set its arrival time to 'current'
else:
	- Find the oldest page (i.e., oldest timestamp) in the BP
	- If that page’s RB is set to 0:
		- Replace that BP page with the new one
		- Set the new page’s RB to 1, and its arrival time to “current”
	else: 
		- Give that page a second chance (victim not found yet)
		- Decrement that page’s RB to 0
		- Update that page’s arrival time to “current”
```

#### Extended Clock Algorithm:

- Include both a reference bit and a dirty bit (RB/DB)
- DB is set if page needs to be written to disk
- Similar to Clock PRA
- Again, victim search begins with the oldest page. The first 0/0 or 0/0* is the victim.
	- 0/0 or 0/0* Becomes: Victim (* = write out the dirty page)
	- 0/1 Becomes: 0/0*
	- 1/0 or 1/0* Becomes: 0/0 or 0/0*
	- 1/1 Becomes: 0/1

#### Sequential Flooding:
- Page replacement policy can have big impact on # of I/Os. Also, depends on the data access pattern
- __Sequential flooding__: Nasty situation caused by LRU + repeated sequential scans:
	- When #buffer frames < #pages in file, means each page request causes an I/O (page fault)
	- Example: LRU with 8 available buffer frames, read and process pages 1-9 from Table X

#### DBMS vs. OS File System
OS does disk space & buffer mgmt, so why not let the OS manage these tasks?  
A DBMS needs to have control over events that most OS’s don’t need to worry about for their own paging activities. Such events include forcing a page to disk, controlling the order of page writes to disk, working with files that span disks, having the ability to control prefetching and page replacement policies based on predictable access patterns, etc.

- Differences in OS support: portability issues
- Buffer management in DBMS requires ability to:
	- Pin a page in the buffer pool, or force a page to disk.
	- Adjust replacement policy, and prefetch pages based on access patterns in typical DB operations.
