// ♥️♥️♥️ doing any operation in any node first store that node if there is use of that node in your program

// leetcode link of this problem --> https://leetcode.com/problems/reorder-list/?envType=problem-list-v2&envId=linked-list
class Solution {
public:
    int lenOfll(ListNode* head){
        if(!head) return 0;
        ListNode* temp = head;
        int cnt =0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* reverseLL(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* temp = head;
        while(temp){
            ListNode* front = temp->next; 
            temp->next = pre;
            pre = temp;
            temp = front;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr) return ;
        ListNode* temp = head;
        int len = lenOfll(temp);
        temp = head;
        ListNode* pre = nullptr;
        for(int i=0;i<((len+1)/2);i++){
            pre = temp;
            temp = temp->next;
        }
        pre->next = nullptr;
        ListNode* temp1 = head;
        ListNode* temp2 = reverseLL(temp);
        ListNode* newhead = new ListNode(-1);
        ListNode* mover = newhead;
        while(temp1&&temp2){
            ListNode* front1 = temp1->next;
            ListNode* front2 = temp2->next;
            temp1->next = temp2;
            temp2->next = front1;
            mover->next = temp1;
            mover = temp2;
            temp1 = front1;
            temp2 = front2;
        }
        if(temp1) {
            mover->next = temp1;
        }
        return ;
    }
};

