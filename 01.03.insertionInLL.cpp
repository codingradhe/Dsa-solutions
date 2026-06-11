// *** 🖊️🖊️🖊️ 1. you can use free or delete in cpp and garbage-collector in java;***
// *** 🖊️🖊🖊️ 2.
#include <bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node* next;
  public:
  node(int data1, node* next1){
    data = data1;
    next = next1;
  }
};
node* convertArrToLL(vector<int>&v){
  if(v.empty()) return nullptr;
  node* head = new node(v[0],nullptr);
  node* mover = head;
  for(int i=1;i<v.size();i++){
    node* temp = new node(v[i],nullptr);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
//***😘😘😘 add a node as Head of LL.***
node* insertHead(node* head,int val){
  node* temp = new node(val,head);
  return temp;
}
//***😘😘😘 add val as tail of LL ***.
node* insertValAsTailOfLL(node* head,int val){
  node* addTail = new node(val,nullptr);
  if(head == nullptr) return addTail;
  node* temp = head;
  while(temp){
    if(temp->next== nullptr){
      temp->next = addTail;
      break;
    }
    temp = temp->next;
  }
  return head;
}
///***💘💘💘 insert node at kth position of LL ***
node* insertNodeAtKthPosi(node* head, int k, int val){
  if(k == 1) return new node(val, head);
  node* temp = head;
  for(int i = 1; temp != nullptr && i < k - 1; i++){
    temp = temp->next;
  }
  if(temp == nullptr) return head;
  temp->next = new node(val, temp->next);
  return head;
}
///***💘💘💘 insert node before a value of LL ***
node* insertNodeBeforeVal(node* head, int val, int pushVal){
  if(head == nullptr) return head;
  if(head->data==val) return new node(pushVal, head);
  node* temp = head;
  node* pre = nullptr;
  while(temp!=nullptr){
    if(temp->data==val) break;
    pre = temp;
    temp= temp->next;
  }
  if(temp == nullptr) return head;
  pre->next = new node(pushVal,temp);
  return head;
}
int main() {
  int n;cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  node* head = convertArrToLL(v);
  int val1;cin>>val1;
  head = insertHead(head,val1);
  int val2;cin>>val2;
  head =insertValAsTailOfLL(head,val2);
  int  k,val3;cin>>k>>val3;
  head =insertNodeAtKthPosi(head,k,val3);
  int val4,pushVal;cin>>val4>>pushVal;
  head=insertNodeBeforeVal(head,val4,pushVal);
  node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  return 0;
}
