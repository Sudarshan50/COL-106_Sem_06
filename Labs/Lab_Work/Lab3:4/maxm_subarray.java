import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class maxm_subarray {
    public static void main(String[] args)
    {
        Scanner sc =  new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> arr = new ArrayList()<Integer>();
        for(int i = 0; i < n; i++)
        {
            arr.add(sc.nextInt());
        }
        Stack<Integer> leftMax = new Stack<Integer>();
        Stack<Integer> rightMax = new Stack<Integer>();
        for(int i = 0; i < n; i++)
        {
            
        }
    }
}
