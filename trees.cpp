#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int s)
    {
        left = right = NULL;
        data = s;
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

void inOrderTraversal(node* root)
{
    if(root)
    {
        inOrderTraversal(root->left);
        cout<<root->data<<" - ";
        inOrderTraversal(root->right);
    }  
}

void preOrderTraversal(node* root)
{
    if(root)
    {
        cout<<root->data<<" - ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(node* root)
{
    if(root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" - ";
    }
}

void postOrderTraversal2(node* root)
{
    if(root)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" - ";
    }
}

int main()
{
    node* root = NULL;
    root = buildTree(root);
    
    //25 15 3 -1 -1 2 -1 -1 10 4 -1 -1 9 -1 -1

    cout<<"Preorder is -> "<<endl;
    preOrderTraversal(root);
    cout<<endl;
    cout<<"Inorder is -> "<<endl;
    inOrderTraversal(root);
    cout<<endl;
    cout<<"Postorder is -> "<<endl;
    postOrderTraversal(root);
    cout<<endl;

}