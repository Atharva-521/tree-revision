#include<iostream>
#include<queue>
#include "tree.h"

using namespace std;

int lvlnull(node* root)
{
    int height = 0;
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* front = q.front();
        q.pop();
        if(front == NULL)
        {
            height++;
           if(!q.empty())
           {
                q.push(NULL);
           }
        }
       if(front != NULL)
       {
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
    return height;
}

int lvlh(node* root)
{
    int height = 0;
    queue<node*> q;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0 ; i < size ; i++)
        {
            node* front = q.front();
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
        height++;
    }
    return height;  
}

int main()
{
    int height1,height2;
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right= new node(7);
    height1 = lvlnull(root);
    height2 = lvlh(root);

    cout<<"height is "<<height1;
    cout<<"height is "<<height2;

}