import java.util.*;

class Node {
    char ch;
    int freq;
    Node left, right;
    char smallestChar;
    Node(char c, int f) {
        ch = c; freq = f;
        smallestChar = c;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] chars = new char[n];
        int[] freq = new int[n];
        for (int i = 0; i < n; i++) chars[i] = sc.next().charAt(0);
        for (int i = 0; i < n; i++) freq[i] = sc.nextInt();

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
            if (a.freq == b.freq)
                return Character.compare(a.smallestChar, b.smallestChar);
            return a.freq - b.freq;
        });

        for (int i = 0; i < n; i++)
            pq.add(new Node(chars[i], freq[i]));

        while (pq.size() > 1) {
            Node left = pq.poll();
            Node right = pq.poll();
            Node merged = new Node('$', left.freq + right.freq);
            merged.left = left;
            merged.right = right;
            merged.smallestChar = (char)Math.min(left.smallestChar, right.smallestChar);
            pq.add(merged);
        }

        Map<Character, String> codes = new HashMap<>();
        buildCodes(pq.peek(), "", codes);

        System.out.println("Huffman Codes:");
        for (char c : chars)
            System.out.println(c + ": " + codes.get(c));
    }

    static void buildCodes(Node root, String code, Map<Character, String> map) {
        if (root == null) return;
        if (root.left == null && root.right == null) {
            map.put(root.ch, code);
            return;
        }
        buildCodes(root.left, code + "0", map);
        buildCodes(root.right, code + "1", map);
    }
}
