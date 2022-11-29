package Java.Tree;

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        while(q.peek()!=null)
        {
            List<Integer> temp=new ArrayList<>();
            int length=q.size();
            for(int i=0;i<length;i++)
            {
                if(q.peek().left!=null)
                    q.add(q.peek().left);
                if(q.peek().right!=null)
                    q.add(q.peek().right);
                temp.add(q.poll().val);
            }
            ans.add(temp);
        }
        return ans;
    }
}
