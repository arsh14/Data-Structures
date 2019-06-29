#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node *prev;
		Node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
			
		}
	};
class stackll{
	private:
		Node *top;
	public:
		stackll(){
			top=NULL;
		}
		void push(int data){
			Node *n= new Node(data);
			if(top==NULL){
				top=n;
			}
			else{
				top->next=n;
				n->prev=top;
				top=n;
			}
			
		}
		int pop(){
			if (top==NULL){
				cout<<"stack empty";
				return -1;
			}
			else{
				int tempData=top->data;
				Node *temp=top;
				top=top->prev;
				delete temp;
				return tempData;
			}
		}
		void dispStack(){
			int i;
			while(top!=NULL){
				
				i=pop();
				cout<<i<<"\n";
				
			}
		}
};

int main(){
	stackll stack;
	stack.push(1);
	stack.push(10);
	stack.push(20);
	cout<<"........................\n";
	
	cout<<stack.pop();
	cout<<stack.pop();
	cout<<stack.pop();
	
	return 0;
	
}
		
		
	

