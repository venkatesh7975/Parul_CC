import java.util.*;

class Device {
    int id;
    Device left, right;
    Device(int val) { id = val; }
}

public class Main {
    static Scanner sc = new Scanner(System.in);

    static Device buildNetwork() {
        int val = sc.nextInt();
        if (val == -1) return null;
        Device d = new Device(val);
        d.left = buildNetwork();
        d.right = buildNetwork();
        return d;
    }

    static void levelOrder(Device root) {
        if (root == null) return;
        Queue<Device> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Device d = q.poll();
            System.out.print(d.id + " ");
            if (d.left != null) q.add(d.left);
            if (d.right != null) q.add(d.right);
        }
    }

    public static void main(String[] args) {
        Device root = buildNetwork();
        levelOrder(root);
    }
}
