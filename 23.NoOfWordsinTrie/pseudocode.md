# Number of Words in Trie - Pseudocode

## Problem Statement
Count the total number of words stored in a Trie data structure.

## Data Structure
```
TrieNode:
  - children: Map of character to TrieNode
  - isEndOfWord: Boolean flag
  - wordCount: Count of words ending at this node

Trie:
  - root: Root TrieNode
  - totalWords: Total number of words
```

## Algorithm

### Count Words in Trie
```
FUNCTION countWordsInTrie(root):
    IF root == null:
        RETURN 0
    END IF
    
    count = 0
    
    FOR each child in root.children.values():
        count = count + countWordsInTrie(child)
    END FOR
    
    IF root.isEndOfWord:
        count = count + 1
    END IF
    
    RETURN count
END FUNCTION
```

### Insert Word and Update Count
```
FUNCTION insertWord(word, root):
    node = root
    
    FOR each character in word:
        IF node.children does not contain character:
            node.children[character] = new TrieNode
        END IF
        node = node.children[character]
    END FOR
    
    IF NOT node.isEndOfWord:
        node.isEndOfWord = true
        root.wordCount = root.wordCount + 1
    END IF
    
    PRINT "Word inserted:", word
END FUNCTION
```

### Get Total Words with Prefix
```
FUNCTION getWordsWithPrefix(prefix, root):
    node = root
    
    FOR each character in prefix:
        IF node.children does not contain character:
            RETURN 0
        END IF
        node = node.children[character]
    END FOR
    
    RETURN countWordsInTrie(node)
END FUNCTION
```

### Delete Word and Update Count
```
FUNCTION deleteWord(word, root):
    RETURN deleteHelper(word, root, 0)
END FUNCTION
```

### Delete Helper with Count Update
```
FUNCTION deleteHelper(word, node, index):
    IF index == length(word):
        IF NOT node.isEndOfWord:
            RETURN false  // Word doesn't exist
        END IF
        
        node.isEndOfWord = false
        root.wordCount = root.wordCount - 1
        
        RETURN node.children.size() == 0
    END IF
    
    character = word[index]
    
    IF node.children does not contain character:
        RETURN false
    END IF
    
    childNode = node.children[character]
    shouldDeleteChild = deleteHelper(word, childNode, index + 1)
    
    IF shouldDeleteChild:
        node.children.remove(character)
        RETURN node.children.size() == 0 AND NOT node.isEndOfWord
    END IF
    
    RETURN false
END FUNCTION
```

### Get All Words
```
FUNCTION getAllWords(root):
    words = empty list
    word = empty string
    
    dfs(root, word, words)
    
    RETURN words
END FUNCTION
```

### DFS to Get All Words
```
FUNCTION dfs(node, word, words):
    IF node.isEndOfWord:
        words.add(word)
    END IF
    
    FOR each character in node.children.keys():
        dfs(node.children[character], word + character, words)
    END FOR
END FUNCTION
```

### Get Statistics
```
FUNCTION getTrieStatistics(root):
    totalWords = root.wordCount
    uniquePrefixes = countNodes(root)
    maxDepth = getMaxDepth(root)
    
    PRINT "Total words:", totalWords
    PRINT "Unique prefixes:", uniquePrefixes
    PRINT "Maximum depth:", maxDepth
    
    RETURN {totalWords, uniquePrefixes, maxDepth}
END FUNCTION
```

### Count Total Nodes
```
FUNCTION countNodes(node):
    IF node == null:
        RETURN 0
    END IF
    
    count = 1
    
    FOR each child in node.children.values():
        count = count + countNodes(child)
    END FOR
    
    RETURN count
END FUNCTION
```

### Get Maximum Depth
```
FUNCTION getMaxDepth(node):
    IF node == null:
        RETURN 0
    END IF
    
    maxDepth = 0
    
    FOR each child in node.children.values():
        maxDepth = max(maxDepth, getMaxDepth(child))
    END FOR
    
    RETURN maxDepth + 1
END FUNCTION
```

## Time Complexity
- Count words: O(n) - where n is number of nodes
- Insert: O(m) - where m is length of word
- Delete: O(m)
- Get words with prefix: O(n)

## Space Complexity
O(n) - for nodes in Trie

## Example
```
Words inserted: "apple", "app", "apply", "apricot"

Trie structure:
       root
        |
        a
        |
        p
       / \
      p   r
     /|   |
    l e   i
    |     |
    e     c
   (end)  |
          o
          |
          t
          (end)

Total words: 4
Words with prefix "app": 3 (app, apple, apply)
Words with prefix "apr": 1 (apricot)
```
