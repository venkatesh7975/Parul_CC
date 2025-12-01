import java.util.*;
import java.util.stream.Collectors;

public class Main { // Line 7

    static class TreeNode {
        int val;
        TreeNode left, right;
        // FIX 1: Added semicolon
        public TreeNode(int val) { this.val = val; } 
        public boolean isLeaf() { return left == null && right == null; }
    }

    private static int preIndex = 0;
    private static List<Integer> result = new ArrayList<>();

    // BST Construction
    private static TreeNode buildBST(List<Integer> preorder, int min, int max) {
        if (preIndex >= preorder.size()) return null;
        int rootVal = preorder.get(preIndex);
        if (rootVal < min || rootVal > max) return null;
        
        preIndex++;
        TreeNode root = new TreeNode(rootVal);
        root.left = buildBST(preorder, min, rootVal);
        root.right = buildBST(preorder, rootVal, max);
        return root;
    }

    // Left boundary (Top-down, excluding leaves)
    private static void printLeftBoundary(TreeNode root) {
        TreeNode curr = root.left;
        while (curr != null) {
            if (!curr.isLeaf()) result.add(curr.val);
            // FIX 2: Corrected ternary operator (added ?)
            curr = (curr.left != null) ? curr.left : curr.right; 
        }
    }

    // Leaf nodes (Left-to-right)
    private static void printLeaves(TreeNode root) {
        if (root == null) return;
        if (root.isLeaf()) {
            result.add(root.val);
            return;
        }
        printLeaves(root.left);
        printLeaves(root.right);
    }

    // Right boundary (Bottom-up, excluding leaves)
    private static void printRightBoundary(TreeNode root) {
        TreeNode curr = root.right;
        Stack<Integer> stack = new Stack<>();
        while (curr != null) {
            if (!curr.isLeaf()) stack.push(curr.val);
            // FIX 3: Corrected ternary operator (added ?)
            curr = (curr.right != null) ? curr.right : curr.left; 
        }
        while (!stack.isEmpty()) {
            result.add(stack.pop());
        }
    }

    // Main Boundary Traversal Logic
    private static List<Integer> boundaryTraversal(TreeNode root) {
        result.clear();
        if (root == null) return result;

        if (!root.isLeaf()) {
            result.add(root.val);
        }

        printLeftBoundary(root);
        printLeaves(root);
        printRightBoundary(root);

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine(); 
        scanner.close();

        // Parse input, filter out -1
        List<Integer> inputPreorder = Arrays.stream(line.split("\\s+"))
            .map(Integer::parseInt)
            .filter(val -> val != -1) 
            .collect(Collectors.toList());

        if (inputPreorder.isEmpty()) {
            System.out.println("Boundary Traversal:");
            return;
        }

        preIndex = 0;
        TreeNode root = buildBST(inputPreorder, Integer.MIN_VALUE, Integer.MAX_VALUE);
        
        List<Integer> traversalResult = boundaryTraversal(root);
        
        String output = traversalResult.stream()
            .map(String::valueOf)
            .collect(Collectors.joining(" "));
            
        System.out.println("Boundary Traversal: " + output);
    } // Closing brace for main method
} // Closing brace for Main class (Fix 4: This was likely missing)