// 331. Verify Preorder Serialization of a Binary Tree
// Medium
// One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.


// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

// Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

// It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

// You may assume that the input format is always valid.

// For example, it could never contain two consecutive commas, such as "1,,3".
// Note: You are not allowed to reconstruct the tree.
//  leetcode link -->> https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/?envType=problem-list-v2&envId=tree
class Solution {
public:
    bool isValidSerialization(string s) {
        int slots = 1;
        int i = 0;

        while (i < s.size()) {

            // No place available for this node
            if (slots == 0)
                return false;

            // Process one token
            if (s[i] == '#') {
                slots--;
                i++;
            }
            else {
                // Process complete number
                while (i < s.size() && s[i] != ',') {
                    i++;
                }

                slots--;   // use one slot
                slots += 2; // create left and right slots
            }

            // Skip comma
            if (i < s.size() && s[i] == ',')
                i++;
        }

        return slots == 0;
    }
};

