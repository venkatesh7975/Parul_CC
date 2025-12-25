import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class MergePointLinkedList {

    // Build linked list from input, using nodeMap to share nodes
    public static Node buildList(Map<Integer, Node> nodeMap, Scanner sc) {
        Node head = null;
        Node tail = null;

        while (true) {
            int x = sc.nextInt();
            if (x == -1) break;

            Node newNode;
            if (nodeMap.containsKey(x)) {
                newNode = nodeMap.get(x);
            } else {
                newNode = new Node(x);
                nodeMap.put(x, newNode);
            }

            if (head == null) {
                head = tail = newNode;
            } else {
                tail.next = newNode;
                tail = newNode;
            }
        }

        return head;
    }

    // Get length of linked list
    public static int getLength(Node head) {
        int length = 0;
        while (head != null) {
            length++;
            head = head.next;
        }
        return length;
    }

    // Find merge point
    public static int findMergePoint(Node a, Node b) {
        int len1 = getLength(a);
        int len2 = getLength(b);

        int diff = Math.abs(len1 - len2);

        if (len1 > len2) {
            while (diff-- > 0) a = a.next;
        } else {
            while (diff-- > 0) b = b.next;
        }

        while (a != null && b != null) {
            if (a == b) {  // reference comparison
                return a.data;
            }
            a = a.next;
            b = b.next;
        }

        return -1;
    }

    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<Integer, Node> nodeMap = new HashMap<>();

        // Build two linked lists
        Node head1 = buildList(nodeMap, sc);
        Node head2 = buildList(nodeMap, sc);

        System.out.println(findMergePoint(head1, head2));
    }
}
