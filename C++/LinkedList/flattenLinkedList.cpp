Node* merge(Node *current,Node *forward)
{
    Node *temp,*mergedList;
    mergedList=new Node(0);
    temp=mergedList;
    while(current && forward)
    {
        if(current->data>forward->data)
        {
            temp->bottom=forward;
            forward=forward->bottom;
        }else{
            temp->bottom=current;
            current=current->bottom;
        }
        temp=temp->bottom;
    }
    if(current)
    {
        temp->bottom=current;
    }else{
        temp->bottom=forward;
    }
    return mergedList->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   Node *curr,*forward,*temp;
   curr=root;
   forward=root->next;
   while(curr && forward)
   {
       curr=merge(curr,forward);
       forward=forward->next;
   }
   return curr;
}
