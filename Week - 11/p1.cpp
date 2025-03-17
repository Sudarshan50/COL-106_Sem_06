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


int height(Tree* root)
{
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Tree* root)
{
    if(root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}

void solve()
{
    Tree* root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(20);
    root->left->left = new Tree(3);
    root->left->right = new Tree(7);
    root->right->left = new Tree(15);
    root->right->right = new Tree(25);

    //check iff this bst is a AVL tree or not..
    if(isBalanced(root))
        cout<<"Yes, it is a AVL tree"<<endl;
    else
        cout<<"No, it is not a AVL tree"<<endl;
}




signed main()
{
    solve();
}