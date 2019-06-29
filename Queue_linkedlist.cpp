#include<iostream>
using namespace std;
class Node {
	public:
	Node *next;
	int data;
	Node(int data){
		this->data=data;
		this->next=NULL;
	}
};
class Queuell{
	private:
		Node* front;
		Node *rear; 
		
	public:
		Queuell(){
			front=rear=NULL;
		}
		void enqueue(int data){
			Node *n= new Node(data);
			if(front==NULL && rear==NULL){
				front=rear=n;
				}
			else{
			rear->next=n;
			rear=n;
		}
		}
		int dequeue(){
			if (front==NULL ){
				cout<<"No element in queue"<<endl;
				return -1;
			}
			else {
				int temp=front->data;
				Node *f=front;
				if(front==rear){
					front=rear=NULL;
				}
				else
				front=front->next;
			delete f;
			return temp;
			}
		
		}
		~Queuell(){
			Node *temp;
			while (front!=NULL ){
				temp=front;
				front=front->next;
				delete temp;
				
			}
			
		}
};
int main(){
	Queuell que;
	que.enqueue(1);
	que.enqueue(2);
	cout<<que.dequeue()<<" ";
	que.enqueue(3);
	cout<<que.dequeue()<<" ";
	cout<<que.dequeue()<<" ";
	return 0;
}
