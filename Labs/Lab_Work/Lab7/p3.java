import java.util.PriorityQueue;

public class p3 {
    public static void kSmallest(int[] arr, int k)
    {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0; i < arr.length; i++)
        {
            pq.add(arr[i]);
        }
        for(int i = 0; i < k; i++)
        {
            System.out.print(pq.poll() + " ");
        }
    }
    public static void main(String[] args) {
        int[] arr = {3,4,5,2,10};
        int k = 3;
        kSmallest(arr, k);
    }
}
