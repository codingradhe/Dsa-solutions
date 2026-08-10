class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next == nullptr) return  slow;
        else return slow->next;
    }
};
