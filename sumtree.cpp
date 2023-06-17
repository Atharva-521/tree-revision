#include<iostream>
#include<bits/stdc++.h>
#include<utility>
#include "tree.h"

using namespace std;

pair<bool,int> isSum(node* root)
{
    //base case
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    //leaf node
    if(root->left == NULL && root->right == NULL)
    {
        pair<bool,int> p = make_pair(true,root->data);
        return p; 
    }

    pair<bool,int> left = isSum(root->left);
    pair<bool,int> right = isSum(root->right);

    bool leftans = left.first;
    bool rightans = right.first;
    bool issum = (left.second + right.second) == root->data;
    int sum = left.second + right.second + root->data;

    if(leftans && rightans && issum)
    {
        pair<bool,int> ans = make_pair(true,sum);
        return ans;
    }
    else
    {
        pair<bool,int> ans = make_pair(false,sum);
        return ans;
    }
}

int main()
{
    pair<bool,int> ans;
    node* root = new node(44);
    root->left = new node(9);
    root->right = new node(13);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right= new node(7);

    ans = isSum(root);

    if(ans.first)
    {
        cout<<"It is Sum tree"<<endl;
    }
    else
    {
        cout<<"Not a sum tree"<<endl;
    }
}