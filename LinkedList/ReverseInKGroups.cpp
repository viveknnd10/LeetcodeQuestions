class Solution {
public:
    ListNode* reverseGroup(ListNode* start,ListNode* end)
    {
        ListNode *previous,*current,*forward;
        previous=NULL;
        current=start;
        forward=start->next;
        while(current!=end)
        {
            current->next=previous;
            previous=current;
            current=forward;
            if(forward)
                forward=forward->next;
        }
        return previous;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k==1)
        {
            return head;
        }
        ListNode *start=head,*end=head,*str;
        bool flag=false;
        while(end)
        {
            for(int i=0;i<k;i++)
            {
                if(end==NULL && i<k)
                {
                    flag=true;
                    break;
                }
                if(end)
                {
                    end=end->next;
                }
            }
            if(flag==true)
            {
                start->next=str;
                break;
            }
            if(start==head)
            {
                head=reverseGroup(start,end);
                str=end;
            }
            else
            {
                start->next=reverseGroup(str,end);
                start=str;
                str=end;
            }
        }
        return head;
        
    }
};