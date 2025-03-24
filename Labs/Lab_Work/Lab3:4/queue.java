package COL_106.Lab3;

import java.util.Stack;

public class queue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;

    public queue()
    {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }

    public void enqueue(int x)
    {
        stack1.push(x);
    }
    public void dequeue(){
        if(stack2.isEmpty()){
            while(!stack1.isEmpty()){
                stack2.push(stack1.pop());
            }
        }
        stack2.pop();
    }
    public int front()
    {
        if(stack2.isEmpty()){
            while(!stack1.isEmpty()){
                stack2.push(stack1.pop());
            }
        }
        return stack2.peek();
    }

    public boolean isEmpty()
    {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    public static void main(String[] args)
    {
        queue q = new queue();
        q.enqueue(1);
        q.enqueue(2);
        System.out.println(q.front());
        q.dequeue();
        System.out.println(q.front());
    }
}
