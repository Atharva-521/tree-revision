#include<iostream>
#include "tree.h"

using namespace std;

void morris(node* root)
{
    if(root == NULL)
    {
        return;
    }

    node* curr = root;

    node* pred;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            pred = curr->left;
            while(pred->right != NULL && pred->right != curr)
            {
                pred = pred->right;
            }

            //if pred->right = NULL
            if(pred->right == NULL)
            {
                pred->right = curr;
                if(curr->left)
                {
                    curr = curr->left;
                }
                else if(curr->right)
                {
                    curr = curr->right;
                }
            }

            if(pred->right == curr)
            {
                pred->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
                
            }
            

        }
       


    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right= new node(7);

    morris(root);
}