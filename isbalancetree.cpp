#include <iostream>
#include<bits/stdc++.h>
#include <utility>
#include "tree.h"

using namespace std;

pair<bool,int> balance(node* root)
{
    //base case
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> left = balance(root->left);
    pair<bool,int> right = balance(root->right);

    bool leftans = left.first;
    bool rightans = right.first;

    bool heightdiff = abs(left.second - right.second) <= 1;

    int height = max(left.second,right.second) + 1;

    if(leftans && rightans && heightdiff)
    {
        pair<bool,int> ans = make_pair(true,height);
        return ans;
    }

    else
    {
        pair<bool,int> ans = make_pair(false,height);
        return ans;
    }

    }

int main()
{
    pair<bool,int> ans;
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right= new node(7);

    ans = balance(root);

    if(ans.first)
    {
        cout<<"Tree is balanced"<<endl;
        cout<<"Height of tree : "<<ans.second<<endl;
    }
    else
    {
        cout<<"Tree is not balanced"<<endl;
        cout<<"Height of tree : "<<ans.second<<endl;
    }

}