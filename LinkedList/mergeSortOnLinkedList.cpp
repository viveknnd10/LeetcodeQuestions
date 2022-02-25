class Solution {
public:
  ListNode* getMid(ListNode* head)
  {
    ListNode *mid,*slow,*fast;
    slow=NULL;
    fast=head;
    while(fast && fast->next)
    {
      slow=(slow==NULL)?head:slow->next;
      fast=fast->next->next;
    }
    mid=slow->next;
    slow->next=NULL;
    return mid;
  }
  ListNode* merge(ListNode *list1,ListNode *list2)
  {
    ListNode dummyNode(0);
    ListNode *current=&dummyNode;
    while(list1 && list2)
    {
        if(list1->val>list2->val)
        {
          current->next=list2;
          list2=list2->next;
        }
        else
        {
          current->next=list1;
          list1=list1->next;
        }
        current=current->next;
    }
    if(list1)
      current->next=list1;
    if(list2)
      current->next=list2;
    return dummyNode.next;
  }
    ListNode* sortList(ListNode* head) 
    {
      if(!head || !head->next)
      {
        return head;
      }
      ListNode *mid=getMid(head);
      ListNode *left=sortList(head);
      ListNode *right=sortList(mid);
      return merge(left,right); 
    }
};