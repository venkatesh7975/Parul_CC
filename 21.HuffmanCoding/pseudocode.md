# Huffman Coding - Pseudocode

## Problem Statement
Implement Huffman Coding for data compression by assigning variable-length codes based on frequency.

## Data Structure
```
Node:
  - character: Character
  - frequency: Frequency of character
  - left: Pointer to left child
  - right: Pointer to right child

HuffmanCoding:
  - root: Root of Huffman Tree
  - huffmanCodes: Map of character to its code
```

## Algorithm

### Build Huffman Tree
```
FUNCTION buildHuffmanTree(frequencies):
    // Create priority queue (min-heap) of nodes
    minHeap = empty priority queue
    
    // Insert each character with its frequency
    FOR each character and its frequency:
        node = new Node(character, frequency)
        minHeap.insert(node)
    END FOR
    
    // Build tree by combining minimum frequency nodes
    WHILE minHeap.size() > 1:
        leftNode = minHeap.deleteMin()
        rightNode = minHeap.deleteMin()
        
        // Create parent node with combined frequency
        parentNode = new Node(null, leftNode.frequency + rightNode.frequency)
        parentNode.left = leftNode
        parentNode.right = rightNode
        
        minHeap.insert(parentNode)
    END WHILE
    
    // Root is the last node in heap
    IF minHeap.size() == 1:
        root = minHeap.deleteMin()
    ELSE:
        PRINT "Invalid frequencies"
        RETURN null
    END IF
    
    RETURN root
END FUNCTION
```

### Generate Huffman Codes
```
FUNCTION generateHuffmanCodes(root):
    huffmanCodes = empty map
    code = empty string
    
    generateCodesHelper(root, code, huffmanCodes)
    
    RETURN huffmanCodes
END FUNCTION
```

### Generate Codes Helper
```
FUNCTION generateCodesHelper(node, code, huffmanCodes):
    IF node == null:
        RETURN
    END IF
    
    // If leaf node, store the code
    IF node.character != null:
        huffmanCodes[node.character] = code
        RETURN
    END IF
    
    // Traverse left with code += "0"
    generateCodesHelper(node.left, code + "0", huffmanCodes)
    
    // Traverse right with code += "1"
    generateCodesHelper(node.right, code + "1", huffmanCodes)
END FUNCTION
```

### Encode Text
```
FUNCTION encodeText(text, huffmanCodes):
    encodedText = empty string
    
    FOR each character in text:
        encodedText = encodedText + huffmanCodes[character]
    END FOR
    
    RETURN encodedText
END FUNCTION
```

### Decode Text
```
FUNCTION decodeText(encodedText, root):
    decodedText = empty string
    current = root
    
    FOR each bit in encodedText:
        IF bit == '0':
            current = current.left
        ELSE:
            current = current.right
        END IF
        
        // If leaf node found
        IF current.character != null:
            decodedText = decodedText + current.character
            current = root
        END IF
    END FOR
    
    RETURN decodedText
END FUNCTION
```

### Calculate Compression Ratio
```
FUNCTION calculateCompressionRatio(originalText, encodedText):
    originalSize = length(originalText) * 8  // Assuming 8 bits per character
    compressedSize = length(encodedText)
    
    ratio = (1 - (compressedSize / originalSize)) * 100
    
    PRINT "Original size:", originalSize, "bits"
    PRINT "Compressed size:", compressedSize, "bits"
    PRINT "Compression ratio:", ratio, "%"
    
    RETURN ratio
END FUNCTION
```

## Time Complexity
- Build tree: O(n log n)
- Generate codes: O(n)
- Encode: O(m) - where m is length of text
- Decode: O(m * k) - where k is average code length

## Space Complexity
O(n) - for the tree and codes map

## Example
```
Text: "aabbbcccc"
Frequencies: {'a': 2, 'b': 3, 'c': 4}

Huffman Tree:
           9
          / \
         4   c(4)
        / \
      a(2) b(3)

Huffman Codes: {'c': '0', 'b': '10', 'a': '11'}

Original: aabbbcccc (72 bits)
Encoded: 11110101010000 (14 bits)
Compression: 80.6%
```
