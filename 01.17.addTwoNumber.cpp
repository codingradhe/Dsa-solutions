class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>v1;
        vector<int>v2;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1){
            v1.push_back(t1->val);
            t1= t1->next;
        }
        while(t2){
            v2.push_back(t2->val);
            t2= t2->next;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        int sum1 = 0,sum2 = 0,sum3 = 0;
        for(int i=0;i<v1.size(),i++){
            sum1 = sum1*10 + v1[i];
        }
        for(int i=0;i<v2.size(),i++){
            sum2 = sum2*10 + v2[i];
        }
        sum3 = sum1+sum2;
        ListNode* newhead = new ListNode(sum3%10);
        sum3/=10;
        ListNode* mover = 
    }
};
