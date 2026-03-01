
---

# 🌳 Heap Data Structure — Complete Professional Notes

---

# 📌 1. What is a Heap?

A **Heap** is a special type of **Complete Binary Tree** that follows a strict ordering rule called the **Heap Property**.

> 💡 Important:
> A heap is NOT a BST.
> It only guarantees parent-child ordering — not full sorting.

---

## ✅ 1.1 Complete Binary Tree

A tree is *complete* when:

* All levels are completely filled
* The last level is filled **from left to right**
* No gaps are allowed

---

### 📷 Visual Example

![Image](https://cdn.programiz.com/sites/tutorial2program/files/complete-binary-tree_0.png)

![Image](https://gtl.csa.iisc.ac.in/dsa/img158.gif)

![Image](https://files.codingninjas.in/complete_binary_tree-6731.png)

![Image](https://res.cloudinary.com/hptuexamhelper/image/upload/f_auto%2Cq_auto/BT1_ukd5pe.png)

---

# 📌 2. Heap Order Property

There are two types of heaps:

---

## 🔼 Max Heap

```
Parent ≥ Children
```

* Largest element is always at the root
* Used in Priority Queues (max priority first)

---

## 🔽 Min Heap

```
Parent ≤ Children
```

* Smallest element is always at the root
* Used in Dijkstra, Prim’s Algorithm, etc.

---

### 📷 Max vs Min Heap

![Image](https://www.btechsmartclass.com/data_structures/ds_images/Max%20Heap.png)

![Image](https://iq.opengenus.org/content/images/2019/06/Min-Heap.png)

![Image](https://prepbytes-misc-images.s3.ap-south-1.amazonaws.com/assets/1674109793492-Difference%20Between%20Max%20Heap%20and%20Min%20Heap2.png)

![Image](https://i.imgur.com/1mghTRv.png)

---

# 📌 3. Array Representation (Most Important Part)

⚠️ Heap is NOT stored as a tree internally.

It is stored as an **array**.

Tree structure is just visualization.

---

## 🔢 Index Formulas

For any index `i`:

```text
Parent      = (i - 1) // 2
Left Child  = 2*i + 1
Right Child = 2*i + 2
```

---

## Example

Tree:

```
        50
      /    \
    30      40
   /  \
 10   20
```

Array:

```python
[50, 30, 40, 10, 20]
```

---

# 📌 4. Core Heap Operations

1. Insert
2. Heapify Up
3. Delete Root
4. Heapify Down
5. Build Heap

---

# ✅ 5. INSERT (Max Heap)

### 📌 Logic

1. Add element at the end
2. Bubble it up until heap property is restored

---

### 🔥 Pseudocode

```text
INSERT(heap, value):

    add value at end

    index = last position

    while index > 0:
        parent = (index - 1) // 2

        if heap[parent] < heap[index]:
            swap(parent, index)
            index = parent
        else:
            break
```

---

### 🐍 Python Implementation

```python
heap = []

def insert(value):
    heap.append(value)
    heapify_up(len(heap) - 1)

def heapify_up(i):
    while i > 0:
        parent = (i - 1) // 2
        
        if heap[parent] < heap[i]:
            heap[parent], heap[i] = heap[i], heap[parent]
            i = parent
        else:
            break
```

---

### 🔎 Dry Run

```
Insert 10 → [10]

Insert 20 → [10, 20]
Swap      → [20, 10]

Insert 30 → [20, 10, 30]
Swap      → [30, 10, 20]
```

---

# ✅ 6. DELETE ROOT (Extract Max)

### 📌 Logic

1. Store root value
2. Replace root with last element
3. Remove last element
4. Heapify Down

---

### 🔥 Pseudocode

```text
DELETE(heap):

    if heap empty:
        return

    root = heap[0]

    move last element to root
    remove last element

    heapify_down(0)

    return root
```

---

# ✅ 7. HEAPIFY DOWN (Max Heap)

```text
HEAPIFY_DOWN(i):

    while True:

        left = 2*i + 1
        right = 2*i + 2
        largest = i

        if left exists AND heap[left] > heap[largest]:
            largest = left

        if right exists AND heap[right] > heap[largest]:
            largest = right

        if largest == i:
            break

        swap(i, largest)
        i = largest
```

---

### 🐍 Python Code

```python
def delete():
    if len(heap) == 0:
        return None

    root = heap[0]

    heap[0] = heap[-1]
    heap.pop()

    heapify_down(0)

    return root


def heapify_down(i):
    n = len(heap)

    while True:
        left = 2*i + 1
        right = 2*i + 2
        largest = i

        if left < n and heap[left] > heap[largest]:
            largest = left

        if right < n and heap[right] > heap[largest]:
            largest = right

        if largest == i:
            break

        heap[i], heap[largest] = heap[largest], heap[i]
        i = largest
```

---

# 📌 8. Build Heap (Important Interview Topic)

If you insert elements one by one:

```
Time = O(n log n)
```

But if you use bottom-up heapify:

```
Time = O(n)
```

> 💡 Most people incorrectly think build heap is O(n log n).
> This is a favorite interview trap.

---

# 📊 9. Time Complexity Summary

| Operation  | Time Complexity |
| ---------- | --------------- |
| Insert     | O(log n)        |
| Delete     | O(log n)        |
| Peek       | O(1)            |
| Build Heap | O(n)            |

---

# 🧠 10. Core Insight (Very Important)

Heap is:

```
Array + Index Mathematics
```

NOT a pointer-based tree.

That’s why it is memory efficient.

---

# 🚀 11. Mental Model

```
Insert → Bubble UP ↑
Delete → Push DOWN ↓
```

That’s the entire heap logic.

---

# 🎯 12. Where Heaps Are Used

* Priority Queue
* Dijkstra’s Algorithm
* Prim’s Algorithm
* Heap Sort
* Top K Frequent Elements
* Kth Largest / Smallest Problems

---


Below is a **clean, symmetric, professional Markdown version** including:

* Max Heap
* Min Heap
* Insert
* Delete
* Heapify Up
* Heapify Down
* Build Heap
* Comparison

You can directly paste this into GitHub / Notion / your course material.

---

# 🌳 Heap Data Structure — Complete Notes (Max Heap + Min Heap)

---

# 📌 1. What is a Heap?

A **Heap** is a **Complete Binary Tree** that satisfies the **Heap Property**.

> 💡 Heap does NOT guarantee sorted order.
> It only guarantees correct ordering between parent and children.

---

## ✅ Complete Binary Tree Rules

* All levels completely filled
* Last level filled **from left to right**
* No gaps allowed

---

### 📷 Complete Binary Tree Example

![Image](https://cdn.programiz.com/sites/tutorial2program/files/complete-binary-tree_0.png)

![Image](https://files.codingninjas.in/complete_binary_tree-6731.png)

![Image](https://gtl.csa.iisc.ac.in/dsa/img158.gif)

![Image](https://miro.medium.com/1%2ACMGFtehu01ZEBgzHG71sMg.png)

---

# 📌 2. Types of Heap

---

# 🔼 2.1 Max Heap

### Heap Property

```text
Parent ≥ Children
```

* Largest element at root
* Used when we need maximum quickly

### Example

```
        50
      /    \
    30      40
   /  \
 10   20
```

Array:

```python
[50, 30, 40, 10, 20]
```

---

# 🔽 2.2 Min Heap

### Heap Property

```text
Parent ≤ Children
```

* Smallest element at root
* Used in Dijkstra, Prim’s Algorithm, etc.

### Example

```
        10
      /    \
    20      30
   /  \
 40   50
```

Array:

```python
[10, 20, 30, 40, 50]
```

---

### 📷 Max Heap vs Min Heap

![Image](https://www.btechsmartclass.com/data_structures/ds_images/Max%20Heap.png)

![Image](https://iq.opengenus.org/content/images/2019/06/Min-Heap.png)

![Image](https://prepbytes-misc-images.s3.ap-south-1.amazonaws.com/assets/1674109793492-Difference%20Between%20Max%20Heap%20and%20Min%20Heap2.png)

![Image](https://prepbytes-misc-images.s3.ap-south-1.amazonaws.com/assets/1661418057715-MaxHeapinJava%20-1.png)

---

# 📌 3. Array Representation (Most Important Concept)

Heap is stored in an **array**.

For any index `i`:

```text
Parent      = (i - 1) // 2
Left Child  = 2*i + 1
Right Child = 2*i + 2
```

> Heap = Array + Index Mathematics

---

# 📌 4. Core Operations

* Insert
* Heapify Up
* Delete Root
* Heapify Down
* Build Heap

---

# 🔼 5. INSERT — Max Heap

### Logic

1. Add element at end
2. Bubble Up while parent < child

---

### Python Code (Max Heap)

```python
max_heap = []

def insert_max(value):
    max_heap.append(value)
    heapify_up_max(len(max_heap) - 1)

def heapify_up_max(i):
    while i > 0:
        parent = (i - 1) // 2
        
        if max_heap[parent] < max_heap[i]:
            max_heap[parent], max_heap[i] = max_heap[i], max_heap[parent]
            i = parent
        else:
            break
```

---

# 🔽 6. INSERT — Min Heap

### Logic

1. Add element at end
2. Bubble Up while parent > child

---

### Python Code (Min Heap)

```python
min_heap = []

def insert_min(value):
    min_heap.append(value)
    heapify_up_min(len(min_heap) - 1)

def heapify_up_min(i):
    while i > 0:
        parent = (i - 1) // 2
        
        if min_heap[parent] > min_heap[i]:
            min_heap[parent], min_heap[i] = min_heap[i], min_heap[parent]
            i = parent
        else:
            break
```

---

# 🔼 7. DELETE ROOT — Max Heap

### Steps

1. Store root
2. Replace root with last element
3. Remove last
4. Heapify Down

---

### Python Code

```python
def delete_max():
    if not max_heap:
        return None

    root = max_heap[0]
    max_heap[0] = max_heap[-1]
    max_heap.pop()

    heapify_down_max(0)
    return root


def heapify_down_max(i):
    n = len(max_heap)

    while True:
        left = 2*i + 1
        right = 2*i + 2
        largest = i

        if left < n and max_heap[left] > max_heap[largest]:
            largest = left

        if right < n and max_heap[right] > max_heap[largest]:
            largest = right

        if largest == i:
            break

        max_heap[i], max_heap[largest] = max_heap[largest], max_heap[i]
        i = largest
```

---

# 🔽 8. DELETE ROOT — Min Heap

### Python Code

```python
def delete_min():
    if not min_heap:
        return None

    root = min_heap[0]
    min_heap[0] = min_heap[-1]
    min_heap.pop()

    heapify_down_min(0)
    return root


def heapify_down_min(i):
    n = len(min_heap)

    while True:
        left = 2*i + 1
        right = 2*i + 2
        smallest = i

        if left < n and min_heap[left] < min_heap[smallest]:
            smallest = left

        if right < n and min_heap[right] < min_heap[smallest]:
            smallest = right

        if smallest == i:
            break

        min_heap[i], min_heap[smallest] = min_heap[smallest], min_heap[i]
        i = smallest
```

---

# 📌 9. Build Heap (Interview Gold)

### Method 1 — Insert One by One

```
Time = O(n log n)
```

### Method 2 — Bottom-Up Heapify (Correct Way)

```
Time = O(n)
```

> ⚠️ Most candidates answer O(n log n).
> Correct answer: O(n).

---

# 📊 10. Time Complexity Table

| Operation  | Max Heap | Min Heap |
| ---------- | -------- | -------- |
| Insert     | O(log n) | O(log n) |
| Delete     | O(log n) | O(log n) |
| Peek       | O(1)     | O(1)     |
| Build Heap | O(n)     | O(n)     |

---

# 🧠 11. Mental Model

```
Max Heap:
Insert → Bubble UP ↑
Delete → Push DOWN ↓

Min Heap:
Insert → Bubble UP ↑
Delete → Push DOWN ↓
```

Only comparison sign changes.

---

# 🎯 12. Where Heaps Are Used

* Priority Queue
* Dijkstra’s Algorithm
* Prim’s Algorithm
* Heap Sort
* Top K Frequent Elements
* Kth Largest / Smallest

---




