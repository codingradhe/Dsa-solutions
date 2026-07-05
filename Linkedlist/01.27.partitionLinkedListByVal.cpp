// concept of  dummy node
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        if(temp==nullptr||temp->next == nullptr) return head;
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* newhead = nullptr;
        ListNode* mover1 = dummy1;
        ListNode* mover2 = dummy2;
        while(temp){
            if(temp->val <x){
                mover1->next = temp;
                mover1 = temp;
            }
            else {
                mover2->next = temp;
                mover2 = temp;
            }
            temp = temp->next;
        }
        if(mover1!=dummy1&&mover2!=dummy2){
            newhead = dummy1->next;
            mover1->next = dummy2->next;
            mover2->next = nullptr;
            delete dummy1;
            delete dummy2;
            return newhead;
        }
        if(mover1!=dummy1){
            newhead = dummy1->next;
            mover1->next = nullptr;
            delete dummy1;
            delete dummy2;
            return newhead;
        }
        if(mover2!=dummy2){
            newhead = dummy2->next;
            mover2->next = nullptr;
            delete dummy2;
            delete dummy1;
            return newhead;
        }
        return newhead;
    }
};


