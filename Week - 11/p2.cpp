#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;
    Tree(int data){
        this->data = data;
        left = right = NULL;
    }
};

class AVLTree {
    public:
    Tree* root;
    AVLTree() { root = NULL; }
    //it is a bst...
    bool search(int key)
    {
        if(root == NULL)
            return false;
        Tree* temp = root;
        while(temp != NULL)
        {
            if(temp->data == key)
                return true;
            else if(temp->data > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }
    void insert(int ele)
    {
        Tree* temp = new Tree(ele);
        if(root == NULL)
        {
            root = temp;
            return;
        }
        Tree* parent = NULL;
        Tree* curr = root;
        while(curr != NULL)
        {
            parent = curr;
            if(curr->data > ele)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(parent->data > ele)
            parent->left = temp;
        else
            parent->right = temp;
    }
};

void inorder(Tree* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

signed main()
{
    AVLTree* obj = new AVLTree();
    obj->insert(10);
    obj->insert(5);
    obj->insert(20);
    obj->insert(3);
    obj->insert(7);
    obj->insert(15);
    obj->insert(25);
    inorder(obj->root);
    cout<<endl;
    if(obj->search(15))
        cout<<"Yes, 15 is present in the AVL tree"<<endl;
    else
        cout<<"No, 15 is not present in the AVL tree"<<endl;
    if(obj->search(100))
        cout<<"Yes, 100 is present in the AVL tree"<<endl;
    else
        cout<<"No, 100 is not present in the AVL tree"<<endl;
    return 0;
}

