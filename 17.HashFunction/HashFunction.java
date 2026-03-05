import java.util.*;

class Node {
    int key, value;
    Node next;
    Node(int k, int v) { key = k; value = v; next = null; }
}

public class Main {
    static final int SIZE = 10;
    static Node[] table = new Node[SIZE];

    static int hashFunc(int key) {
        return key % SIZE;
    }

    static void insert(int key, int value) {
        int index = hashFunc(key);
        Node newNode = new Node(key, value);
        if (table[index] == null)
            table[index] = newNode;
        else {
            Node curr = table[index];
            while (curr.next != null)
                curr = curr.next;
            curr.next = newNode;
        }
        System.out.println("Inserted: (" + key + "," + value + ")");
    }

    static void get(int key) {
        int index = hashFunc(key);
        Node curr = table[index];
        while (curr != null) {
            if (curr.key == key) {
                System.out.println(key + " -> " + curr.value);
                return;
            }
            curr = curr.next;
        }
        System.out.println(key + " not found");
    }

    static void display() {
        for (int i = 0; i < SIZE; i++) {
            System.out.print(i + ": ");
            Node curr = table[i];
            if (curr == null) {
                System.out.println("NULL");
            } else {
                while (curr != null) {
                    System.out.print("(" + curr.key + "," + curr.value + ")-> ");
                    curr = curr.next;
                }
                System.out.println("NULL");
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int op = sc.nextInt();
            if (op == 1) {
                int key = sc.nextInt(), value = sc.nextInt();
                insert(key, value);
            } else if (op == 2) {
                int key = sc.nextInt();
                get(key);
            } else if (op == 3) {
                display();
            } else if (op == 4) {
                System.out.println("Exit");
                break;
            }
        }
        sc.close();
    }
}
