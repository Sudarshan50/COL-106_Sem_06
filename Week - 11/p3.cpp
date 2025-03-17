#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node* formBST(vector<int> &a)
{
    Node* root = new Node(a[0]);
    for(int i=1; i<a.size(); i++)
    {
        Node* temp = new Node(a[i]);
        Node* parent = NULL;
        Node* curr = root;
        while(curr != NULL)
        {
            parent = curr;
            if(curr->data > a[i])
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(parent->data > a[i])
            parent->left = temp;
        else
            parent->right = temp;
    }
    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


signed main()
{
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    Node* root = formBST(a);
    inorder(root);
    cout<<"\n";
}