// learn internal implementation operation in queue data structure 
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
class Q{
	private:
		node* startNode = nullptr, endNode = nullptr;
		int qSize = 0;
	public:
		void push(int x ) {
			node* temp = new node(x);
			if(startNode ==nullptr){
				startNode = temp;
				endNode = temp;
			}
			else {
				endNode->next = temp;
				endNode = temp;
			}
			qSize++;
			return;
		}
		void pop( ){
			if(startNode == nullptr){
				cout<<"Queue is empty\n";
				return ;
			}
			else if(startNode ==endNode ){
				node* temp = startNode;
				startNode = nullptr;
				endNode = nullptr;
				delete temp;
				qSize--;
				return;
			}
			node* temp = startNode;
			startNode = startNode->next;
			delete temp;
			qSize--;
			return;
		}
		int top( ){
			if(startNode == nullptr) {
				cout<<"Queue is empty\n";
				return -1;
			}
			else return startNode->val;
		}
		int size( ){
			return qSize;
		}	
};	

int main() {
	cout<<"hellow world";
	return 0;
}

