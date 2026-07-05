#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    public:
    node(int data1,node* next1){
        data = data1,next = next1;
    }
    public:
    node(int data1){
        data = data1,next = nullptr;
    }
};
node* convertArrToLL(vector<int> &v){
    if(v.empty()) return nullptr;
    node* head = new node(v[0]);
    node* mover = head;
    for(int i=1;i<v.size();i++){
        node* temp = new node(v[i]);
        mover->next = temp;
        mover = temp ;
    }
    return head;
}
int main() {
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    node* head = convertArrToLL(v);
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    return 0;
}
