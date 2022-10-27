/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int indexSmallest(vector<ListNode*>& lists)
    {
      int smallest=INT_MAX,itr=0;
      for(int i=0;i<lists.size();i++)
      {
        if((lists[i])->val<=smallest)
        {
          smallest=(lists[i])->val;
          itr=i;
        }
      }
      return itr;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
      if(lists.size()==0)
      {
        return NULL;
      }
      if(lists.size()==1)
      {
        return lists[0];
      }
      for(int i=0;i<lists.size();i++)
      {
        if(lists[i]==NULL)
        {
          lists.erase(lists.begin()+i);
          i--;
        }
      }
      ListNode *root=new ListNode(0);
      ListNode *current=root;
      while(lists.empty()!=true)
      {
        int index=indexSmallest(lists);
        ListNode *temp=new ListNode(lists[index]->val);
        current->next=temp;
        current=current->next;
        lists[index]=lists[index]->next;
        if(lists[index]==NULL)
        {
          lists.erase(lists.begin()+index);
        }
      }
      return root->next;
    }
};