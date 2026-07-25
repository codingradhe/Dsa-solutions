//♥️♥️♥️ always write code on your notebook then start writing on your computer 
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head||!head->next->next) return nullptr;
        ListNode* temp = head->next;
        ListNode* mover = head;
        ListNode* pre = nullptr;
        while(temp){
            while(temp->val != 0){
                mover->val += temp->val;
                temp = temp->next;
            }
            mover->next = temp;
            pre = mover;
            mover = temp;
            temp = temp->next;
        }
        pre->next = nullptr;
        return head;
    }
};
