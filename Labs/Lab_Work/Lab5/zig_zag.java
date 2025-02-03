import java.util.Stack;

class Node {
    int value;
    Node left, right;

    public Node(int val) {
        this.value = val;
        this.left = this.right = null;
    }

    public static void zigzag(Node root) {
        if (root == null) return;

        Stack<Node> curr = new Stack<>();
        Stack<Node> nxt = new Stack<>();
        boolean flag = true;

        curr.push(root);

        while (!curr.isEmpty()) {
            Node node = curr.pop();
            System.out.print(node.value + " ");

            if (flag) {
                if (node.left != null) nxt.push(node.left);
                if (node.right != null) nxt.push(node.right);
            } else {
                if (node.right != null) nxt.push(node.right);
                if (node.left != null) nxt.push(node.left);
            }

            if (curr.isEmpty()) {
                flag = !flag;
                Stack<Node> temp = curr;
                curr = nxt;
                nxt = temp;
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node root = new Node(3);
        root.left = new Node(9);
        root.right = new Node(20);
        root.right.right = new Node(7);
        root.right.left = new Node(15);
        zigzag(root);
    }
}
