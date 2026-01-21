import java.util.*;

class Node {
    String key;
    Node left, right;
    Node(String k) { key = k; left = right = null; }
}

public class Main {
    static Node insert(Node root, String key) {
        if (root == null) return new Node(key);
        if (key.compareTo(root.key) < 0)
            root.left = insert(root.left, key);
        else
            root.right = insert(root.right, key);
        return root;
    }

    static List<String> leftView(Node root) {
        List<String> res = new ArrayList<>();
        if (root == null) return res;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            res.add(q.peek().key);
            for (int i = 0; i < n; i++) {
                Node node = q.poll();
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        Node root = null;
        for (int i = 0; i < n; i++) {
            String keyword = sc.nextLine();
            root = insert(root, keyword);
        }
        List<String> res = leftView(root);
        for (String s : res)
            System.out.print(s + " ");
    }
}
