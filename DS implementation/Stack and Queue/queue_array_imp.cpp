//INCOMPLETE: needs modification
#include<iostream>
#define N 1000
using namespace std;

class queue{
	int front,back;
	public:
		queue(){
			front=-1;
			back=-1;
		}
		int a[N];
		bool push(int x);
		int pop();
		int peek();
		bool isEmpty();
};

bool queue::isEmpty(){
	return (front==-1 && back==-1);
}

bool push(int x){
	if(front==(back+1)%N)
		return false;
	
	if(front==-1){
		back++;
		front++;
		a[back]=x;
		return true;
	}
	a[(++back)%N]=x;
	return true;
}

int pop(){
	int x=a[front];
	front=(front+1)%N;
	
}
