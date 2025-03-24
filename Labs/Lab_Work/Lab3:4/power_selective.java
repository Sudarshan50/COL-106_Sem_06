import java.util.Queue;
import java.util.Scanner;
import java.util.LinkedList;

public class power_selective {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i = 0;i<n;i++)
        {
            a[i] = sc.nextInt();
        }
        Queue<Integer> q = new LinkedList<>();
        //second greater elemenet....
        for(int i = 0;i<n;i++)
        {
            if(q.isEmpty())
            {
                q.add(a[i]);
            }
            else if(!q.isEmpty() && q.peek()>a[i])
            {
                q.add(a[i]);
            }
            else if(!q.isEmpty() && q.peek()<=a[i])
            {
                while(!q.isEmpty() && q.peek()<=a[i])
                {
                    q.poll();
                }
                if(q.isEmpty())
                {
                    q.add(a[i]);
                }
                else
                {
                    q.add(a[i]);
                }
            }
        }
        System.out.println();

    }    
}
