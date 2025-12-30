import java.util.*;

public class NGE {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] nge = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            nge[i] = -1; // initialize NGE
        }

        Stack<Integer> stack = new Stack<>();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop elements <= current
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }

            // If stack is not empty → top is NGE
            if (!stack.isEmpty()) {
                nge[i] = stack.peek();
            }

            // Push current element
            stack.push(arr[i]);
        }

        // Print output in same format as Python
        for (int i = 0; i < n; i++) {
            System.out.println("NGE of " + arr[i] + " is " + nge[i]);
        }

        sc.close();
    }
}
