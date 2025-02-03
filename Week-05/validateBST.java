class Node{
    int value;
    Node left, right;

    public Node(int val) {
        this.value = val;
        this.left = this.right = null;
    }

    public static boolean validate(Node root,Node min,Node max)
    {
        if(root == null)
        {
            return true;
        }
        if(root.left != null && root.left.value > root.value)
        {
            return false;
        }
        if(root.right != null && root.right.value < root.value)
        {
            return false;
        }
        return validate(root.left,min,root) && validate(root.right,root,min) && validate(root.right,root,max);
    }
    public static void main(String[] args)
    {
        Node root = new Node(5);
        root.left = new Node(1);
        root.right = new Node(4);
        root.right.left = new Node(3);
        root.right.right = new Node(6);
        System.out.println(validate(root,null,null));
    }
}