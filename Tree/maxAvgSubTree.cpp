//My Solution
class Solution {
public:
    pair<double,double> maxAvgValue=make_pair(INT_MIN,0);
    pair<double,double> maxAvgSubtree(TreeNode* root)
    {
      if(!root)
        return make_pair(0.0,0.0);
      else if(!root->left && !root->right)
        return make_pair(root->val,1.0);
      else
      {
        pair<double,double> left,right,curMaxVal;
        left=maxAvgSubtree(root->left);
        right=maxAvgSubtree(root->right);
        
        double sumLeft=left.first*left.second,sumRight=right.first*right.second,totalAvg;
        totalAvg=(root->val+sumLeft+sumRight)/(1+left.second+right.second);
        curMaxVal=make_pair(max((left.first),(right.first)),(left.first)>(right.first)?left.second:right.second);
        maxAvgValue=curMaxVal.first>maxAvgValue.first?curMaxVal:maxAvgValue;
        maxAvgValue=make_pair(max(maxAvgValue.first,totalAvg),maxAvgValue.first>totalAvg?maxAvgValue.second:1+left.second+right.second);
        return make_pair(totalAvg,(1+left.second+right.second));
      }
    }
    double maximumAverageSubtree(TreeNode* root) 
    {
      maxAvgSubtree(root);
      auto [maxAvgVal,count]=maxAvgValue;
      return maxAvgVal;
        
    }
};


//Better Solution
class Solution {
public:
    double maxAvg = 0;
    pair<int, double> search(TreeNode* node){
        if (node == nullptr) return {0, 0}; //{nodes, sum}

        pair<int, double> leftPair = search(node->left);
        pair<int, double> rightPair = search(node -> right);

        int count = leftPair.first + rightPair.first + 1;
        double sum = leftPair.second + rightPair.second + node -> val;

        maxAvg = max(maxAvg, sum / count);

        return {count, sum};

    }

    double maximumAverageSubtree(TreeNode* root) {
        search(root);
        
        return maxAvg;
    }
};