import java.util.*;

class TrieNode {
    TrieNode[] children = new TrieNode[26];
}

public class DistinctSubstringsTrie {
    static int insertSubstring(TrieNode root, String s, int start) {
        TrieNode curr = root;
        int newNodes = 0;
        for (int i = start; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';
            if (curr.children[idx] == null) {
                curr.children[idx] = new TrieNode();
                newNodes++;
            }
            curr = curr.children[idx];
        }
        return newNodes;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        TrieNode root = new TrieNode();
        int count = 0;

        for (int i = 0; i < s.length(); i++)
            count += insertSubstring(root, s, i);

        System.out.println(count);
    }
}
