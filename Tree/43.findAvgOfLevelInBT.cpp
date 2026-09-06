// 637. Average of Levels in Binary Tree
// Easy
// Given the root of a binary tree, return the average
// value of the nodes on each level in the form of an
// array. Answers within 10-5 of the actual answer 
// will be accepted.
// leetcode link of this problem -->> https://leetcode.com/problems/average-of-levels-in-binary-tree/?envType=problem-list-v2&envId=tree
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            double sum = 0;
            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            static_cast<double>(size);
            ans.push_back(sum/size);
        }
        return ans;
    }
};
