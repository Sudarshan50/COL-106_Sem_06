import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class stock_span {
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> arr = new ArrayList<Integer>();
        for(int i = 0; i < n; i++)
        {
            arr.add(sc.nextInt());
        }
        Stack<Integer> s = new Stack<Integer>();
        s.push(0);
        System.out.print(1 + " ");
        for(int i = 1; i < n; i++)
        {
            while(!s.isEmpty() && arr.get(s.peek()) <= arr.get(i))
            {
                s.pop();
            }
            int span = s.isEmpty() ? i + 1 : i - s.peek();
            System.out.print(span + " ");
            s.push(i);
        }
    }
}
