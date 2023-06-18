#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <queue>
#include "tree.h"

using namespace std;
   


vector<int> vertical(node* root)
{
    vector<int> ans;
    map<int,vector<int> > mapped;
    pair<node* , int> p;
    queue<pair<node* , int> > q;
    if(root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node*,int> temp = q.front();
        node* front = temp.first;
        int hd = temp.second;
        q.pop();
        mapped[hd].push_back(front->data);

        if(front->left)
        {
            q.push(make_pair(front->left,hd-1));
        }

        if(front->right)
        {
            q.push(make_pair(front->right,hd+1));
        }
    }

    for(auto i : mapped)
    {
        for(auto j : i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}


int main()
{
    vector<int> ans;
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    ans = vertical(root);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
    
    
    return 0;
}