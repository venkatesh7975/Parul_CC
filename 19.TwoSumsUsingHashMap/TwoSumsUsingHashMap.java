import java.util.*;

public class TwoSumHash {
    static class Node {
        int key, value;
        Node next;
        Node(int k, int v) { key = k; value = v; }
    }

    static final int SIZE = 100003;
    static Node[] hashTable = new Node[SIZE];

    static int hashFunc(int key) {
        return Math.abs(key) % SIZE;
    }

    static void insert(int key, int value) {
        int index = hashFunc(key);
        Node newNode = new Node(key, value);
        newNode.next = hashTable[index];
        hashTable[index] = newNode;
    }

    static int search(int key) {
        int index = hashFunc(key);
        Node curr = hashTable[index];
        while (curr != null) {
            if (curr.key == key) return curr.value;
            curr = curr.next;
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        int target = sc.nextInt();

        System.out.println("Finding two indices whose values add up to " + target + "...");
        Arrays.fill(hashTable, null);
        boolean found = false;

        for (int i = 0; i < n; i++) {
            int complement = target - arr[i];
            int compIndex = search(complement);
            if (compIndex != -1) {
                System.out.println("Indices: " + compIndex + " " + i);
                found = true;
                break;
            }
            insert(arr[i], i);
        }

        if (!found) System.out.println("No solution found");
    }
}
