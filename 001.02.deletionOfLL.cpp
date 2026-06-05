// *** 🖊️🖊️🖊️ 1. you can use free or delete in cpp and garbage-collector in java;***
// *** 🖊️🖊🖊️ 2.
#include <bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node* next;
  public:
  node(int data1){
    data = data1;
    next = nullptr;
  }
};
node* convertArrToLL(vector<int>&v){
  if(v.empty()) return nullptr;
  node* head = new node(v[0]);
  node* mover = head;
  for(int i=1;i<v.size();i++){
    node* temp = new node(v[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}
//***😘😘😘 delete Head of LL.***
node* deleteHead(node* head){
  if(head == NULL) return head;
  node* temp = head;
  head = head->next;
  delete temp;
  return head;
}
//***😘😘😘 delete tail of LL ***.
node* deleteTailOfLL(node* head){
  node* temp = head;
  if(temp ==nullptr||temp->next ==nullptr){
    return nullptr;
  }
  while(temp->next->next!=nullptr){
    temp = temp->next;
  }
  delete temp->next;
  temp->next = nullptr;
  return head;
}
///***💘💘💘delete kth elements of LL ***
node* deleteKthElements(node* head,int k){
  if(head == nullptr) return head;
  if(k==1){
    node* temp = head;
    head = head->next;
    delete temp;
  }
  int cnt =0;
  node* temp = head;
  node* pre = nullptr;
  while(temp != nullptr){
    cnt++;
    if(cnt == k){
      pre->next = pre->next->next;
      delete temp;
      break;
    }
    pre = temp;
    temp = temp->next;
  };
  return head;
}
int main() {
  int n;cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  node* head = convertArrToLL(v);
  head = deleteHead(head);
  deleteTailOfLL(head);
  deleteKthElements(head,3);
  node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  return 0;
}


