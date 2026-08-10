
//leetcode link of this problem-->https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/?envType=problem-list-v2&envId=linked-list
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int count =0;
        ListNode* temp1 = head;
        while(temp1){
            count++;
            temp1 = temp1->next;
        }
        int ans = 0;
        count--;
        ListNode* temp = head;
        while(temp){
            ans += temp->val*(pow(2,count));
            count--;
            temp = temp->next;
        }
        return ans;
    }
};
