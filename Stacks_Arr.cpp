#include<iostream>
using namespace std; 
class StackArray{
	private:
		int size;
		int *stackArr;
		int top;
		void resize(){
			int tempSize=size*2;
			int *temp= new int[tempSize];
			for(int i=0;i<size;i++){
				temp[i]==stackArr[i];
				delete [] stackArr;
				stackArr = temp;
				size = tempSize;
			}
		}
	public:
		StackArray(int size){
			this->size=size;
			stackArr=new int[size];
			top=-1;
		}
		void push(int data){
			if (top==size-1)
			resize();
			stackArr[++top]=data;
		}
		int pop(){
			if(top==-1){
			cout<<"Empty Stack";
			return 0;
			}
			return stackArr[top--];
		}
		void dispStack(){
			while(top!=-1){
				int i;
				i=pop();
				cout<<i<<"\n";
			}
		}
		~StackArray(){
			delete [] stackArr;
		}
};
int main(){
	StackArray stack(4);
	stack.push(1);
	stack.push(10);
	stack.push(20);
	cout<<"........................\n";
	stack.dispStack();
	return 0;
}
