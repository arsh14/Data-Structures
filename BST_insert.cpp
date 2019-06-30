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
		void removePrivate(int data, Node *&root){
			if(root==NULL){
				return;
			}
			else if(data<root->data){
				removePrivate(data, root->left);
			}
			else if(data>root->data){
				removePrivate(data, root->right);
			}
			else{
				if (root->left==NULL && root->right==NULL){
					delete root;
					root=NULL;
				}
				else if(root->left==NULL){
					Node *temp=root;
					root=root->right;
					delete temp;
				}
				else if(root->right==NULL){
					Node *temp=root;
					root=root->left;
					delete temp;
				}
				else {
					Node *temp=findMin(root->right);
					root->data=temp->data;
					removePrivate(temp->data,root->right);
					}
				}
			}
		Node* findMin(Node *root){
			while (root->left!=NULL){
				root=root->left;
			}
			return root;
				
	}
	public:
		BST(){
			root=NULL;
		}
		void insert(int data){
			insertPrivate(data, *&root);
		}
		void remove(int data){
			removePrivate(data, *&root);
		}
	
		
};

int main(){
	BST tree;
	tree.insert(10);
	tree.insert(6);
	tree.insert(3);
	tree.insert(9);
	tree.insert(12);
	tree.remove(6);
	return 0;
	
}

