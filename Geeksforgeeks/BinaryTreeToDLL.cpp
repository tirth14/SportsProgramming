/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Structure for tree and linked list
struct Node
{
    int data;
    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; */
// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list

Node* BDLL(Node* root)
{
    if(root==NULL) return root;
    
    Node* l=BDLL(root->left);
    
    Node* r=BDLL(root->right);
    
    if(l)
    {
        Node* lend=l;
        while(lend->right!=NULL) lend=lend->right;
        lend->right=root;
        root->left=lend;
    }
    if(r)
    {
        Node* rstart=r;
        while(rstart->left!=NULL) rstart=rstart->left;
        rstart->left=root;
        root->right=rstart;
    }
    
    return l!=NULL?l:root;
}

void BToDLL(Node *root, Node **head_ref)
{
    *head_ref=BDLL(root);
}
