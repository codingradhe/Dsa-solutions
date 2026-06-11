#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int  data;
    node* next;
    node* back;
    public:
    node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
    public:
    node(int data1,node* next1,node* back1){
        data = data1;
        next = next1;
        back =back1;
    }
};
node* convertArrToDLL(vector<int> & v){
    if(v.empty()) return nullptr;
    node* head = new node(v[0]);
    node* pre = head;
    for(int i=1;i<v.size();i++){
        node* temp=new node(v[i]);
        temp->back = pre;
        pre->next= temp;
        pre= temp;
    }
    return head;
}
int main() {
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    node* head=convertArrToDLL(v);
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}
