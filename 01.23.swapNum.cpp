// leetcode problem link of this problem -->https://leetcode.com/problems/swap-nodes-in-pairs/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {

            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
