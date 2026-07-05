// solve by hash mapping
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        map<Node*,int>mp;
        Node* temp = head;
        int cnt =1;
        while(temp){
            if(mp.find(temp)!=mp.end()){
                return cnt - mp[temp];
            }
            mp[temp] = cnt;
            cnt++;
            temp=temp->next;
        }
        return 0;
    }
};
//optimal approach O(1) space complexity
class Solution {
  public:
    int lenOfLoop(Node* slow,Node*fast){
        int cnt = 1;
        while(slow!=fast){
            cnt++;
            fast = fast->next;
        }
        return cnt;
    }
    int lengthOfLoop(Node *head) {
        if(head == nullptr || head->next == nullptr) return 0;
        Node* slow = head;
        Node* fast = head;
        while(fast &&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast) return lenOfLoop(slow,fast->next);
        }
        return 0;
    }
};
