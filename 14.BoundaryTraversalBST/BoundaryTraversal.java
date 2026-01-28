import java.util.*;

class Node {
    int val;
    Node left, right;
    Node(int v) { val = v; left = right = null; }
}

public class Main {
    static Node buildTree(List<Integer> vals, int[] idx) {
        if (idx[0] >= vals.size() || vals.get(idx[0]) == -1) {
            idx[0]++;
            return null;
        }
        Node root = new Node(vals.get(idx[0]++));
        root.left = buildTree(vals, idx);
        root.right = buildTree(vals, idx);
        return root;
    }

    static void printLeaves(Node root, List<Integer> res) {
        if (root == null) return;
        printLeaves(root.left, res);
        if (root.left == null && root.right == null)
            res.add(root.val);
        printLeaves(root.right, res);
    }

    static List<Integer> boundaryTraversal(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        res.add(root.val);

        // Left boundary
        Node node = root.left;
        while (node != null) {
            if (node.left != null || node.right != null)
                res.add(node.val);
            node = (node.left != null) ? node.left : node.right;
        }

        // Leaf nodes
        printLeaves(root.left, res);
        printLeaves(root.right, res);

        // Right boundary
        List<Integer> rightNodes = new ArrayList<>();
        node = root.right;
        while (node != null) {
            if (node.left != null || node.right != null)
                rightNodes.add(node.val);
            node = (node.right != null) ? node.right : node.left;
        }
        Collections.reverse(rightNodes);
        res.addAll(rightNodes);

        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> vals = new ArrayList<>();
        while (sc.hasNextInt())
            vals.add(sc.nextInt());
        int[] idx = {0};
        Node root = buildTree(vals, idx);
        List<Integer> ans = boundaryTraversal(root);
        System.out.print("Boundary Traversal: ");
        for (int v : ans)
            System.out.print(v + " ");
    }
}
