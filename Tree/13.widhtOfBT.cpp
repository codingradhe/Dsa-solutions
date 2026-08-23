// leetcode link of this problem -->> https://leetcode.com/problems/maximum-width-of-binary-tree/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;
            long long first = 0,last = 0;
            for(int i = 0;i < size; i++){
                TreeNode* node = q.front().first;
                long long CI = q.front().second - mini;
                q.pop();
                if(i==0) first = CI;
                if(i == size-1) last = CI;
                if(node->left){
                    q.push({node->left,CI*2+1});
                }
                if(node->right){
                    q.push({node->right,CI*2+2});
                }
            }
            ans = max(ans,int(last-first+1));
        }
        return ans;
    }
};
