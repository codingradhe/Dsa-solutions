//2130. Maximum Twin Sum of a Linked List
//In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.The twin sum is defined as the sum of a node and its twin.Given the head of a linked list with even length, return the maximum twin sum of the linked list.
//leetcode problem link of this problem --> https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/?envType=problem-list-v2&envId=linked-list
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
    int pairSum(ListNode* head) {
        if(head==nullptr) return 0;
        ListNode* temp = head;
        int len = lenOfll(temp);
        temp = head;
        ListNode* pre = nullptr;
        for(int i=0;i<((len)/2);i++){
            pre = temp;
            temp = temp->next;
        }
        pre->next = nullptr;
        ListNode* temp1 = head;
        ListNode* temp2 = reverseLL(temp);
        int ans = INT_MIN;
        while(temp1){
            ans = max(ans, temp1->val+temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return ans;
    }
};
