//♥️♥️♥️ use of two pointer approach like array left and right 
// gfg problem link of this problem -->>https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1?utm_source=chatgpt.com
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int,int>>v;
        Node* left = head;
        while(left->next){
            left = left->next;
        }
        Node* right = left;
        left = head;
        while(left!=right || left->prev!=right){
            int sum = left->data + right->data;
            if(sum == target){
                v.push_back({left->data ,right->data});
                right = right->prev;
                left = left->next;
            }
            else if(sum>target){
                right = right->prev;
            }
            else {
                left = left->next;
            }
        }
        return v;
    }
};
