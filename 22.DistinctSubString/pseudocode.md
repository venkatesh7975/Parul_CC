# Distinct Substrings - Pseudocode

## Problem Statement
Find all distinct substrings of a given string.

## Algorithm

### Find All Distinct Substrings
```
FUNCTION findDistinctSubstrings(string):
    n = length(string)
    substrings = empty set
    
    FOR i = 0 TO n - 1:
        FOR j = i + 1 TO n:
            substring = string[i:j]
            substrings.add(substring)
        END FOR
    END FOR
    
    RETURN substrings
END FUNCTION
```

### Find Count of Distinct Substrings
```
FUNCTION countDistinctSubstrings(string):
    n = length(string)
    substrings = empty set
    
    // Add empty string
    substrings.add("")
    
    FOR i = 0 TO n - 1:
        FOR j = i + 1 TO n:
            substring = string[i:j]
            substrings.add(substring)
        END FOR
    END FOR
    
    RETURN substrings.size()
END FUNCTION
```

### Using Suffix Array (Optimized)
```
FUNCTION findDistinctSubstringsUsingSuffixArray(string):
    n = length(string)
    suffixes = empty list
    
    // Create all suffixes
    FOR i = 0 TO n - 1:
        suffixes.add(string[i:n])
    END FOR
    
    // Sort suffixes
    sort(suffixes)
    
    count = 0
    prevCommon = 0
    
    FOR i = 0 TO length(suffixes) - 1:
        // Calculate LCP (Longest Common Prefix) with previous suffix
        lcp = getLongestCommonPrefix(suffixes[i], suffixes[i-1])
        
        // All substrings of current suffix except LCP are new
        count = count + (n - startIndex(suffixes[i]) - lcp)
    END FOR
    
    RETURN count
END FUNCTION
```

### Get Longest Common Prefix
```
FUNCTION getLongestCommonPrefix(str1, str2):
    i = 0
    WHILE i < length(str1) AND i < length(str2) AND str1[i] == str2[i]:
        i = i + 1
    END WHILE
    
    RETURN i
END FUNCTION
```

### Display Substrings by Length
```
FUNCTION displaySubstringsByLength(string):
    n = length(string)
    
    FOR len = 1 TO n:
        PRINT "Substrings of length", len, ":"
        FOR i = 0 TO n - len:
            PRINT string[i:i+len]
        END FOR
    END FOR
END FUNCTION
```

## Time Complexity
- Brute force: O(n² log n) - for finding and storing in set
- Using suffix array: O(n log n) - with optimal suffix sorting

## Space Complexity
O(n²) - for storing all substrings

## Example
```
String: "abc"

All distinct substrings:
"", "a", "ab", "abc", "b", "bc", "c"

Count: 7 (or 6 if empty string not included)

---

String: "aab"

All distinct substrings:
"a", "aa", "aab", "ab", "b"

Count: 5
```
