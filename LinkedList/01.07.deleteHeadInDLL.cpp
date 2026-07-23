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
//***😘😘😘 delete Head of LL.***
node* deleteHeadInDLL(node* head){
  if(head == NULL) return head;
  node* temp = head;
  head = head->next;
  head->back = nullptr;
  delete temp;
  return head;
}
