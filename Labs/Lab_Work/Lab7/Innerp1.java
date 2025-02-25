


public class Innerp1 {
    public class Node{
        int data;
        Node left;
        Node right;
        Node(int x)
        {
            data = x;
            left = null;
            right = null;
        }
    }
    public class PrioityQueue{
        Node root;
        PrioityQueue()
        {
            root = null;
        }
        public void insert(int x)
        {
            Node insert = new Node(x);
            if(root == null)
            {
                root = insert;
            }
            else
            {
                Node temp = root;
                while(temp.left != null)
                {
                    temp = temp.left;
                }
                temp.left = insert;
            }
        }
        public int extractMax()
        {
            if(root == null)
            {
                throw new IllegalStateException("Heap is empty");
            }
            int max = root.data;
            root = (root.left.data > root.right.data) ? root.left : root.right;
            return max;
        }
        public int getMax()
        {
            if(root == null)
            {
                throw new IllegalStateException("Heap is empty");
            }
            return root.data;
        }
    }
    
}