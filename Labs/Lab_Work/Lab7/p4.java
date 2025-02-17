import java.util.ArrayList;
import java.util.PriorityQueue;

public class p4 {
    public static void meadianInput(int[] arr) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < arr.length; i++) {
            pq.add(arr[i]);
            
        }
    }

    public static void main(String[] args) {
        int[] arr = { 5, 6, 9, 10, 1, 2 };
        meadianInput(arr);
    }
}
