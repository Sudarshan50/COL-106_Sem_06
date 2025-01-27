import COL_106.Lab3.min_stack;
public class minQueue {
    private min_stack enqueueStack;
    private min_stack dequeueStack;

    public minQueue()
    {
        enqueueStack = new min_stack();
        dequeueStack = new min_stack();
    }

    public void enqueue(int x)
    {
        enqueueStack.push(x);
    }
    public void dequeue()
    {
        if(dequeueStack.size == 0)
        {
            while(enqueueStack.size != 0)
            {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }
        dequeueStack.pop();
    }
    public int front()
    {
        if(dequeueStack.size == 0)
        {
            while(enqueueStack.size != 0)
            {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }
        return dequeueStack.top();
    }
    public int getMin()
    {
        return Math.min(enqueueStack.getMin(),dequeueStack.getMin());
    }

    public static void main(String[] args)
    {
        minQueue q = new minQueue();
        q.enqueue(1);
        q.enqueue(2);
        System.out.println(q.getMin());
        q.dequeue();
        System.out.println(q.getMin());
    }
}
