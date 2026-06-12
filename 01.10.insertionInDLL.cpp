// *** 🖊️🖊️🖊️ 1. you can use free or delete in cpp and garbage-collector in java;***..
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* back;
    public:
    node(int data1,node* next1,node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
node* convertArrToDLL(vector<int>&v){
  if(v.empty()) return nullptr;
  node* head = new node(v[0]);
  node* mover = head;
  for(int i=1;i<v.size();i++){
    node* temp = new node(v[i]);
    mover->next = temp;
    temp->back = mover;
    mover = temp;
  }
  return head;
}
//***😘😘😘 add a node as Head of LL.***
node* insertHeadInDLL(node* head,int val){
  node* temp = new node(val,head,nullptr);
  if(head != nullptr){
    head->back = temp;
  }
  return temp;
}
//***😘😘😘 add val as tail of DLL ***.
node* insertValAsTailOfDLL(node* head,int val){
  node* addTail = new node(val,nullptr,nullptr);
  if(head == nullptr) return addTail;
  node* temp = head;
  while(temp->next != nullptr){
    temp = temp->next;
  }
  temp->next = addTail;
  addTail->back = temp;
  return head;
}
///***💘💘💘 insert node at kth position of DLL ***
node* insertNodeAtKthPosInDLL(node* head, int k, int val){
  if(k == 1) return insertHeadInDLL(head,val);
  node* temp = head;
  int cnt = 0;
  while(temp){
    cnt++;
    if(cnt == k) break;
    temp = temp->next;
  }
  if(temp == nullptr) return head;
  node* addnode = new node(val);
  node* pre = temp->back;
  pre->next = addnode;
  addnode->next = temp;
  temp->back = addnode;
  addnode->back = pre;
  return head;
}
///***💘💘💘 insert node before a value of DLL ***
node* insertNodeBeforeValInDLL(node* head, int val, int pushVal){
  if(head == nullptr) return head;
  if(head->data==val) return insertHeadInDLL(head,pushVal);
  node* temp = head;
  while(temp!=nullptr){
    if(temp->data==val) break;
    temp= temp->next;
  }
  if(temp == nullptr) return head;
  node* addnode = new node(pushVal);
  node* pre = temp->back;
  pre->next = addnode;
  addnode->next = temp;
  temp->back = addnode;
  addnode->back = pre;
  return head;
}
int main() {
  int n;cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  node* head = convertArrToDLL(v);
  int val1;cin>>val1;
  head = insertHeadInDLL(head,val1);
  int val2;cin>>val2;
  head =insertValAsTailOfDLL(head,val2);
  int  k,val3;cin>>k>>val3;
  head =insertNodeAtKthPosInDLL(head,k,val3);
  int val4,pushVal;cin>>val4>>pushVal;
  head=insertNodeBeforeValInDLL(head,val4,pushVal);
  node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  return 0;
}
