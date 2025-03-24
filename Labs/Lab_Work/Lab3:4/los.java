import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class los{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        for(int i =0;i<n;i++)
        {
            a[i] = sc.nextInt();
        }
        Stack<Integer> s = new Stack<>();
        List<Integer> ans = new ArrayList<>();
        for(int i = n-1;i>=0;i--)
        {
            if(s.isEmpty())
            {
                ans.add(-1);
            }
            else if(!s.isEmpty() && s.peek()>a[i])
            {
                ans.add(s.peek());
            }
            else if(!s.isEmpty() && s.peek()<=a[i])
            {
                while(!s.isEmpty() && s.peek()<=a[i])
                {
                    s.pop();
                }
                if(s.isEmpty())
                {
                    ans.add(-1);
                }
                else
                {
                    ans.add(s.peek());
                }
            }
            s.push(a[i]);
        }
        for(int i = ans.size()-1;i>=0;i--)
        {
            System.out.print(ans.get(i)+" ");
        }
        System.out.println();

    }
}