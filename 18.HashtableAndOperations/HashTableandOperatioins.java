import java.util.Scanner;

class Node {
    int key;
    int value;
    Node next;

    Node(int key, int value) {
        this.key = key;
        this.value = value;
        this.next = null;
    }
}

class HashTable {
    int SIZE = 10;
    Node[] table;

    HashTable() {
        table = new Node[SIZE];
    }

    int hashFunc(int key) {
        return key % SIZE;
    }

    void insert(int key, int value) {
        int index = hashFunc(key);

        Node newNode = new Node(key, value);
        newNode.next = table[index];
        table[index] = newNode;

        System.out.println("Inserted: (" + key + "," + value + ")");
    }

    void deleteKey(int key) {
        int index = hashFunc(key);

        Node curr = table[index];
        Node prev = null;

        while (curr != null) {
            if (curr.key == key) {
                if (prev != null) {
                    prev.next = curr.next;
                } else {
                    table[index] = curr.next;
                }

                System.out.println("Key " + key + " deleted successfully.");
                return;
            }

            prev = curr;
            curr = curr.next;
        }

        System.out.println("Key " + key + " not found.");
    }

    void search(int key) {
        int index = hashFunc(key);

        Node curr = table[index];

        while (curr != null) {
            if (curr.key == key) {
                System.out.println(key + " -> " + curr.value);
                return;
            }
            curr = curr.next;
        }

        System.out.println("Key " + key + " not found.");
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            Node curr = table[i];

            if (curr != null) {
                System.out.print("Index " + i + ": ");
                while (curr != null) {
                    System.out.print("(" + curr.key + "," + curr.value + ") ");
                    curr = curr.next;
                }
                System.out.println();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        HashTable ht = new HashTable();

        while (true) {
            int choice = sc.nextInt();

            if (choice == 1) {
                int key = sc.nextInt();
                int value = sc.nextInt();
                ht.insert(key, value);
            }

            else if (choice == 2) {
                int key = sc.nextInt();
                ht.deleteKey(key);
            }

            else if (choice == 3) {
                int key = sc.nextInt();
                ht.search(key);
            }

            else if (choice == 4) {
                ht.display();
            }

            else if (choice == 5) {
                System.out.println("Exit");
                break;
            }
        }

        sc.close();
    }
}
