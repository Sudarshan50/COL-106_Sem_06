package COL_106.Lab3;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class validate_sequence {

    public boolean validate(List<Integer> l1, List<Integer> l2) {
        int n = l1.size();
        boolean flag = true;
        int it1 = 0;
        int it2 = n-1;
        while(it1<it2)
        {
            if(l1.get(it1) != l2.get(it2))
            {
                flag = false;
                break;
            }
            it1++;
            it2--;
        }
        return flag;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> l1  = new ArrayList<Integer>();
        List<Integer> l2  = new ArrayList<Integer>();
        for(int i = 0;i<n;i++)
        {
            l1.add(sc.nextInt());
        }   
        for(int i = 0;i<n;i++)
        {
            l2.add(sc.nextInt());
        }
        validate_sequence vs = new validate_sequence();
        boolean result = vs.validate(l1, l2);
        System.out.println(result);
    }
}
