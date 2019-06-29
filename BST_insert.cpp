#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *left,*right;
		Node(int data){
			this->data=data;
			left=right=NULL;
	}
};
class BST{
	private:
		Node *root;
		void insertPrivate(int data, Node *&root){
			if(root==NULL){
				root=new Node(data);
			}
			else if(data<root->data){
				if(root->left!=NULL)
				insertPrivate(data, root->left);
				else
				root->left=new Node(data);
			}
			else if(data>root->data){
				if(root->right!=NULL)
				insertPrivate(data, root->right);
				else
				root->right=new Node(data);
			}
			
		}
		
	public:
		BST(){
			root=NULL;
		}
		void insert(int data){
			insertPrivate(data, *&root);
		}
};

int main(){
	BST tree;
	tree.insert(10);
	tree.insert(6);
	tree.insert(3);
	tree.insert(9);
	tree.insert(12);
	
}

