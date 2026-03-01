
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


