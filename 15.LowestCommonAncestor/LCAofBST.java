import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int val) { data = val; }
}

public class Main {
    static int index = 0;

    static Node buildTree(String[] nodes) {
        if (index >= nodes.length || nodes[index].equals("-1")) {
            index++;
            return null;
        }
        Node root = new Node(Integer.parseInt(nodes[index++]));
        root.left = buildTree(nodes);
        root.right = buildTree(nodes);
        return root;
    }

    static Node findLCA(Node root, int n1, int n2) {
        while (root != null) {
            if (root.data > n1 && root.data > n2) root = root.left;
            else if (root.data < n1 && root.data < n2) root = root.right;
            else break;
        }
        return root;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] line = sc.nextLine().split(" ");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();

        Node root = buildTree(line);
        Node lca = findLCA(root, n1, n2);

        if (lca != null) {
            System.out.println("The Lowest Common Ancestor of " + n1 + " and " + n2 + " is " + lca.data + ".");
        }
    }
}
