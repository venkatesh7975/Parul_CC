import java.util.*;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isEnd;
}

class Trie {
    TrieNode root = new TrieNode();

    void insert(String word) {
        TrieNode node = root;
        for (char ch : word.toCharArray())
            node = node.children.computeIfAbsent(ch, c -> new TrieNode());
        node.isEnd = true;
        System.out.println("Inserted: " + word);
    }

    boolean search(String word) {
        TrieNode node = root;
        for (char ch : word.toCharArray()) {
            node = node.children.get(ch);
            if (node == null) return false;
        }
        return node.isEnd;
    }

    boolean removeHelper(TrieNode node, String word, int depth) {
        if (node == null) return false;
        if (depth == word.length()) {
            if (!node.isEnd) return false;
            node.isEnd = false;
            return node.children.isEmpty();
        }
        char ch = word.charAt(depth);
        TrieNode next = node.children.get(ch);
        if (removeHelper(next, word, depth + 1)) {
            node.children.remove(ch);
            return !node.isEnd && node.children.isEmpty();
        }
        return false;
    }

    void remove(String word) {
        if (!search(word))
            System.out.println("Not found: " + word);
        else {
            removeHelper(root, word, 0);
            System.out.println("Removed: " + word);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Trie trie = new Trie();

        while (sc.hasNextInt()) {
            int choice = sc.nextInt();
            if (choice == 4) break;
            String word = sc.next();
            switch (choice) {
                case 1 -> trie.insert(word);
                case 2 -> System.out.println((trie.search(word) ? "Found: " : "Not found: ") + word);
                case 3 -> trie.remove(word);
            }
        }
        sc.close();
    }
}
