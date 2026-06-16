/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//most brute force solution 
// leetcode problem link -->>https://leetcode.com/problems/intersection-of-two-linked-lists/?envType=problem-list-v2&envId=linked-list
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa = headA;
        while(tempa){
            ListNode* tempb = headB;
            while(tempb){
                if(tempa==tempb) return tempa;
                tempb=tempb->next;
            }
            tempa= tempa->next;
        }
        return NULL;
    }
};
// ♥️♥️♥️most optimal solution-->>♥️♥️
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
            a = (a == NULL) ? headB : a->next;
            b = (b == NULL) ? headA : b->next;
        }

        return a;
    }
};
