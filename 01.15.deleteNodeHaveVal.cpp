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
// brute force solutions by me 
// leetcode link of this problem-->https://leetcode.com/problems/remove-linked-list-elements/?envType=problem-list-v2&envId=linked-list
class Solution {
public:
    ListNode* deleteHead(ListNode* head){
        if(head == nullptr) return nullptr;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* pre = nullptr;
        while(head!=nullptr&&head->val==val){
            head = deleteHead(head);
        }
        temp = head;
        while(temp){
            if(temp->val== val&&temp->next == nullptr){
                pre->next = nullptr;
                delete temp;
                break;
            }
            else if(temp->val == val){
                ListNode* front = temp->next;
                pre->next = front;
                temp->next = nullptr;
                delete temp;
                temp = front;
            }
            else {
                pre = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
// ♥️♥️♥️ optimal solutons  for this problme ♥️♥️♥️


ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* curr = &dummy;

    while(curr->next){
        if(curr->next->val == val){
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }

    return dummy.next;


