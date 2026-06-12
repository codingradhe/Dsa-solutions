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
// leetcode problme link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int>st;
        ListNode* temp = head;
        while(temp){
            st.insert(temp->val);
            temp= temp->next;
        }
        vector<int>v;
        for(auto it:st){
            v.push_back(it);
        }
        if(v.empty()) return nullptr;
        ListNode* newHead = new ListNode(v[0]);
        ListNode* mover = newHead;
        for(int i=1;i<v.size();i++){
            ListNode* temp = new ListNode(v[i]);
            mover->next = temp;
            mover = temp ;
        }
        return newHead;
    }
};
