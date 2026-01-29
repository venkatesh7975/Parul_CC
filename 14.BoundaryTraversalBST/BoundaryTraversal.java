import java.util.*;

class Main {
    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; left = right = null; }
    }

    static Node insertBST(Node root, int val){
        if(root == null) return new Node(val);
        if(val < root.val) root.left = insertBST(root.left, val);
        else root.right = insertBST(root.right, val);
        return root;
    }

    static boolean isLeaf(Node root){ return root != null && root.left == null && root.right == null; }

    static void leftBoundary(Node root){
        if(root == null) return;
        if(root.left != null){ 
            System.out.print(root.val + " "); 
            leftBoundary(root.left); 
        }
        else if(root.right != null){ 
            System.out.print(root.val + " "); 
            leftBoundary(root.right);
        }
    }

    static void rightBoundary(Node root){
        if(root == null) return;
        if(root.right != null){ 
            rightBoundary(root.right); 
            System.out.print(root.val + " "); 
        }
        else if(root.left != null){ 
            rightBoundary(root.left); 
            System.out.print(root.val + " "); 
        }
    }

    static void printLeaves(Node root){
        if(root == null) return;
        printLeaves(root.left);
        if(isLeaf(root)) System.out.print(root.val + " ");
        printLeaves(root.right);
    }

    static void boundaryTraversal(Node root){
        if(root == null) return;
        System.out.print(root.val + " "); // root
        leftBoundary(root.left);
        printLeaves(root.left);
        printLeaves(root.right);
        rightBoundary(root.right);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Node root = null;
        while(sc.hasNextInt()){
            int val = sc.nextInt();
            if(val == -1) break;
            root = insertBST(root, val);
        }
        System.out.print("Boundary Traversal: ");
        boundaryTraversal(root);
        System.out.println();
    }
}
