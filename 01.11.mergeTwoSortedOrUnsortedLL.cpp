/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 🥰🥰🥰 leetcode problem link -->> https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newhead;
        if(list2==nullptr && list1 ==nullptr) return nullptr;
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
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
};
