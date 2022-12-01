#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        left = right = NULL;
        data = data;
    }    
};

node* buildTree(node* root)
{
    cout<<"Enter data for node\n";
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1) return NULL;

    cout<<"Enter data for left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    node* root = NULL;
    root = buildTree(root);
}