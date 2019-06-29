#include<iostream>
using namespace std;
class QueueArray{
	private:
		int front,rear,size,numOfElements;
		int *queueArr;
		void resize(){
			int tempsize = 2*size;
			int tempArr[tempsize];
			for(int i=0;i<size;i++){
				tempArr[i]=queueArr[i];
			}
			
			delete [] queueArr;
			queueArr=tempArr;
			front=0;
			rear=size-1;
			size=tempsize;
		};
	public:
		QueueArray(int size){
			front=rear=-1;
			this->size=size;
			numOfElements=0;
			queueArr=new int [size];
		}
		void enqueue(int data){
			if(numOfElements == size){
				resize();
			}
			if(front==-1 && rear==-1){
				front=rear=0;
				}
			else{
			rear=(rear+1)%size;	
			}
			
			queueArr[rear]=data;
			numOfElements++;
			
		}
		int dequeue(){
			if (numOfElements==0){
				cout<<"No element in queue"<<endl;
				return -1;
			}
			else {
				int temp = queueArr[front];
				if(front==rear){
					front=rear=-1;
				}
				else
				front=(front+1)%size;
			
			numOfElements--;
			return temp;
			}
		
		}
		~QueueArray(){
			delete [] queueArr;
		}
};
int main(){
	QueueArray que(4);
	que.enqueue(1);
	que.enqueue(2);
	cout<<que.dequeue()<<" ";
	que.enqueue(3);
	cout<<que.dequeue()<<" ";
	cout<<que.dequeue()<<" ";
	return 0;
}
