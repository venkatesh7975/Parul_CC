import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int d) {
        data = d;
        left = right = null;
    }
}

public class ValidateBST {

    static Scanner sc = new Scanner(System.in);

    static Node buildTree() {
        if (!sc.hasNextInt()) return null;
        int val = sc.nextInt();
        if (val == -1) return null;

        Node node = new Node(val);
        node.left = buildTree();
        node.right = buildTree();
        return node;
    }

    static boolean isValidBST(Node root, long min, long max) {
        if (root == null) return true;
        if (root.data <= min || root.data >= max) return false;
        return isValidBST(root.left, min, root.data) &&
               isValidBST(root.right, root.data, max);
    }

    public static void main(String[] args) {
        Node root = buildTree();
        System.out.print(isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE) ? "True" : "False");
    }
}
