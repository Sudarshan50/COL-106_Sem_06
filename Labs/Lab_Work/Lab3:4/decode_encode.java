package COL_106.Lab3;

import java.util.Scanner;
import java.util.Stack;

public class decode_encode {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sh = sc.nextLine();
        String ans = "";
        int cnt = 0;
        Stack<String> st = new Stack<>();
        Stack<Integer> countStack = new Stack<>();

        for (int i = 0; i < sh.length(); i++) {
            char c = sh.charAt(i);

            if (Character.isDigit(c)) {
                cnt = cnt * 10 + (c - '0');
            } else if (c == '[') {
                st.push(ans);
                countStack.push(cnt);
                ans = "";
                cnt = 0;
            } else if (c == ']') {
                int times = countStack.pop();
                String temp = st.pop();
                StringBuilder sb = new StringBuilder(temp);
                for (int j = 0; j < times; j++) {
                    sb.append(ans);
                }
                ans = sb.toString();
            } else {
                ans += c;
            }
        }
        System.out.println(ans);
    }
}
