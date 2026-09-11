// 1373. Maximum Sum BST in Binary Tree
// Hard
// Topics
// premium lock icon
// Companies
// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// leetcode link -->> https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
class nodeval {
public:
    int maxnode, minnode;
    int sum;       // sum of current BST
    int maxsum;    // maximum BST sum found

    nodeval(int minnode, int maxnode, int sum, int maxsum) {
        this->minnode = minnode;
        this->maxnode = maxnode;
        this->sum = sum;
        this->maxsum = maxsum;
    }
};
class Solution {
public:
    nodeval largestBstsubtreesum(TreeNode* root) {

        if (!root)
            return nodeval(INT_MAX, INT_MIN, 0, 0);

        auto left = largestBstsubtreesum(root->left);
        auto right = largestBstsubtreesum(root->right);

        if (left.maxnode < root->val &&
            right.minnode > root->val) {

            int currentsum =
                left.sum + right.sum + root->val;

            return nodeval(
                min(root->val, left.minnode),
                max(root->val, right.maxnode),
                currentsum,
                max({left.maxsum, right.maxsum, currentsum})
            );
        }

        return nodeval(
            INT_MIN,
            INT_MAX,
            0,
            max(left.maxsum, right.maxsum)
        );
    }

    int maxSumBST(TreeNode* root) {
        return largestBstsubtreesum(root).maxsum;
    }
};
