#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node *prev;


	Node(int data){
		this->data= data;
		next = NULL;
		prev = NULL;
	}
};

class LinkedList{
	private:
		Node *header;
		Node *tail;
		int size;
	public:
		LinkedList(){
			header=NULL;
			tail=NULL;
			size=0;
		}
		int getSize(){
		return size;
		}
		~LinkedList(){
		Node *next;
		while(header!=NULL){
			next=header;
			delete header;
			header=next;
		}
		size=0;
		}
		void toString(){
			Node *temp=header;
			while(temp != NULL){
				
				cout<< temp->data << " ";
				temp=temp->next;
			}
		}


		void prepend(int data){
			Node *n= new Node(data);
			if (header==NULL){
				header=n;
				tail=n;
			}
			else {
				header->prev=n;
				n->next=header;
				header=n;
			}
			size++;
		}
		void append(int data){
			Node *n= new Node(data);
			if(header==NULL){
				header=n;
				tail=n;
			}
			else{
				tail->next=n;
				n->prev=tail;
				tail=n;
			}
			size++;
		}
		void insertAt(int pos,int data){
			
			if(pos<1 || pos>size+1){
			cout<<"invalid";
			return;
			}
			else if(pos==1){
				prepend(data);
			}
			else if(pos==size+1){
				append(data);
			}
			else if(header!=NULL){
				Node *n=new Node(data);
				Node *temp=header;
				for(int i=1;i<pos;i++){
					temp=temp->next;
				}
				temp->prev->next=n;
				n->prev=temp->prev;
				n->next=temp;
				temp->prev=n;
				size++;
			}
			
		}
		void toStringReverse(){
			Node *N=tail;
			while(N!=NULL){
				cout<<N->data<<" ";
				N=N->prev;
			}
		}
		void removeFirst(){
			if(header->next==NULL){
				delete header;
				header=NULL;
				tail=NULL;
				size--;
			}
			else if(header!=NULL){
				header=header->next;
				delete header->prev;
				header->prev=NULL;
				size--;
			}
			
		}
		void removeLast(){
			if(header->next==NULL){
				delete header;
				header=NULL;
				tail=NULL;
				size--;
			}
			else if(header!=NULL){
				tail=tail->prev;
				delete tail->next;
				tail->next=NULL;
				size--;
			}
			
		}
		void removeAt(int pos){
		if(pos<1 || pos>size+1){
			cout<<"invalid";
			return;
			}
		else if(pos==1){
			removeFirst();
			}
		else if(pos==size){
			removeLast();
		}
		else if(header!=NULL){
			Node *cur=header;
			for(int i=1;i<pos;i++){
				cur=cur->next;
			}
			cur->prev->next=cur->next;
			cur->next->prev=cur->prev;
			delete cur;
			size--;
		}
		}
		
		
};

int main(){
	LinkedList list;
	list.prepend(1);
	list.prepend(2);
	list.prepend(3);
	list.append(10);
	list.append(11);
	list.insertAt(4,9);
	list.toString();
	cout<<"\n";
	list.toStringReverse();
	list.removeFirst();
	cout<<"\n";
	list.toString();
	list.removeLast();
	cout<<"\n";
	list.toString();
	list.removeAt(2);
	cout<<"\n";
	list.toString();
	return 0;
	
	}
