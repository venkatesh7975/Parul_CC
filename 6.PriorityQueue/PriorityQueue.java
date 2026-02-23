import java.util.*;

public class TopThreeProduct {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < n; i++) {
            set.add(sc.nextInt());
        }

        if (set.size() < 3) {
            System.out.println(-1);
            return;
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        pq.addAll(set);

        int a = pq.poll();
        int b = pq.poll();
        int c = pq.poll();

        System.out.println(a * b * c);
    }
}
