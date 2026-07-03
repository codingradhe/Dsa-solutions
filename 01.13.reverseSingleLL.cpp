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
// 🥰🥰🥰leetcode problem link of this problme -->https://leetcode.com/problems/reverse-linked-list/?utm_source=chatgpt.com
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>v;
        if(head == nullptr) return nullptr;
        ListNode* temp = head;
        ListNode* newhead;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int n= v.size();
        newhead =  new ListNode(v[n-1]);
        ListNode* mover = newhead;
        for(int i=n-2;i>=0;i--){
            mover->next  = new ListNode(v[i]);
            mover= mover->next;
        }
        return newhead;
    }
};
// *** ♥️♥️♥️optimal solution for this problem ♥️♥️♥️
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};
