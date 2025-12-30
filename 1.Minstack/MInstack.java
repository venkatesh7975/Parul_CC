import java.util.*;

public class Main {

    static int[] stack;
    static int[] minstack;
    static int top = -1;
    static int mintop = -1;
    static int N;

    static void push(int value) {
        if (top == N - 1) {
            System.out.println("overflow");
            return;
        }

        stack[++top] = value;

        if (mintop == -1 || value <= minstack[mintop]) {
            minstack[++mintop] = value;
        }

        System.out.println("Pushed " + value);
    }

    static void pop() {
        if (top == -1) {
            System.out.println("underflow");
            return;
        }

        if (stack[top] == minstack[mintop]) {
            mintop--;
        }

        top--;
    }

    static void Top() {
        if (top == -1) {
            System.out.println("stack is empty");
            return;
        }
        System.out.println("Top: " + stack[top]);
    }

    static void getMin() {
        if (mintop == -1) {
            System.out.println("Minstack empty");
            return;
        }
        System.out.println("Min: " + minstack[mintop]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        stack = new int[N];
        minstack = new int[N];

        while (true) {
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    int val = sc.nextInt();
                    push(val);
                    break;

                case 2:
                    pop();
                    break;

                case 3:
                    Top();
                    break;

                case 4:
                    getMin();
                    break;

                case 5:
                    System.out.println("Exit");
                    return;
            }
        }
    }
}
