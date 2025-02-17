import java.util.PriorityQueue;

public class p6 {
    public static void SweetCookieMaggie(int[] arr,int k)
    {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0;i<arr.length;i++)
        {
            pq.add(arr[i]);
        }
        int cnt = 0;
        while(!pq.isEmpty())
        {
            if(pq.peek() == 0)
            {
                System.out.println(-1);
                return;
            }
            if(pq.peek() >= k)
            {
                break;
            }
            int top1 = pq.poll();
            int top2 = pq.poll();
            int newCookie = top1 + 2*top2;
            pq.add(newCookie);
            cnt++;
        }
        System.out.println(cnt);
    }
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        int k = 9;
        SweetCookieMaggie(arr, k);
    }
}
