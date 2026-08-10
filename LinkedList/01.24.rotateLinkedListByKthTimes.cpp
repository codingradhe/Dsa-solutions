class Solution {
public:
    int lenOfLL(ListNode* head){
        if(head == nullptr) return 0;
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        if(head==nullptr||head->next == nullptr) return head;
        int n = lenOfLL(head);
        k = k%n;
        k %= n;
        if(k == 0) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<k;i++){
            fast = fast->next;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* pre = slow;
        slow = slow->next;
        pre->next = nullptr;
        fast->next = head;
        ListNode* newhead = slow;
        return newhead;
        
    }
};
