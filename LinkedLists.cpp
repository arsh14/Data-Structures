#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;


	Node(int data){
		this->data= data;
		next = NULL;
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

//Function for appending
void append(int data){
	Node *n = new Node(data);
	if(header==NULL){
		header=n;
		tail=n;
	}
	else{
		tail->next=n;
		tail=n;
	}
	size++;
}
//To prepend
void prepend(int data){
	Node *n= new Node(data);
	if(header==NULL){
		header=n;
		tail=n;
	}
	else{
		Node *temp=header;
		header=n;
		n->next=temp;
	}
	size++;

}
//To print
void toString(){
	Node *temp=header;
	while(temp != NULL){
		
		cout<< temp->data << " ";
		temp=temp->next;
	}
	

}
void removeFirst(){
	if(header!=NULL){
		Node *temp=header;
		header=header->next;
		delete temp;
		size--;
	}
	
}
void removeLast(){
	//empty 
	//1Node
	if(header->next==NULL){
		removeFirst();
	}
	//More than 1 node
	else if(header!=NULL){
		Node *cur=header;
		Node *prev;
		while(cur->next!=NULL){
			prev=cur;
			cur=cur->next;
		}
		prev->next=NULL;
		tail=prev;
		delete cur;
		
	}
	size--;
}

void removeAt(int pos){
	//case1:check for valid pos
	if(pos>size || pos<1){
		cout<< "Invalid pos";
	}
	//case2:check if pos is 1st node
	else if(pos==1){
		removeFirst();
	}
	//case3:check if pos is at last node
	else if(pos==size){
		removeLast();
	}
	//case4: all other cases
	else if(header!=NULL){
		Node *cur,*prev;
		cur=header;
		int count=1;
		while(count<pos){
			prev=cur;
			cur=cur->next;
			count++;
		}
		prev->next=cur->next;
		delete cur;
		size--;
	}
}
void insertAt(int pos, int data){
	//Case1:check for valid pos
	if (pos<1 || pos>(size+1)){
		cout<<"Invalid position";
		return;}
	//Case2:check if insertion at begining of list
	else if(pos==1){
		prepend(data);
	}
	//case3:check if insertion at end of list
	else if(pos==(size+1)){
		append(data);
	}
	//case4:all other cases
	else if(header!=NULL){
		Node *n=new Node(data);
		Node *cur,*prev;
		cur=header;
		for(int i=1;i<pos;i++){
			prev=cur;
			cur=cur->next;
		}
		prev->next=n;
		n->next=cur;
		size++;

	}
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
};


int main(){

	LinkedList list;
	list.append(1);
	list.append(4);
	list.append(10);
	list.prepend(0);
	// list.removeFirst();
	// list.toString();
	// list.removeLast();
	// list.toString();
	list.removeAt(3);
	//list.toString();
	list.insertAt(3,25);
	list.insertAt(1,11);
	list.toString();

	
	return 0;
}