#include<iostream>
using namespace std;

struct Node{
	int data,height;
	Node *left, *right;
};

//max of 2 integers
int max(int a, int b){
	return a>b?a:b;
}

//construction of a new node
Node *newnode(int d){
	Node *temp= new Node;
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	
	return temp;
}

//calculating height of a node
int height(Node *node){
	return node==NULL?0:(node->height);
}


//calculating balance factor
int getBalanceFactor(Node *node){
	return node==NULL?0:(height(node->left)-height(node->right));//left-right
}


Node *leftRotate(Node *y){//see img AVL_insert1
	Node *x=y->right;
	Node *T1=x->left;
	
	//rotation
	x->left=y;
	y->right=T1;
	
	//updating height
	y->height= 1+ max(height(y->left),height(y->right));
	x->height= 1+ max(height(x->left),height(x->right));
	
	return x;//returning new head of subtree
}

Node *rightRotate(Node *y){//see image AVL_insert1
	Node *x=y->left;
	Node *T2=x->right;
	
	//rotation
	x->right=y;
	y->left=T2;
	
	//updating heights
	y->height= 1+ max(height(y->left),height(y->right));
	x->height= 1+ max(height(x->left),height(x->right));
	
	return x;
}

//print preorder traversal of tree
void preOrder(Node *root){
	if(root==NULL)
		return;
	
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

Node *insert(Node *node, int dat){
	//simple BST insertion
	if(node==NULL)
		return newnode(dat);
		
	else if(dat>node->data)
		node->right=insert(node->right,dat);
		
	else if(dat<node->data)
		node->left=insert(node->left,dat);
		
	else//equal data nodes not allowed
		return node;
		
	//height updation
	node->height= 1+max(height(node->right),height(node->left));
	
	int bal= getBalanceFactor(node);
	
	//checking balance factor
	
	//if bal>1 the it is either left-left or left-right case
	//if dat<node->left then it is left-left
	//else it is right-right
	
	
	if(bal>1 && dat<node->left->data){//LEFT-LEFT
		//right rotate about pivot
		return rightRotate(node);
	}
	
	if(bal>1 && dat>node->left->data){//LEFT-RIGHT
		//left rotate about pivot->left
		node->left=leftRotate(node->left);
		
		//right rotate about pivot
		return rightRotate(node);	
	}
	
	//if bas<1 it is either right-right or right-left
	//if dat<node->right then it is right-left
	//else it is right-right
	
	if(bal<-1 && dat>node->right->data){//RIGHT-RIGHT
		//left rotate about pivot
		return leftRotate(node);
	}
	
	
	if(bal<-1 && dat<node->right->data){//RIGHT-LEFT
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	
	//balanced node
	return node;
	
}
	

	
int main()  
{  
    Node *root = NULL;  
      
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
      
   
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
      
    return 0;  
}  
