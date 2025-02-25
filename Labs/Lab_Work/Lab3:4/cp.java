import java.util.Scanner;

public class cp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- >0)
        {
            int n = sc.nextInt();
            if(n<=2)
            {
                System.out.println(n);
            }else{
                int temp = n;
                while(temp>2)
                {
                    temp = temp/2;
                }
                System.out.println(n/temp);
            }
        }
    }
}
