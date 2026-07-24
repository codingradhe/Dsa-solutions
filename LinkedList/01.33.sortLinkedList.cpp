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
// ❤️❤️❤️❤️ modifind hare and tortoise algorithm 
// slow = head;; BUT 
// fast = head->next; to find exact middle in any case ;
class Solution {
public:
    ListNode* findMid(ListNode* head){
        if(!head||!head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* heada,ListNode*headb){
        if(heada==nullptr && headb ==nullptr) return nullptr;
        if(heada==nullptr) return headb;
        if(headb==nullptr) return heada;
        ListNode* newhead;
        ListNode* temp1 = heada;
        ListNode* temp2 = headb;
        if(temp1->val>=temp2->val){
            newhead = temp2;
            temp2 = temp2->next;
        }
        else{
            newhead = temp1;
            temp1= temp1->next;
        }
        ListNode* mover = newhead;
        while(temp1!= nullptr&&temp2!=nullptr){
            if(temp1->val>=temp2->val){
                mover->next= temp2;
                temp2 = temp2->next;
                mover= mover->next;
            }
            else if(temp1->val<temp2->val){
                mover->next= temp1;
                temp1 = temp1->next;
                mover= mover->next;
            }
        }
        if(temp1) mover->next = temp1;
        if(temp2) mover->next = temp2;
        return newhead;
    }
    ListNode* sortList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* mid = findMid(head);
        ListNode* head2 = mid->next;
        mid->next = nullptr;
        ListNode* heada = sortList(head);
        ListNode* headb = sortList(head2);
        return merge(heada,headb);
    }
};







