#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next=NULL;
};

struct Node *top=NULL;

Node *newnode(int data){
	Node *node=new Node;
	node->data=data;

	return node;
}

bool isEmpty(){
	return top==NULL;
}

void push(int data){
	Node *temp= newnode(data);
	temp->next=top;
	top=temp;
}

int pop(){
	if(isEmpty())
		return -1;
	
	Node *temp=top;
	top=top->next;
	int dat=temp->data;
	delete temp;
	return dat;
}

int peek(){
	if(top==NULL)
		return -1;
	
	return top->data;
}

int main(){
	
	push(2);
	push(3);
	push(4);
	push(5);
	cout<<"Top Element is: ";
	cout<<peek()<<endl;
	cout<<"Popped elements are: ";
	cout<<pop()<<" ";
	cout<<pop()<<" ";
	cout<<pop()<<" ";
	cout<<pop()<<" \n";
	
	if(isEmpty())
		cout<<"Stack is empty\n";
	return 0;
}
