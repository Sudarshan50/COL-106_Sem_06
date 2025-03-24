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
    (isRedBlack(root)) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}