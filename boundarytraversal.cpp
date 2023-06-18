#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include "tree.h"

using namespace std;

void traverseleft(node* root,vector<int> &ans)
{
    //base cases 
    if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        return ;
    }

    ans.push_back(root->data);
    
    if(root->left)
        traverseleft(root->left,ans);
    else
        traverseleft(root->right,ans);
}

void traverseleaf(node* root,vector<int> &ans)
{
    //base case
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
}

void traverseright(node* root,vector<int> &ans)
{
    //base case
    if(root == NULL ||(root->left == NULL && root->right == NULL))
    {
        return ;
    }

    if(root->right)
        traverseright(root->right,ans);
    else
        traverseright(root->left,ans);

    ans.push_back(root->data);
}

vector<int> boundary(node* root)
{
    vector<int> ans;
    //base case
    if(root == NULL)
    {
        return ans;
    }

    //traverseleft
    traverseleft(root,ans);

    //traverse leaf
    traverseleaf(root,ans);

    //traverse right

    traverseright(root->right,ans);

    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->right = new node(3);
    root->right->right = new node(6);
    root->right->right->right = new node(9);
    root->right->right->right->left = new node(10);
    root->right->right->right->right = new node(11);

    vector<int> ans;

    ans = boundary(root);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }

    return 0;
}