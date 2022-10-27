class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
      ListNode* temp=new ListNode();
      ListNode *ans,*itr;
      ans=temp;
      itr=ans;
      int carry=0;
      while(l1 || l2 || carry>0)
      {
        int sum=0;
        if(l1)
        {
          sum+=l1->val;
          l1=l1->next;
        }
        if(l2)
        {
          sum+=l2->val;
          l2=l2->next;
        }
        sum+=carry;
        ListNode* x=new ListNode(sum%10);
        itr->next=x;
        itr=itr->next;
        carry=sum/10;
      }
      return ans->next;
    }
};