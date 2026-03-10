import java.util.*;

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isEnd = false;
}

class Trie {
    TrieNode root = new TrieNode();
    int count = 0;

    void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            node.children.putIfAbsent(c, new TrieNode());
            node = node.children.get(c);
        }
        if (!node.isEnd) {
            node.isEnd = true;
            count++;
        }
    }

    int totalWords() {
        return count;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        Trie trie = new Trie();
        for (int i = 0; i < n; i++) {
            String word = sc.nextLine();
            trie.insert(word);
        }
        System.out.println(trie.totalWords());
    }
}
