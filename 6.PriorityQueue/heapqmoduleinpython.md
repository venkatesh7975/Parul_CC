
---

# 🐍 Python `heapq` Module — Detailed Complete Notes

---

# 📌 1️⃣ What is `heapq`?

`heapq` is a Python module that implements a:

> **Binary Min Heap using a list**

It is:

* Array-based
* Complete Binary Tree
* Maintains Min-Heap property

⚠️ Important:

```text
Python heapq supports ONLY Min Heap by default.
```

If you want Max Heap → you must simulate it.

---

# 📌 2️⃣ Internal Working

`heapq` uses:

```text
Parent = (i - 1) // 2
Left   = 2*i + 1
Right  = 2*i + 2
```

It does NOT create tree nodes.

It stores everything in a Python list.

---

# 📌 3️⃣ Core Heap Functions

---

# 🔹 3.1 `heapq.heapify(iterable)`

### Purpose

Convert an existing list into a heap **in-place**.

### Syntax

```python
import heapq
heapq.heapify(list_name)
```

### Example

```python
nums = [7, 3, 10, 1, 5]
heapq.heapify(nums)
print(nums)
```

Output (valid heap):

```text
[1, 3, 10, 7, 5]
```

⚠️ Not sorted.
Only root is guaranteed smallest.

---

### Time Complexity

```text
O(n)
```

💡 Interview Insight:

Many candidates say O(n log n) ❌
Correct answer → O(n) ✅

Because bottom-up heapify is used.

---

# 🔹 3.2 `heapq.heappush(heap, value)`

### Purpose

Insert element while maintaining heap property.

### Syntax

```python
heapq.heappush(heap, value)
```

### Time Complexity

```text
O(log n)
```

Because it performs **heapify-up**.

---

# 🔹 3.3 `heapq.heappop(heap)`

### Purpose

Remove and return smallest element (root).

### Syntax

```python
smallest = heapq.heappop(heap)
```

### Time Complexity

```text
O(log n)
```

Because it performs **heapify-down**.

---

# 🔹 3.4 `heapq.heappushpop(heap, value)`

### Purpose

Push new element → then pop smallest.

More efficient than:

```python
heappush()
heappop()
```

### Syntax

```python
heapq.heappushpop(heap, value)
```

### Important Behavior

* First pushes value
* Then removes smallest element

### Time Complexity

```text
O(log n)
```

⚡ Used in Top-K problems for optimization.

---

# 🔹 3.5 `heapq.heapreplace(heap, value)`

### Purpose

Pop smallest → then push new element.

### Syntax

```python
heapq.heapreplace(heap, value)
```

### Difference from heappushpop

| Function    | Operation Order |
| ----------- | --------------- |
| heappushpop | Push → Pop      |
| heapreplace | Pop → Push      |

⚠️ `heapreplace()` always removes root first.

Used when heap size must remain constant.

---

# 🔹 3.6 `heapq.nlargest(k, iterable)`

### Purpose

Return K largest elements.

### Syntax

```python
heapq.nlargest(k, iterable)
```

### Time Complexity

```text
O(n log k)
```

Internally maintains a heap of size k.

---

# 🔹 3.7 `heapq.nsmallest(k, iterable)`

### Purpose

Return K smallest elements.

### Syntax

```python
heapq.nsmallest(k, iterable)
```

### Time Complexity

```text
O(n log k)
```

---

# 📌 4️⃣ Simulating Max Heap in Python

Since `heapq` only supports Min Heap:

### Trick → Use negative numbers

```python
heap = []
heapq.heappush(heap, -10)
heapq.heappush(heap, -20)
heapq.heappush(heap, -5)

print(-heapq.heappop(heap))  # 20
```

### Why This Works

Min Heap stores smallest number.

Negative of largest number becomes smallest.

---

# 📌 5️⃣ Using Heap with Tuples (Very Important)

Heap compares tuple elements lexicographically.

### Example

```python
heap = []
heapq.heappush(heap, (2, "apple"))
heapq.heappush(heap, (1, "banana"))
heapq.heappush(heap, (3, "cherry"))

print(heapq.heappop(heap))
```

Output:

```text
(1, 'banana')
```

Comparison order:

1. Compare first element
2. If tie → compare second
3. And so on

---

# 📌 6️⃣ When to Use Which Function

| Scenario                 | Best Method              |
| ------------------------ | ------------------------ |
| Build heap from list     | heapify()                |
| Insert element           | heappush()               |
| Remove smallest          | heappop()                |
| Maintain fixed size heap | heapreplace()            |
| Efficient push+pop       | heappushpop()            |
| Find top k elements      | nlargest() / nsmallest() |

---

# 📌 7️⃣ Common Patterns in Interviews

---

### Pattern 1 — K Largest Elements

Use Min Heap of size k.

---

### Pattern 2 — K Smallest Elements

Use Max Heap of size k (simulate using negatives).

---

### Pattern 3 — Frequency Problems

Use tuple:

```python
(count, element)
```

or

```python
(-count, element)
```

---

### Pattern 4 — Dijkstra

Use tuple:

```python
(distance, node)
```

Min Heap automatically picks smallest distance.

---

# 📌 8️⃣ Heap vs Sorting

| Problem        | Sorting    | Heap         |
| -------------- | ---------- | ------------ |
| Full sorting   | O(n log n) | ❌            |
| Top k elements | O(n log n) | O(n log k) ✅ |
| Streaming data | ❌          | ✅            |

Heap is best when:

```text
You do NOT need full sorting.
You only need extreme elements.
```

---

# 📌 9️⃣ Space Complexity

Heap always uses:

```text
O(n)
```

But for Top-K problems:

```text
O(k)
```

---

# 📌 🔟 Real Interview Insight

Weak candidates know:

```python
heappush
heappop
```

Strong candidates know:

* heapify is O(n)
* heapreplace vs heappushpop difference
* tuple ordering behavior
* how to simulate max heap
* Top-K pattern

Elite candidates:

* Can implement heap manually
* Understand build heap proof
* Know internal heap invariants

---

# 🧠 Final Mental Model

```text
Min Heap:
Insert → Bubble Up (smaller goes up)
Delete → Push Down (larger goes down)

Max Heap:
Insert → Bubble Up (larger goes up)
Delete → Push Down (smaller goes down)
```

`heapq` = Min Heap + List + Index Math

---


