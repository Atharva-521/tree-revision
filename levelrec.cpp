#include<iostream>
#include "tree.h"

using namespace std;

int height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    if(lheight > rheight)
    {
        return lheight + 1;
    }

    return rheight + 1;
}

void printcurrlvl(node* root, int level)
{
    if(root == NULL)
    {
        return;
    }

    if(level == 1)
    {
        cout<<root->data<<" ";
    }

    printcurrlvl(root->left,level - 1);
    printcurrlvl(root->right,level - 1);

}

void levelrec(node* root)
{
    int h = height(root);

    for(int level = 1; level <= h ; level++)
    {
        printcurrlvl(root,level);

        cout<<"\n";
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

    levelrec(root);
}