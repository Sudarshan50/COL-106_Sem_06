class Node {
    int value;
    Node left, right;

    public Node(int val) {
        this.value = val;
        this.left = this.right = null;
    }

    public static int search(int[] inorder, int val,int lft,int rgt) {
        for (int i = lft; i <= rgt; i++) {
            if (inorder[i] == val) return i;
        }
        return -1;
    }

    public static Node buildTree(int[] inorder, int[] preorder,int trk,int lft,int rgt) {
        if (lft > rgt) return null;
        Node root = new Node(preorder[trk]);
        trk++;
        int idx = search(inorder, root.value,lft,rgt);
        root.left = buildTree(inorder, preorder, trk, lft, idx - 1);
        root.right = buildTree(inorder, preorder, trk + idx - lft, idx + 1, rgt);
        return root;
    }

    public static void inorder(Node root)
    {
        if(root == null)
        {
            return;
        }
        inorder(root.left);
        System.out.print(root.value + " "); 
        inorder(root.right);
    }
    public static void preorder(Node root)
    {
        if(root == null)
        {
            return;
        }
        System.out.print(root.value + " ");
        preorder(root.left);
        preorder(root.right);
    }   
    public static void main(String[] args)
    {
        int[] inorder = {9, 3, 15, 20, 7};
        int[] preorder = {3, 9, 20, 15, 7};
        int trk = 0;

        Node root = buildTree(inorder, preorder,trk,0,inorder.length-1);
        inorder(root);
        System.out.println();
        preorder(root);
        System.out.println();
    }
}
