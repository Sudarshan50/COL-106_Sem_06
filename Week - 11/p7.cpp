#include<bits/stdc++.h>
using namespace std;    

enum Color {RED, BLACK};

class Node{
    public:
        int data;
        Node* parent;
        Node* left;
        Node* right; 
        Color color;

};

void joinRedBlack(Node* root1, Node* root2)
{
    if(root1 == NULL)
    {
        root1 = root2;
        return;
    }
    if(root2 == NULL)
        return;
    Node* temp = root1;
    Node* parent = NULL;
    while(temp != NULL)
    {
        parent = temp;
        if(temp->data > root2->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(parent->data > root2->data)
        parent->left = root2;
    else
        parent->right = root2;
}


void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int blackDepth(Node* root)
{
    if(root == NULL)
        return 0;
    int leftDepth = blackDepth(root->left);
    int rightDepth = blackDepth(root->right);
    int add = (root->color == BLACK) ? 1 : 0;
    return add + max(leftDepth, rightDepth);
}

bool isRedBlack(Node* root)
{
    if(root == NULL)
        return true;
    if(root->color == RED)
    {
        if(root->left != NULL && root->left->color == RED)
            return false;
        if(root->right != NULL && root->right->color == RED)
            return false;
    }
    int leftBlackDepth = blackDepth(root->left);
    int rightBlackDepth = blackDepth(root->right);
    if(leftBlackDepth != rightBlackDepth)
        return false;
    return isRedBlack(root->left) && isRedBlack(root->right);
}


signed main()
{
    Node* root = new Node();
    root->data = 10;
    root->color = BLACK;
    root->left = new Node();
    root->left->data = 5;
    root->left->color = RED;
    root->right = new Node();
    root->right->data = 20;
    root->right->color = RED;
    root->left->left = new Node();
    root->left->left->data = 3;
    root->left->left->color = BLACK;
    root->left->right = new Node();
    root->left->right->data = 7;
    root->left->right->color = BLACK;
    root->right->left = new Node();
    root->right->left->data = 15;
    root->right->left->color = BLACK;
    root->right->right = new Node();
    root->right->right->data = 25;
    root->right->right->color = BLACK;



    Node* root1 = new Node();
    root1->data = 20;
    root1->color = BLACK;
    root1->left = new Node();
    root1->left->data = 10;
    root1->left->color = RED;
    root1->right = new Node();
    root1->right->data = 40;
    root1->right->color = RED;
    root1->left->left = new Node();
    root1->left->left->data = 6;
    root1->left->left->color = BLACK;
    root1->left->right = new Node();
    root1->left->right->data = 14;
    root1->left->right->color = BLACK;
    root1->right->left = new Node();
    root1->right->left->data = 30;
    root1->right->left->color = BLACK;
    root1->right->right = new Node();
    root1->right->right->data = 50;
    root1->right->right->color = BLACK;



    inorder(root);
    cout<<"\n";
    inorder(root1);
    cout<<"\n";
    cout<<isRedBlack(root)<<"\n";
    cout<<isRedBlack(root1)<<"\n";

    joinRedBlack(root, root1);
    inorder(root);
    cout<<"\n";
    cout<<isRedBlack(root)<<"\n";
}