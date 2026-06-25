// gfg link of this problem-->https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=chatgpt.com
//🖊️🖊️🖊️  learning -->always consider edge cases for better solution  first approach edge cases then solve for normal behaviour
class Solution {
  public:
    Node* segregate(Node* head) {
        if(head == NULL) return head;
        int cnt0=0,cnt1=0,cnt2=0;
        Node* temp1 = head;
        while(temp1){
            if(temp1->data ==0) cnt0++;
            else if(temp1->data==1) cnt1++;
            else cnt2++;
            temp1 = temp1->next;
        }
        if(cnt0>0) {
            head->data = 0;
            cnt0--;
        }
        else if(cnt1>0) {
            head->data = 1;
            cnt1--;
        }
        else return head;
        Node* temp = head->next;
        while(cnt0){
            temp->data =0;
            cnt0--;
            temp = temp->next;
        }
        while(cnt1){
            temp->data =1;
            cnt1--;
            temp = temp->next;
        }
        while(cnt2){
            temp->data =2;
            cnt2--;
            temp = temp->next;
        }
        return head;
    }
};
