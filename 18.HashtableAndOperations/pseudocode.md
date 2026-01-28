# Hash Table and Operations - Pseudocode

## Problem Statement
Implement a hash table with insert, delete, and search operations.

## Data Structure
```
HashTable:
  - table: Array of slots
  - size: Current number of elements
  - capacity: Size of the table
  - loadFactor: size / capacity
```

## Algorithm

### Initialize Hash Table
```
FUNCTION initializeHashTable(capacity):
    table = array of size capacity
    size = 0
    loadFactor = 0.75
    RETURN HashTable instance
END FUNCTION
```

### Insert Operation
```
FUNCTION insert(key, value):
    IF size >= capacity * loadFactor:
        rehash()
    END IF
    
    hashValue = hash(key, capacity)
    
    // Linear probing for collision resolution
    WHILE table[hashValue] != null AND table[hashValue].key != key:
        hashValue = (hashValue + 1) % capacity
    END WHILE
    
    IF table[hashValue] == null:
        size = size + 1
    END IF
    
    table[hashValue] = new Entry(key, value)
    PRINT "Inserted:", key, "->", value
END FUNCTION
```

### Search Operation
```
FUNCTION search(key):
    hashValue = hash(key, capacity)
    
    WHILE table[hashValue] != null:
        IF table[hashValue].key == key:
            RETURN table[hashValue].value
        END IF
        hashValue = (hashValue + 1) % capacity
    END WHILE
    
    RETURN null
END FUNCTION
```

### Delete Operation
```
FUNCTION delete(key):
    hashValue = hash(key, capacity)
    
    WHILE table[hashValue] != null:
        IF table[hashValue].key == key:
            table[hashValue] = null  // Tombstone marker
            size = size - 1
            PRINT "Deleted:", key
            RETURN true
        END IF
        hashValue = (hashValue + 1) % capacity
    END WHILE
    
    PRINT "Key not found:", key
    RETURN false
END FUNCTION
```

### Rehash Operation
```
FUNCTION rehash():
    oldTable = table
    oldCapacity = capacity
    
    capacity = nextPrime(capacity * 2)
    table = array of size capacity
    size = 0
    
    FOR each entry in oldTable:
        IF entry != null:
            insert(entry.key, entry.value)
        END IF
    END FOR
    
    PRINT "Rehashing completed. New capacity:", capacity
END FUNCTION
```

### Display Hash Table
```
FUNCTION display():
    PRINT "Hash Table:"
    FOR i = 0 TO capacity - 1:
        IF table[i] != null:
            PRINT i, "->", table[i].key, ":", table[i].value
        END IF
    END FOR
END FUNCTION
```

### Hash Function
```
FUNCTION hash(key, capacity):
    hashValue = 0
    
    IF key is integer:
        RETURN key % capacity
    ELSE IF key is string:
        FOR each character in key:
            hashValue = (hashValue * 31 + asciiValue(character)) % capacity
        END FOR
        RETURN hashValue
    END IF
END FUNCTION
```

## Time Complexity
- Insert: O(1) average, O(n) worst case
- Search: O(1) average, O(n) worst case
- Delete: O(1) average, O(n) worst case
- Rehash: O(n)

## Space Complexity
O(n) - where n is the number of key-value pairs

## Load Factor
- If load factor > 0.75, rehash to larger table
- If load factor < 0.25, rehash to smaller table

## Example
```
Insert: ("name", "John") -> Hash: 5
Insert: ("age", 25) -> Hash: 2
Insert: ("city", "NYC") -> Hash: 8
Search: "name" -> "John"
Delete: "age"
```
