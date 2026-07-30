// leetcode problem link of this problem -->https://leetcode.com/problems/add-two-numbers-ii/?envType=problem-list-v2&envId=linked-list
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head||!head->next) return head;
        ListNode* temp = head;
        ListNode* pre = nullptr;
        while(temp){
            ListNode* next = temp->next;
            temp->next = pre;
            pre = temp;
            temp = next;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* la, ListNode* lb) {
        ListNode* tempa = la;
        ListNode* tempb= lb;
        tempa = reverse(tempa);
        tempb = reverse(tempb);
        ListNode* mover = nullptr;
        int carry = 0;
        while(tempa&&tempb){
            ListNode* nexta = tempa->next;
            ListNode* nextb = tempb->next;
            int sum = tempa->val+tempb->val+carry;
            int digit = sum%10;
            carry = sum/10;
            tempa->val = digit;
            tempa->next = mover;
            mover = tempa;
            tempa = nexta,tempb = nextb;
        }
        while(tempa){
            ListNode* next = tempa->next;
            int sum = tempa->val +carry;
            tempa->val = sum%10;
            carry = sum/10;
            tempa->next = mover;
            mover = tempa;
            tempa = next;
        }
        while(tempb){
            ListNode* next = tempb->next;
            int sum = tempb->val +carry;
            tempb->val = sum%10;
            carry = sum/10;
            tempb->next = mover;
            mover = tempb;
            tempb = next;
        }
        if(carry){
            ListNode* head = new ListNode(carry);
            head->next = mover;
            mover = head;
        }
        return mover;
    }
};

