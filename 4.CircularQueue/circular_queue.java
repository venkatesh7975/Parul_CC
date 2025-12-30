import java.util.Scanner;

public class CircularQueue {
    int k;              // Size of the queue
    int front = -1;     // Front of the queue
    int rear = -1;      // Rear of the queue
    int[] queue;        // Array to store queue elements
    
    // Constructor to initialize the queue with the given size
    public CircularQueue(int size) {
        k = size;
        queue = new int[k];
    }
    
    // Enqueue function
    public void enqueue(int x) {
        // Check overflow
        if ((rear + 1) % k == front) {
            System.out.println("Queue Overflow");
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % k;
        queue[rear] = x;
        System.out.println("Enqueued " + x);
    }
    
    // Dequeue function
    public void dequeue() {
        // Check underflow
        if (front == -1) {
            System.out.println("Queue Underflow");
            return;
        }
        System.out.println("Dequeued " + queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % k;
        }
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        CircularQueue queue = new CircularQueue(k);
        
        while (scanner.hasNextInt()) {
            int x = scanner.nextInt();
            if (x >= 0) {
                queue.enqueue(x);
            } else if (x == -1) {
                queue.dequeue();
            }
        }
        scanner.close();
    }
}
