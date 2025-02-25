package COL_106.Lab3;

import java.util.ArrayList;
import java.util.List;

public class min_stack {
    private List<Integer> minTillNow;
    private int size;
    private List<Integer> store;

    public min_stack ()
    {
        minTillNow = new ArrayList<>();
        size = 0;
        store = new ArrayList<>();
    }
    public void push(int x)
    {
        if(size == 0)
        {
            minTillNow.add(x);
        }
        else
        {
            if(x < minTillNow.get(size-1))
            {
                minTillNow.add(x);
            }
            else
            {
                minTillNow.add(minTillNow.get(size-1));
            }
        }
        store.add(x);
        size++;
    }
    public void pop()
    {
        if(size == 0)
        {
            System.out.println("Stack is empty");
        }
        else
        {
            store.remove(size-1);
            minTillNow.remove(size-1);
            size--;
        }
    }
    public int top()
    {
        if(size == 0)
        {
            System.out.println("Stack is empty");
            return -1;
        }
        return store.get(size-1);
    }
    public int getMin()
    {
        return minTillNow.get(size-1);
    }

    public static void main(String[] args)
    {
        min_stack stack = new min_stack();
        stack.push(3);
        stack.push(5);
        System.out.println("Current Min: " + stack.getMin()); // 3
        stack.push(2);
        stack.push(1);
        System.out.println("Current Min: " + stack.getMin()); // 1
        stack.pop();
        System.out.println("Current Min: " + stack.getMin()); // 2
        stack.pop();
        System.out.println("Top Element: " + stack.top()); // 5
        System.out.println("Current Min: " + stack.getMin()); // 3
    }
}
