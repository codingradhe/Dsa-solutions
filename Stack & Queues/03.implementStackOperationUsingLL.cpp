#include <iostream>
using namespace std;

class node{
	public:
	int val;
	node* next;
	
	node(int x) : val(x),next (nullptr) { }
	node(int x,node* next) : val(x),next(next) { }
	node( ) :val(0), next(nullptr){ }
};
class st{
	private:
		node* topNode = nullptr;
		int stSize = 0;
	public:
		void push(int x ) {
			node* temp = new node(x);
			temp->next = topNode;
			topNode = temp;
			stSize++;
			return;
		}
		void pop( ){
			if(topNode == nullptr){
				cout<<"Stack is empty\n";
				return ;
			}
			node* temp = topNode;
			topNode = topNode->next;
			delete temp;
			stSize--;
			return;
		}
		int top( ){
			if(topNode == nullptr) {
				cout<<"Stack is empty\n";
				return -1;
			}
			else return topNode->val;
		}
		int size( ){
			return stSize;
		}	
};	

int main() {
	cout<<"hellow world";
	return 0;
}
