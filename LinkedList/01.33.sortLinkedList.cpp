// O(n2) time complexity
class Solution {
public:
    ListNode* sortL(ListNode* head,ListNode* node){
        if(!head) return node;
        if(head->next ==nullptr)  {
            if(head->val>node->val){
                node->next = head;
                return node;
            }
            else {
                head->next = node;
                node->next = nullptr;
                return head;
            }
        }
        if(head->val>node->val){
            node->next = head;
            return node;
        }
        ListNode* pre = nullptr;
        ListNode* temp = head;
        bool get = false;
        while(temp){
            if(temp->val>node->val){
                pre->next = node;
                node->next = temp;
                get = true;
                return head;
            }
            pre = temp;
            temp = temp->next;
        }
        if(get ==false){
            pre->next = node;
            node->next = nullptr;
        }
        return head;
    }
    ListNode* sortList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* temp = head->next;
        ListNode* newhead = head;
        newhead->next = nullptr;
        while(temp){
            ListNode* front = temp->next;
            newhead = sortL(newhead,temp);
            temp = front;
        }
        return newhead;
    }
};
//  apply merge sort in linked list
