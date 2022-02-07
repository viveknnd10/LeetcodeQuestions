TreeNode* createTree(pair<int,string> first,ListNode *red,ListNode* blue,ListNode* green)
{
	auto [head,color]=first;
  if((color==red && !green && !blue)||(color==blue && !green && !red)||(color==green && !red && !blue))
  {
  	return NULL;
  }
	TreeNode* root=new TreeNode(head);
  TreeNode* current=root;
  if(color==red)
  {
    current->left=createTree({blue->val,blue},red->next,blue->next,green->next);
    current->right=createTree({green->val,green},red->next,blue->next,green->next);
  }
  else if(color==green)
  {
  	current->left=createTree({blue->val,blue},red->next,blue->next,green->next);
    current->right=createTree({red->val,red},red->next,blue->next,green->next);
  }
  else
  {
  	current->left=createTree({green->val,green},red->next,blue->next,green->next);
    current->right=createTree({red->val,red},red->next,blue->next,green->next);
  }
}