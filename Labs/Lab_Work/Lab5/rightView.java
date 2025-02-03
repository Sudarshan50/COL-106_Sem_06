import java.util.LinkedList;
import java.util.Queue;

class  Node{
    int value;
    Node left, right;
    public Node(int val) {
        this.value = val;
        this.left = this.right = null;
    }


    public static void rightView(Node root)
    {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                Node curr = q.poll();
                if(i == sz - 1)
                {
                    System.out.print(curr.value + " ");
                }
                if(curr.left != null)
                {
                    q.add(curr.left);
                }
                if(curr.right != null)
                {
                    q.add(curr.right);
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args)
    {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.right.right = new Node(4);
        root.right.left = new Node(5);
        rightView(root);
    }
}
