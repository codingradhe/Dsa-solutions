// 🖊️🖊️🖊️🖊️ dont declare one variable again and agaiin  like -->
// if temp once declare then dont declare again but resign that as --> ♥️♥️ temp = head ;♥️♥️
class Solution {
	public:
	Node* reverseLL(Node* head){
	    if(head == nullptr || head->next == nullptr) return head;
	    Node* temp = head;
	    Node* pre = nullptr;
	    while(temp){
	        Node* front = temp->next;
	        temp->next = pre;
	        pre = temp;
	        temp = front;
	    }
	    return pre;
	}
	Node* addOne(Node* head) {
		if (head == nullptr)
			return nullptr;
		Node* temp = head;
		head = reverseLL(temp);
		temp = head;
		int carry = 1;
		while(temp){
		    temp->data = temp->data+ carry;
		    if(temp->data == 10){
		        carry = 1;
		        temp->data = 0;
		        temp = temp->next;
		    }
		    else break;
		}
		Node* temp = head;
		head = reverseLL(temp);
		if(carry){
		    Node* newhead = new Node(1);
		    newhead->next = head;
		    return newhead;
		}
		return head;
	}
};



