#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node(int x){
		data=x;
		next=NULL;
	}
};

void display(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void insertAfter(node *prev,int x){
	if(prev==NULL){
		cout<<"Null previous node not allowed\n";
		return;
	}
	
	node *new_node=new node(x);
	new_node->next=prev->next;
	prev->next=new_node;
}

void push(node **head,int x){//insert at beginning
	node *n=new node(x);
	if(head==NULL){
		*head=n;
		return;
	}
	n->next=*head;
	*head=n;
}

void append(node **head,int x){
	node *n=new node(x);
	node *temp=*head;
	if(*head==NULL){
		*head=n;
		return;
	}
		
	while((temp)->next!=NULL)
		temp=(temp)->next;
	temp->next=n;
}

void findNode(node **head,int x){
	if(*head==NULL)
		return;
	
	while((*head)!=NULL && (*head)->data!=x){
		(*head)=(*head)->next;
	}
}

void deleteNode(node **head,int x){
	node *temp=*head;
	if((*head)->data==x){
		*head=temp->next;
		delete temp;
		return;
	}
	
	node *prev;
	while(temp!=NULL && temp->data!=x){
		prev=temp;
		temp=temp->next;
	}
	
	if(temp!=NULL){
		prev->next=temp->next;
		delete temp;
	}
}

void deleteAfter(node *prev){
	if(prev==NULL || prev->next==NULL)
		return;
	node *temp=prev->next;
	prev->next=prev->next->next;
	delete temp;
}

int main(){
	node *head=NULL;
	push(&head,1);
//	append(&head,1);
	append(&head,2);
	push(&head,3);
	node *temp=head;
	findNode(&temp,2);
	if(temp!=NULL)
		insertAfter(temp,4);
	
//	deleteNode(&head,2);
//	deleteNode(&head,3);
	deleteAfter(head->next);
	display(head);
	
}
