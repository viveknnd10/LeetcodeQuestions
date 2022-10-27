lass Solution {
public:
    Node* copyRandomList(Node* head) 
    {
      if(!head)
        return head;
      Node *current=head;
      Node *new_head=new Node(0);
      Node *new_curr=new_head;
      while(current)
      {
        Node *temp=new Node(current->val);
        current=current->next;
        new_curr->next=temp;
        new_curr=new_curr->next;
      }
      new_curr=new_head->next;
      unordered_map<int,Node*> address;
      while(new_curr)
      {
        address.insert({new_curr->val,new_curr});
        new_curr=new_curr->next;
      }
      current=head;
      new_curr=new_head->next;
      while(current)
      {
        if(current->random)
          new_curr->random=address[current->random->val];
        current=current->next;
        new_curr=new_curr->next;
      }
      return new_head->next;
    }
};