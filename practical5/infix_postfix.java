// Write your code here!!

import java.util.*;

public class InfixToPostfix {
    static int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    static String infixToPostfix(String expr) {
        Stack<Character> st = new Stack<>();
        StringBuilder result = new StringBuilder();

        for (char ch : expr.toCharArray()) {
            if (Character.isLetterOrDigit(ch)) {
                result.append(ch).append(' ');
            } else if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                while (!st.isEmpty() && st.peek() != '(')
                    result.append(st.pop()).append(' ');
                st.pop();
            } else {
                while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch) && ch != '^')
                    result.append(st.pop()).append(' ');
                st.push(ch);
            }
        }

        while (!st.isEmpty())
            result.append(st.pop()).append(' ');

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String expr = sc.next();
        System.out.println(infixToPostfix(expr));
    }
}
