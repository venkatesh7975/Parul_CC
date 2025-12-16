import java.util.*;
 
class ListNode {
    int value;
    ListNode next;
    ListNode(int val) { this.value = val; }
}
 
public class Main {
 
    // Read linked list until -1
    public static ListNode readLinkedList(Scanner sc) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while (sc.hasNextInt()) {
            int val = sc.nextInt();
            if (val == -1) break;
            tail.next = new ListNode(val);
            tail = tail.next;
        }
        return dummy.next;
    }
 
    // Merge two sorted linked lists
    public static ListNode mergeSortedLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
 
        while (l1 != null && l2 != null) {
            if (l1.value <= l2.value) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
 
        tail.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }
 
    // Print linked list
    public static void printLinkedList(ListNode head) {
        boolean first = true;
        while (head != null) {
            if (!first) System.out.print(" ");
            System.out.print(head.value);
            first = false;
            head = head.next;
        }
        System.out.println();
    }
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        ListNode l1 = readLinkedList(sc);
        ListNode l2 = readLinkedList(sc);
 
        ListNode merged = mergeSortedLists(l1, l2);
        printLinkedList(merged);
 
        sc.close();
    }
}