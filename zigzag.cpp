#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include "tree.h"

using namespace std;

vector<int> zigzag(node* root)
{
    //base case
    if(root == NULL)
    {
        vector<int> arr = {0};
        return arr;
    }

    vector<int> ans;
    bool LeftToRight = true;
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for(int i = 0 ; i<size ; i++)
        {
            node* front = q.front();
            q.pop();
            int index = LeftToRight ? i : size - i - 1;
            temp.insert(temp.begin() + index, front->data);


            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        LeftToRight = !LeftToRight;
        // for (auto& v : temp)
        // {
        //     ans.insert(ans.end(), v.begin(), v.end());
        // }
         for(auto i : temp)
        {
                
            ans.push_back(i);
        }

    }
    return ans;
}

int main()
{
    vector<int> ans;
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right= new node(7);
    
    ans = zigzag(root);

    for(auto i : ans)
    {
        cout<<i<<" ";
    }
}