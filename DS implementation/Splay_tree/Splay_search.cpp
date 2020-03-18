#include<iostream>
using namespace std;

struct Node{
	int data,height;
	Node *left, *right;
};

Node *newnode(int d){
	Node *temp= new Node;
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

Node *leftRotate(Node *y){
	Node *x=y->right;
	Node *T1=x->left;
	
	x->left=y;
	y->right=T1;
	
	return x;
}

Node * rightRotate(Node *y){
	Node *x=y->left;
	Node *T2=x->right;
	
	x->right=y;
	y->left=T2;
	
	return x;
}

Node *splay(Node *root,int key){
	if(root==NULL || root->data==key)
		return root;
	
	
//	left subtree has the key
	if(root->data>key){
		
//		key is not found
		if(root->left==NULL)
			return root;
			
//		left-left or zig-zig	
		if(root->left->data>key){
			root->left->left=splay(root->left->left,key);
			
			root=rightRotate(root);
		}
		
//		left-right or zig-zag
		else if(root->left->data<key){
			root->left->right=splay(root->left->right,key);
			
			if(root->left->right!=NULL)
				root->left=leftRotate(root->left);
		}
		
//		second rotation
		return root->left==NULL?root:rightRotate(root);
		
	}
	
//	present in right subtree
	else{
		if(root->right==NULL||root->data==key)
			return root;
//		right-right
		if(root->right->data<key){
			root->right->right=splay(root->right->right,key);
			
			root=leftRotate(root);
		}
		
//		right-left
		else if(root->right->data>key){
			root->right->left=splay(root->right->left,key);
			
			if(root->right->left!=NULL){
				root->right=rightRotate(root->right);
			}
		}
		
//		second rotate
		return  root->right==NULL?root:leftRotate(root);
	}
}

Node *search(Node *root,int key){
	return(splay(root,key));
}



void preOrder(Node *root){
	if(root==NULL)
		return;
	
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}



int main()  
{  
    Node *root = newnode(100);  
    root->left = newnode(50);  
    root->right = newnode(200);  
    root->left->left = newnode(40);  
    root->left->left->left = newnode(30);  
    root->left->left->left->left = newnode(20);  
  
    root = search(root, 20);  
    cout << "Preorder traversal of the modified Splay tree is \n";  
    preOrder(root);  
    return 0;  
}  


