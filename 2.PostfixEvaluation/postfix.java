import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String expr = sc.nextLine();
        Stack<Integer> stack = new Stack<>();

        try {
            String[] tokens = expr.trim().split("\\s+");

            for (String token : tokens) {

                // token.startswith('-') and token[1:].isdigit()
                if (token.startsWith("-") && token.length() > 1 && token.substring(1).matches("\\d+")) {
                    stack.push(Integer.parseInt(token));
                }
                // token.isdigit()
                else if (token.matches("\\d+")) {
                    stack.push(Integer.parseInt(token));
                }
                else {
                    if (stack.size() < 2) {
                        throw new Exception();
                    }

                    int b = stack.pop();
                    int a = stack.pop();

                    switch (token) {
                        case "+":
                            stack.push(a + b);
                            break;

                        case "-":
                            stack.push(a - b);
                            break;

                        case "*":
                            stack.push(a * b);
                            break;

                        case "/":
                            if (b == 0) {
                                System.out.println("Error: Division by zero.");
                                 System.out.println("Evaluation failed due to errors in the expression.");
                                return;   // equivalent of Python's exit()
                            }
                            stack.push(a / b);   // integer division (truncate toward zero)
                            break;

                        default:
                            throw new Exception();
                    }
                }
            }

            if (stack.size() != 1) {
                throw new Exception();
            }

            System.out.println(stack.peek());

        } catch (Exception e) {
            System.out.println("Evaluation failed due to errors in the expression.");
        }

        sc.close();
    }
}
