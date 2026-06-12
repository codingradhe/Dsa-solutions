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
node* convertArrToDLL(vector<int> &v){
    if(v.empty()) return nullptr;
    node* head = new node(v[0]);
    node* mover = head;
    for(int i=1;i<v.size();i++){
        node* temp = new node(v[i]);
        temp->back = mover;
        mover->next = temp;
        mover = temp;
    }
    return head;
}
//***😘😘😘 delete Head of DLL.***
node* deleteHeadInDLL(node* head){
  if(head == NULL) return head;
  node* temp = head;
  head = head->next;
  if(head!=nullptr){
    head->back = nullptr;
  }
  delete temp;
  return head;
}
//***😘😘😘 delete tail of double DLL***.
node* deleteTailOfDLL(node* head){
  node* temp = head;
  if(temp ==nullptr||temp->next ==nullptr){
    delete temp;
    return nullptr;
  }
  while(temp->next!=nullptr){
    temp = temp->next;
  }
  node* pre = temp->back;
  pre->next = nullptr;
  temp->back= nullptr;
  delete temp;
  return head;
}
///***💘💘💘delete kth elements of DLL ***
node* deleteKthElementInDLL(node* head, int k){
    if(head == nullptr) return head;
    if(k == 1){
        return deleteHeadInDLL(head);
    }
    int cnt = 0;
    node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    if(temp == nullptr){
        return head;
    }
    node* pre = temp->back;
    node* front = temp->next;
    pre->next = front;
    if(front != nullptr){
        front->back = pre;
    }
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
///***💘💘💘delete a val of DLL ***
node* deleteByValInDLL(node* head,int val){
  if(head == nullptr) return head;
  if(head->data==val){
    node* temp = head;
    head = head->next;
    if(head!= nullptr){
      head->back= nullptr;
    }
    delete temp;
    return head;
  }
  node* temp = head;
  while(temp != nullptr){
    if(temp->data==val) break;
    temp = temp->next;
  };
  if(temp == nullptr){
    return head;
  }
  node* pre = temp->back;
  node* front = temp->next;
  pre->next = front;
  if(front!= nullptr){
    front->back= pre;
  }
  temp->next = nullptr;
  temp->back = nullptr;
  delete temp;
  return head;
}
int main() {
  int n;cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  node* head = convertArrToDLL(v);
  head = deleteHeadInDLL(head);
  head = deleteTailOfDLL(head);
  //enter value of k that node you want to delete|
  int k;cin>>k;
  head = deleteKthElementInDLL(head,k);
  // enter val to be deleted in linked list||
  int val;cin>>val;
  head = deleteByValInDLL(head,val);
  node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  return 0;
}