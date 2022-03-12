/* copy list with a random pointer with O(1) space complexity and O(1) time complexity*/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int val;
    Node *next;
    Node *random;
    Node()
    {
        val=0;
        next=NULL;
        random=NULL;
    }
    Node(int x)
    {
        val=x;
        next=NULL;
        random=NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
      if(!head)
        return head;
      Node *current=head;
      Node *new_head=new Node(0);
      Node *new_curr=new_head;
      /*creating new node as well as interleaving to the original list*/
      while(current)
      {
        Node *temp=new Node(current->val);
        temp->next=current->next;
        current->next=temp;
        current=current->next->next;
      }
      current=head;
      new_curr->next=current->next;
      /*redirecting the random pointer of dublicate list as it should be pointer to */
      while(current)
      {
        Node *temp=current->next;
        if(current->random)
          temp->random=current->random->next;
        else
          temp->random=NULL;
        current=current->next->next;
      }
      current=head;
      /*seperating the two lists from one another*/
      while(current)
      {
        Node *temp=current->next;
        current->next=current->next->next;
        if(temp->next)
          temp->next=temp->next->next;
        current=current->next;
      }
      return new_head->next;
    }
};

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next=new Node(8);
    head->next->next->next->next->next->next->next->next=new Node(9);
    head->next->next->next->next->next->next->next->next->next=new Node(10);
    head->next->next->next->next->next->next->next->next->next->next=new Node(11);
    head->next->next->next->next->next->next->next->next->next->next->next=new Node(12);
    head->next->next->next->next->next->next->next->next->next->next->next->next=new Node(13);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next=new Node(14);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next=new Node(15);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next=new Node(16);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next=new Node(17);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next=new Node(18);
    Solution s;
    Node *new_head=s.copyRandomList(head);
    while(new_head)
    {
        cout<<new_head->val<<" ";
        new_head=new_head->next;
    }
    return 0;
}