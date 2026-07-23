// class node{
//     public:
//     int data;
//     node* next;
//     node* back;
//     public:
//     node(int data1,node* next1,node* back1){
//         data = data1;
//         next = next1;
//         back = back1;
//     }
//     public:
//     node(int data1){
//         data = data1;
//         next = nullptr;
//         back = nullptr;
//     }
// };
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
