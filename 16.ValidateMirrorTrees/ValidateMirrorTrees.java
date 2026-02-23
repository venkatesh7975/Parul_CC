import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int d) { data = d; left = right = null; }
}

public class Main {
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

    static boolean isMirror(Node t1, Node t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (t1.data == t2.data) &&
               isMirror(t1.left, t2.right) &&
               isMirror(t1.right, t2.left);
    }

    public static void main(String[] args) {
        Node tree1 = buildTree();
        Node tree2 = buildTree();

        if (isMirror(tree1, tree2))
            System.out.println("The two trees are mirrors of each other.");
        else
            System.out.println("The two trees are not mirrors of each other.");
    }
}
