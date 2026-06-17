/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
*/ 
// gfg link of this problem-->> https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=chatgpt.com
//code written by me
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* temp = head;
        Node* pre = nullptr;
        if(temp ==nullptr) return nullptr;
        if(temp->next == nullptr) return head;
        while(temp->next){
            Node* front = temp->next;
            temp->next = pre;
            temp->prev = front;
            pre = temp;
            temp = front;
        }
        temp->next = pre;
        temp->prev = nullptr;
        return temp;
    }
};
// some cleaner code for this problem
class Solution {
  public:
    Node *reverse(Node *head) {
        Node* temp = head;
        Node* newhead = nullptr;
        if(head ==nullptr||head->next==nullptr) return head;
        while(temp){
            swap(temp->next,temp->prev);
            newhead = temp;
            temp = temp->prev;
        }
        return newhead;
    }
};

