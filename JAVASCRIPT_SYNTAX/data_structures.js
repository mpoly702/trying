Data Structures in Modern JavaScript

JavaScript provides several built-in data structures, categorized into primitive types and reference types. Below is a detailed breakdown of all modern JavaScript data structures:


---

1. Primitive Data Structures (Immutable, stored in stack)

These are the simplest types in JavaScript.

Number → let x = 42;

BigInt → let bigNumber = 12345678901234567890n;

String → let name = "John Doe";

Boolean → let isTrue = true;

Undefined → let x; (default value when a variable is declared but not assigned)

Null → let empty = null;

Symbol → let sym = Symbol("unique"); (used for unique object keys)



---

2. Non-Primitive Data Structures (Mutable, stored in heap)

These are reference types, allowing for complex data storage.

A. Arrays (Indexed Collections)

A resizable, zero-indexed list of elements.

Declaration: let arr = [1, 2, 3, 4];

Methods: .push(), .pop(), .shift(), .unshift(), .map(), .filter(), .reduce(), etc.


Types of Arrays:

Sparse Array → let sparseArr = [1, , 3]; // Has undefined slots

Typed Arrays (ES6) → let int8 = new Int8Array([10, 20, 30]); (For handling raw binary data)



---

B. Objects (Key-Value Pairs)

A collection of key-value pairs, where keys are strings (or symbols).

Declaration:

let obj = { name: "John", age: 25 };

Methods: Object.keys(), Object.values(), Object.entries(), Object.assign(), Object.freeze(), Object.seal()


Types of Objects:

Plain Object → { key: value }

Nested Object → { user: { name: "Alice", age: 30 } }

Singleton Object → Created via Object.create(null)

Prototypal Objects → Object.create(proto)



---

C. Map (Key-Value Collection)

Similar to objects but allows any data type as a key.

Declaration:

let map = new Map();
map.set("name", "Alice");
map.set(1, "one");

Methods: .set(), .get(), .has(), .delete(), .size, .clear()


Use Cases: Faster key-value lookups, preserving key order.


---

D. WeakMap (Garbage-Collectible Map)

Similar to Map, but keys must be objects and are weakly held.

Declaration:

let weakMap = new WeakMap();
let obj = {};
weakMap.set(obj, "value");

Methods: .set(), .get(), .has(), .delete() (No .size or iteration methods)


Use Case: Prevents memory leaks since keys are garbage-collected when no longer referenced.


---

E. Set (Unique Value Collection)

A collection of unique values of any type.

Declaration:

let set = new Set([1, 2, 3, 3, 4]); // Stores: {1, 2, 3, 4}

Methods: .add(), .delete(), .has(), .clear(), .size, .forEach()


Use Cases: Removing duplicates from arrays, checking for unique elements.


---

F. WeakSet (Garbage-Collectible Set)

Similar to Set, but only stores objects and holds them weakly.

Declaration:

let weakSet = new WeakSet();
let obj = {};
weakSet.add(obj);

Methods: .add(), .has(), .delete() (No .size, .forEach(), or iteration)


Use Case: Prevents memory leaks when managing object references.


---

3. Advanced Data Structures in JavaScript

A. Linked List (Manually Implemented)

A series of nodes containing values and pointers.

Example Implementation:

class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
  }

  append(value) {
    let newNode = new Node(value);
    if (!this.head) {
      this.head = newNode;
    } else {
      let current = this.head;
      while (current.next) {
        current = current.next;
      }
      current.next = newNode;
    }
  }
}



---

B. Stack (LIFO - Last In, First Out)

Can be implemented using arrays or linked lists.

Array Implementation:

class Stack {
  constructor() {
    this.items = [];
  }

  push(value) { this.items.push(value); }
  pop() { return this.items.pop(); }
  peek() { return this.items[this.items.length - 1]; }
}



---

C. Queue (FIFO - First In, First Out)

Can be implemented using arrays or linked lists.

Array Implementation:

class Queue {
  constructor() {
    this.items = [];
  }

  enqueue(value) { this.items.push(value); }
  dequeue() { return this.items.shift(); }
  front() { return this.items[0]; }
}



---

D. Priority Queue

Similar to a queue but with priorities.

Example Implementation:

class PriorityQueue {
  constructor() {
    this.items = [];
  }

  enqueue(value, priority) {
    this.items.push({ value, priority });
    this.items.sort((a, b) => a.priority - b.priority);
  }

  dequeue() {
    return this.items.shift().value;
  }
}



---

E. Hash Table (Implemented Using Objects or Maps)

Efficient key-value storage.

Example Implementation (Using Object):

class HashTable {
  constructor(size = 50) {
    this.buckets = new Array(size).fill(null).map(() => []);
  }

  _hash(key) {
    return key.toString().length % this.buckets.length;
  }

  set(key, value) {
    let index = this._hash(key);
    this.buckets[index].push([key, value]);
  }

  get(key) {
    let index = this._hash(key);
    return this.buckets[index].find(([k]) => k === key)?.[1] || null;
  }
}



---

F. Graph (Node Relationships)

Nodes connected by edges, implemented using adjacency lists or matrices.

Adjacency List Example:

class Graph {
  constructor() {
    this.adjList = new Map();
  }

  addVertex(vertex) {
    if (!this.adjList.has(vertex)) {
      this.adjList.set(vertex, []);
    }
  }

  addEdge(vertex1, vertex2) {
    this.adjList.get(vertex1).push(vertex2);
    this.adjList.get(vertex2).push(vertex1); // Undirected graph
  }
}



---

Conclusion

JavaScript provides a wide range of built-in and manually implemented data structures. Understanding them helps optimize performance and memory usage in applications. Which data structure would you like to explore further?

