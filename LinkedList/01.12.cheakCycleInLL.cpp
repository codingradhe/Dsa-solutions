/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// problem link of this problem --> https://leetcode.com/problems/linked-list-cycle/?envType=problem-list-v2&envId=linked-list
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        set<ListNode*> st;
        while(temp != nullptr) {
            if(st.find(temp) != st.end()) {
                return true;
            }
            st.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};
//*** ♥️♥️♥️♥️ most optimal solution for this problem♥️♥️♥️
// *** most importand algorithm used in this problme -->Better Solution (Floyd's Cycle Detection)
// *** Uses O(1) extra space:

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};
