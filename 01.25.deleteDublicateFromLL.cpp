class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* temp = head;
        map<int,int> mp;
        while (temp) {
            mp[temp->val]++;
            temp = temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* mover = dummy;
        for (auto it : mp) {
            if(it.second==1){
                ListNode* tem = new ListNode(it.first);
                mover->next = tem;
                mover = tem;
            }
        }
        ListNode* newhead = dummy->next;
        delete dummy;
        return newhead;
    }
};
