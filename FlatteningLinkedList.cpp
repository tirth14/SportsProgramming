       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
/*Write a function flatten() to flatten the lists into a single linked list.
The flattened linked list should also be sorted. For example, for the above input list,
output list should be 5->7->8->10->19->20->22->28->30->35->40->45->50.*/

/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node* a,Node* b)
{
    if(a==NULL) return b;
    if(b==NULL) return a;
    
    Node* res;
    if(a->data<b->data) 
    {
        res=a;
        res->bottom=merge(a->bottom,b);
    }
    else
    {
        res=b;
        res->bottom=merge(a,b->bottom);
    }
    return res;
}
    
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL) return root;
   
   return merge(root,flatten(root->next) );
}
