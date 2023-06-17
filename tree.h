#include<iostream>
#include<stdlib.h>
#include <queue>

using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};

void inorder(node* root)
{
    //L N R
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root)
{
    //N L R
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    //L R N
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(node* root)
{
    queue<node*> q;

    q.push(root);

    while(!q.empty())
    {
        node* front = q.front();
        cout<<front->data<<" ";
        q.pop();
        if(front->left)
        {
            q.push(front->left);
        }

        if(front->right)
        {
            q.push(front->right);
        }

    }
}

