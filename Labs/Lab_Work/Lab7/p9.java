import java.util.PriorityQueue;

public class p9 {
    public class Node{
        int data;
        Node next;
        Node(int x)
        {
            data = x;
            next = null;
        }
    }
    public Node mergeLinkedList(int[] arr1,int[] arr2)
    {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0;i<arr1.length;i++)
        {
            pq.add(arr1[i]);
        }
        for(int i = 0;i<arr2.length;i++)
        {
            pq.add(arr2[i]);
        }
        Node head = new Node(pq.poll());
        while (!pq.isEmpty()) 
        {
            Node temp = head;
            while(temp.next != null)
            {
                temp = temp.next;
            }
            temp.next = new Node(pq.poll());
        }
        return head;
    }

    public static void main(String[] args) {
        int[] arr1 = {1,5,7};
        int[] arr2 = {4,10,19};
        p9 obj = new p9();
        p9.Node head = obj.mergeLinkedList(arr1, arr2);
        while(head != null)
        {
            System.out.print(head.data + " ");
            head = head.next;
        }
    }
}
