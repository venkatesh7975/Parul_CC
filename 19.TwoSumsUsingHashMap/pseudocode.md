# Two Sums Using HashMap - Pseudocode

## Problem Statement
Given an array of integers and a target sum, find two elements that add up to the target.

## Algorithm

### Find Two Numbers that Sum to Target
```
FUNCTION twoSum(array, target):
    // Create a hashmap to store element and its index
    hashMap = empty map
    
    FOR i = 0 TO length(array) - 1:
        complement = target - array[i]
        
        // Check if complement exists in hashmap
        IF hashMap contains complement:
            RETURN [hashMap[complement], i]
        END IF
        
        // Store current element and its index
        hashMap[array[i]] = i
    END FOR
    
    PRINT "No pair found"
    RETURN null
END FUNCTION
```

### Find All Pairs that Sum to Target
```
FUNCTION twoSumAll(array, target):
    hashMap = empty map
    result = empty list
    
    FOR i = 0 TO length(array) - 1:
        complement = target - array[i]
        
        IF hashMap contains complement:
            result.add([array[i], complement])
        END IF
        
        IF hashMap does not contain array[i]:
            hashMap[array[i]] = 0
        END IF
        hashMap[array[i]] = hashMap[array[i]] + 1
    END FOR
    
    RETURN result
END FUNCTION
```

### Two Pointer Approach (Sorted Array)
```
FUNCTION twoSumSorted(sortedArray, target):
    left = 0
    right = length(sortedArray) - 1
    
    WHILE left < right:
        sum = sortedArray[left] + sortedArray[right]
        
        IF sum == target:
            RETURN [sortedArray[left], sortedArray[right]]
        ELSE IF sum < target:
            left = left + 1
        ELSE:
            right = right - 1
        END IF
    END WHILE
    
    PRINT "No pair found"
    RETURN null
END FUNCTION
```

### Find Unique Pairs
```
FUNCTION twoSumUnique(array, target):
    hashMap = empty map
    result = empty list
    seen = empty set
    
    FOR i = 0 TO length(array) - 1:
        complement = target - array[i]
        
        IF hashMap contains complement:
            // Create sorted pair to avoid duplicates
            pair = sort([complement, array[i]])
            IF pair not in seen:
                result.add(pair)
                seen.add(pair)
            END IF
        END IF
        
        hashMap[array[i]] = hashMap.get(array[i], 0) + 1
    END FOR
    
    RETURN result
END FUNCTION
```

## Time Complexity
- HashMap approach: O(n)
- Sorted two pointer: O(n log n) - for sorting
- Find all pairs: O(n)
- Find unique pairs: O(n)

## Space Complexity
- HashMap approach: O(n)
- Sorted approach: O(1) - if sorting in-place

## Example
```
Array: [2, 7, 11, 15]
Target: 9

Output: [0, 1] or [2, 7]
Explanation: 2 + 7 = 9

---

Array: [1, 2, 3, 4, 5]
Target: 7

All Pairs: [2, 5], [3, 4]
```
