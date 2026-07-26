// learning of internal queue operation 
#include <iostream>
using namespace std;

class Q{
	int start = -1,end = -1 ,arr[10],arrsize = 0;
public:
	void push(int x){
		if (arrsize == 10) {
  	  cout << "Queue Overflow\n";
  	  return;
		}
		else if(arrsize == 0){
			start = 0,end = 0;
		}
		else {
			end = (end+1)%10;
		}
		arr[end] =x;
		arrsize++;
		return ;
	}
	void pop( ){
		if (arrsize == 0) {
  		  cout << "Queue Underflow\n";
 	  	 return;
		}
		if(arrsize == 1){
			start =-1, end = -1;
		}
		else start = (start+1)%10;
		arrsize--;
		return;
	}
	int  top( ){
		if(arrsize == 0) return -1;
		return arr[start];
	}
	int  size( ){
		return arrsize;
	}
};	

int main() {
	cout<<"\n";
	return 0;
}
