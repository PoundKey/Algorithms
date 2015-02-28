# CPSC 416 Distributed Systems
> A __distributed system__ is an application that executes a collection of protocols to coordinate the actions of multiple processes on a network, such that all components cooperate together to perform a single or small set of related tasks.

#### Pitfalls when Developing Distributed Systems
1. The network is reliable.
2. The network is secure.
3. The network is homogeneous.
4. The topology does not change. 
5. Latency is zero.
6. Bandwidth is infinite.
7. Transport cost is zero.
8. There is one administrator

## Design goals
- Heterogeneity 
	- Systems constructed from: Networks, Computer hardware, and Software
	- The challenge is must get these different systems and environments to inter-operate
- Concurrency 
	- The ability of a system component (e.g., server) to handle multiple simultaneous operations
	- Distributed systems are naturally concurrent (multiple clients operating in parallel)
	- Bottleneck: single server or network.
	- Server may stall while processing a client request; while request is stalled, server should be able to start other requests
- Scalability
	- The ability of a component to handle increased load without significant change
		- Changes to handle increased load should be proportional to the load increase
		- Performance degradation should be proportional to load increase
	- Key goal is to require incremental changes to a system as load increases
	- Allows server to handle increasing client load, this is a key issue for web-based systems
	- Don’t try to scale arbitrarily
		- Generalized scalability results in increased complexity, costs, and time to market
	- Key design constraints: expected system size and growth
	- Focus for expected size, and provide for scaling to handle growth
	- CND: Content Delivery Networks
		- Address translation: from url like espn.com to url of nearby content server
- Openness
	- Two types of openness are important: non-proprietary and extensibility
	- Non-proprietary: public protocols allows clients and servers from different vendors to talk to each other
	- Extensibility is the ability to customize to meet unanticipated needs.
- Fault Tolerance
	- Tolerate partial failures
	- Dealing with partial failure
		- Recoverability: persistent data and for long-running computations, and prevent loss or corruption of data
		- Availability: prevent service interruption
- Security (Privacy and Authentication) 
	- Sender: should be able to control what other programs and people can read or modify the message
	- Receiver: should be able to identify message sender
	- Privacy (protect against eavesdropping) and authentication (know who you are talking to)
	- Key mechanism: cryptography
- Transparency
	- Goal: make distributed programming as easy as local so solve all previous problems
	- How: hide hard stuff behind software abstraction and present single system image to programmers

__Types of transparency__:

- Access transparency
	- Identical operations used to access object regardless of local/remote
	- Important because it simplifies remote access
- Location transparency
	- Access to remote object without knowing where object is or how to find it
	- Important because can move or replicate objects without telling clients
	- Ideally would like location and access transparency together
- Performance transparency
	- Access to remote object as fast as access to local object
	- Hard because remote access is usually slower, sometimes the difference doesn’t matter, but sometimes it does
- Failure & Security Transparency
	- Failure Transparency: Conceals faults allowing applications to complete despite other hardware/software failures
	- Security Transparency: The ability to provide different levels of privacy or authentication without changing the distributed application

__Other Transparencies__:

- Mobility: Migration - moving a resource, Relocation – moving while in use
- Replication – hides the fact there may be replicas (need same name and contents)
- Concurrency/scaling transparency – hide the fact there could be multiple simultaneous users – resource stays consistent and access time constant

## Design Challenges

### Naming
- __Identifiers__: Name used to directly access a resource
	- Examples: IP address & port number, URL, mailing address
	- Not location transparent 
- __Pure name__: A location-transparent name
	- Compared to an identifier:
		- (+) move or replicate without changing name
		- (–) difficult (slow) to locate resource
		- (–) name encodes no location information
	- Examples: IP domain names, your name
- __Resolution__: converting pure name -> identifier
	- Examples: DNS, Phone book (name => number), “open” (Filename => inode)
- __Name contexts__:
	- Name’s meaning can depend on context
	- Examples: domain names (context is IP),  local phone numbers (context is Vancouver) 
- __Protection using ACLs__:
	- Access Control Lists (ACL) attached to resources, list users that can access the resource
	- Requires user authentication, user list is maintained on every resource and permission is checked on every access
- __Capabilities__: Names do two things:
	- name resource
	- grant permission to access the resource
	- a client that holds a capability for a resource has everything needed to access the resource
	- Access control: permission granted when capability issued, and access allowed when valid capability is presented

### Workload Allocation
- Key goal is to use resources efficiently by allocating load evenly among processors
- There are two models:
	- Centralized access to a processor pool
	- Collection of loosely coupled computers

#### Processor pool model
- Put workstations in a closet
- Tightly-coupled operating system or middleware
	- users access via a common shared access point
	- users log into pool not an individual machine
	- system allocates work to different processors to balance load
	- Example: Cloud Computing

#### Loosely Coupled Approach
- Everybody has their own processor
	- connected in a loosely-couple fashion (WAN)
- Problem is that load is not well balanced: processing power barely used or idled

#### Utilizing Idle Workstations
- Benefits: move programs from overloaded nodes
- __Key Issue__: can’t impact users who “own” the processor and owner has priority

---
### Consistency Maintenance
- Four key aspects to consistency
	* __Atomicity__: All-or-nothing property
		- Want all operations to complete or none
		- Issue: operations may include multiple nodes
		- Examples: Transfer between savings and chequing accounts, Internet commerce
	* __Coherence__: Keeping replicated data consistent
		- Why? Increases availability and improves performance
		- Issue: when one copy of an object is updated the system must maintain coherence by updating or invalidating the other copies
		- To maintain consistency we often need to know the order things happened 
	* __Clock Consistency__: Consistent view of time and event ordering
		- Issue: network messages and network performance is unpredictable and the exchange of messages takes time
		- Challenge: establish event ordering
	* __Failure Consistency__: 
		- Fail-stop model: components fail only by stopping instead of giving a “wrong” answer, a simplified failure model 
		- Byzantine failure model: 

## Network
Network = Host + Adapters + Wire + Switches/Routers + Software
![Network](img/network.png)

#### Network Characteristics
- communication style: Unicast, point-to-point, or multicast/broadcast; order
- performance: rate, delay, and predictability; fairness

#### Performance Metrics
- __Throughput__: network transfer rate
	- e.g., use to determine maximum rate to be used to guarantee a level of video quality
- __Latency__: network delay for sending a single message
	- e.g., used to determine how long it will take to download a web page
- __Jitter__: fluctuations in message latency
	- e.g., used to determine how much streaming media should be buffered
- __Packet Loss Rate__: represents the extreme cases or subsets of the above situations

---

## Distributed Coordination

- __Coordinator__: a node that organizes the actions of a set of nodes
- __Problems__: 
	- How to decide on what node or nodes should take over the role of the failed node.
	- How do we ensure that the data the “new” node is going to use is up to date.

#### Coordinator failure
- __Goal__: implement a strategy to deal with coordinator failure
- Two main issues:
	- Picking a new coordinator: detect failure and deal with it
	- Reconstructing coordinator state

#### Electing a new coordinator
- __Key Problem__: must do this without a coordinator
- Detecting failure:
	- any node might detect failure first
- Election:
	- name for process of reaching agreement
	- must run without coordination
	- must deal with arbitrary node failures
	- all the nodes must agree who new coordinator is when election is over
- Key ideas:
	- Before failure: nodes agree on a strategy, and assign total order on nodes
	- After failure:
		- use order to find the “highest” surviving node
		- use broadcast so that all nodes agree

### Election algorithms

#### Bully algorithm
- __Assumption__::
	- every node knows about every other node
	- every node has a unique node number
- __Invariant__:
	- node with highest number is always coordinator
-__Bully election__:
	- held whenever coordinator failure detected
	- reach global agreement on highest remaining node number

- Three types of messages:
	- elect, answer, coord
- Start election
	- send elect to all nodes with higher numbers, and wait for at least one answer
- When elect received
	- reply with answer, and start a new election
- New coordinator
	- is node that starts election but receives no answer
	- it sends coord message to all nodes with lower numbers
	- coord message include new list of nodes
- Adding nodes: call election if new node number is highest

![Bully Algorithm](img/bullyalgo.png)

#### Runtime
- __Base case__:
	- node with second highest id detects failure
	- total messages = n-2 (coord messages, less with broadcast)
- __Worse case__:
	- node with lowest id detects failure
	- total messages = O(n<sup>2</sup>)
- __Election latency__:
	- 3 sends + 1 timeout

---
#### Ring algorithm
- Organize nodes logically into a ring
- When a node detects a failure
	- send elect to neighbor, includes node number
	- If neighbor down, try its neighbor, and so on
- When node receives elect:
	- if not in node set, adds node number to elect and passes it on
	- otherwise, pick highest node in node set as coordinator, 
	- and send coord message around ring to nodes in node set
- Doesn’t tolerate failures very well

![Ring Algorithm](img/ringalgo.png)

#### Runtime
- __Messages required__: 2n (n for elect message and n for coord message)
- __Election latency__: 2n - 1 sends to (n-1)(timeouts)

### Network Partition
- A network partition is a network failure that divides the distributed system into multiple connected sub-networks
- __Problem__:
	- ensure that there is only a single coordinator even if network partitions
- __Solution__:
	- quorum protocol: elect coordinator only if at least half the nodes exist in a partition
![Network Partition](img/netp.png)

### Quorum protocols
- Assigning votes
	- every node has V votes (e.g., 1)
	- every network has a quorum, Q >= V<sub>total</sub>/2 + 0.5
- When electing new coordinator
	- tally votes from all surviving nodes, into T
	- if T < Q do not elect a new coordinator
- In coordinatorless partitions
	- nodes fail or stall until partition “heals”

---

## Time & Physical Clocks
__Time__: Decides event order and event intervals  
__Types of clocks__:

- Physical: 
	- Externally Synchronized: clock that matches real world (e.g., ATM Receipts)
	- Internally Synchronized: clock that matches clocks of other machines (e.g., File timestamps)
	- Have both event ordering and event intervals
- Logical:
	- Ability to order events, but no concept of interval
-  Computer Clock:
	- A vibrating crystal and a counter, crystal interrupts host CPU at regular intervals
- Issues for Synchronized Clocks
	- Setting: hard to get “current” time accurately
	- Keeping time: clocks run at slightly different rates
	- Sum: Synchronizing clocks is hard due to message latency and clock drift
	- Two Approaches: Authoritative Time Broadcast and Time Server

- Cristian’s Algorithm
	- Client
		* T<sub>0</sub> = clock
		* {I, UTC} = timeServer.readUTC () * T<sub>1</sub> = clock
		* clock = UTC + (T<sub>1</sub>-T<sub>o</sub>-I)/2
	- Server
		* I - Adjustment factor, may be 0
		* UTC - accurate at time of message send
		* If T<sub>min</sub> can be reliably estimated then the accuracy is ± ((T<sub>1</sub> – T<sub>0</sub>)/2 – T<sub>min</sub>)

- Adjusting for Clock Skew
	- __Problem__: we can’t move any clocks backward
	- __Solution__: If client is ahead of UTC, slow its clock so that it will converge with UTC before next synchronization message

- NTP (Internet Network Time Protocol)
	* Primary server gets UTC via radio
	* Secondary servers synchronize hierarchically 
	* Accuracy is roughly 30 milliseconds

### Logical Time
- In a distributed system, some events need not be ordered, others must be ordered for correct operation
- __Goal__: Determine event order without centralization, and build system support for higher-level services
- __Usage__: air traffic control systems, distributed locks, distributed checkpoint, recovery, etc.
- __Distributed checkpoint recovery__:
	- collection of nodes communicating over networw, and each updating local state based on messages
	- __Goal__: capture consistent checkpoint of system
	- __Approach__: each node records its updates in remote log, record logical time of update in log
	- To checkpoint, combine all logs and order by logical time

- The “Happened Before” relation:
	- event A HB event B if and only if:
		- A and B are on the same node and A precedes B in program order
		- or, A is the sender of message m and B is the receiver of m
	- Transitive property:
		- (a < b) ^ (b < c) → (a < c)
		- or: (a HB b) ^ (b HB c) → (a HB c)
	- Algorithms that use the HB relationship
		- logical clocks
		- causally ordered atomic multicast (CBCAST)

- Partial Order vs Total Order
	- __Total order__: for any pair of events e<sub>i</sub> and e<sub>j</sub>, either e<sub>i</sub> < e<sub>j</sub> or e<sub>i</sub> > e<sub>j</sub>, as if a global clock orders every message send
	- __Partial order__: for some pair of events e<sub>i</sub> and e<sub>j</sub>, either e<sub>i</sub> < e<sub>j</sub> nor e<sub>i</sub> > e<sub>j</sub>, we write this e<sub>i</sub> ~ e<sub>j</sub>

- Why logical clock?
	- label events with physical time, requires fine-grain internal synchronization, and this is very difficult/expensive to achieve
	- label events with logical time, maintain logical time according to happened before relationships

### Vector Timestamps
- __Basic idea__: message from S to R orders R after S
- Sender assigns sequence number (the node’s time) to message
- Each node maintains a vector timestamp V
	- At a particular node, the entries in V are that node’s idea of the current time on the other nodes
	- Use V on R to order events on R with respect to other nodes
	- Tag events with V of node on which they occur
	- Use event timestamps to determine order

![Vector Timestamp](img/vecs.png)

- Labeling events:
	- Label every event with vector timestamp of node on which it occurs
	- Event E on node A, E.V = V, when E occurs
	- __Note__: to use E.V to order events from the same node, increment V<sub>A</sub> on A when E occurs

![Vector Timestamp](img/vecdec.png)

- Good: ordering exactly matches happened before
- Bad: every message must contain a timestamp vector, timestamp-vector size is O(n)

### Distributed logical clock (DLC)
- __idea__: use a single number to represent logical time
- logical time LT<sub>x</sub> stored at every node x, starts at 0 on every node
- when a node x, sends a message:
	- LT<sub>x</sub> += 1
	- Include LT<sub>x</sub> in the message
- when a node y receives a message from x:
	- LT<sub>y</sub> = max (LT<sub>x</sub>,LT<sub>y</sub>)

![DLC](img/dlc1.png)

- __Note__: Some events that DLC orders, may not be ordered by Happened Before
	- DLC orders some events unnecessarily


![DLC](img/dlc2.png)
