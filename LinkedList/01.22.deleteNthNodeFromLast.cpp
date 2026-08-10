// ♥️♥️♥️ key concept --> go by two pointer approach slow and fast first move fast pointer till n node and move simeltanouly 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(fast ==nullptr){
            head = head->next;
            delete slow;
            return head;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* deletenode = slow->next;
        slow->next = slow->next->next;
        delete deletenode;
        return head;
    }
};
