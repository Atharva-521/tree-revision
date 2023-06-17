#include <iostream>
#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

pair<int,int> diameter(node* root)
{
    //base case 
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameter(root->left);
    pair<int,int> right = diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second) + 1;

    return ans;
}

int main()
{
    pair<int,int> ans;
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->right = new node(3);
    root->right->right = new node(6);
    root->right->right->right = new node(9);
    root->right->right->right->right = new node(11);
    root->right->right->right->left = new node(10);
    root->right->right->right->left->left = new node(12);
    root->right->right->right->left->right = new node(13);

    ans = diameter(root);;
    cout<<"Diameter : "<<ans.first<<endl;
    cout<<"Height : "<<ans.second<<endl;

    return 0;
}