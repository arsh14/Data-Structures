#include<iostream>
using namespace std;
class BinaryMaxHeap{
	private:
		int *heap;
		int heapSize;
		int arraySize;
		int getLeftChild(int index){
			return 2*index+1;
		}
		int getRightChild(int index){
			return 2*index+2;
		}
		int getParent(int index){
			return ((index-1)/2);
		}
		void swap(int i,int j){
			int temp=heap[i];
			heap[i]=heap[j];
			heap[j]=temp;
		}
		bool hasLeft(int index){
			return getLeftChild(index)<heapSize;
		}
		bool hasRight(int index){
			return getRightChild(index)<heapSize;
		}
	public:
		BinaryMaxHeap(int size){
			heap=new int[size];
			heapSize=0;
			arraySize = size;
		}
		void insert(int data){
			if(heapSize==arraySize){
				return;
			}
			else{
				heap[heapSize]=data;
				heapSize++;
				heapifyUp(heapSize-1);
			}
		}
		void heapifyUp(int index){
			if(index!=0){
				int parent=getParent(index);
				if(heap[parent]<heap[index]){
					swap(parent,index);
					heapifyUp(parent);
				}
			}
		}
		void show(){
			for(int i=0;i<heapSize;i++){
			cout<<heap[i]<<" ";
			}
		}
		int removeMax(){
			if(heapSize==0)
			return -1;
			else{
				int root=heap[0];
				heap[0]=heap[heapSize-1];
				heapSize--;
				if(heapSize>1)
				heapifyDown(0);
				return root;
			}
		}
		void heapifyDown(int index){
			int leftChild=getLeftChild(index);
			int rightChild=getRightChild(index);
			int max=index;
			if(hasLeft(index)&& heap[leftChild]>heap[max])
			max=leftChild;
			if(hasRight(index)&& heap[rightChild]>heap[max])
			max=rightChild;
			if(max!=index){
				swap(index,max);
				heapifyDown(max);
			}
				
		}
		
};
int main(){
	BinaryMaxHeap heap(7);
	heap.insert(10);
	heap.insert(5);
	heap.insert(3);
	heap.insert(1);
	heap.insert(25);
	heap.insert(2);
	heap.insert(90);
	heap.show();
	heap.removeMax();
	heap.removeMax();
	cout<<"\n";
	heap.show();
	return 0;
}
