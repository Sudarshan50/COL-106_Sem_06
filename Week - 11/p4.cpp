#include<bits/stdc++.h>
using namespace std;    

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};


void sortArr(Node* root, vector<int> &a)
{
    if(root == NULL)
        return;
    sortArr(root->left, a);
    a.push_back(root->data);
    sortArr(root->right, a);
}

signed main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    vector<int> a;
    sortArr(root, a);
    for(auto i:a)
        cout<<i<<" ";
    cout<<"\n";
}