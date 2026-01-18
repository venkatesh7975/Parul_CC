import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class Main {
    static Scanner sc = new Scanner(System.in);

    // Build tree from preorder input
    static Node buildTree() {
        if (!sc.hasNextInt()) return null;
        int val = sc.nextInt();
        if (val == -1) return null;

        Node root = new Node(val);
        root.left = buildTree();
        root.right = buildTree();
        return root;
    }

    // Compute maximum depth
    static int maxDepth(Node root) {
        if (root == null)
            return 0;
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        return Math.max(leftDepth, rightDepth) + 1;
    }

    public static void main(String[] args) {
        Node root = buildTree();
        System.out.print(maxDepth(root));
    }
}
