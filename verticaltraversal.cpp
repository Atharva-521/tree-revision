#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <queue>
#include "tree.h"

using namespace std;
   
map<int,vector<int> > mapping(node*root,int &hd)
{
    map<int,vector<int> > mapped;
    
    //base case 
    if(root == NULL)
    {
        return mapped;
    }

    mapped[hd].push_back(root->data);
    mapping(root->left,hd-1);
    mapping(root->right,hd+1);

    return mapped;


}

vector<int> vertical(node* root)
{
    mapping(root,0);
}


int main()
{
    
    
    
    return 0;
}