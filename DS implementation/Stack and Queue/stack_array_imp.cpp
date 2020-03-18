#include<iostream>
#define N 1000
using namespace std;


class stack{
	int top;
	public:
		int a[N];
		
		stack(){
			top=-1;
		}
		bool push(int x);
		int pop();
		int peek();
		bool isEmpty();
};

bool stack::push(int x){
	//stack is full
	if(top>=N-1)
		return false;
	top++;
	a[top]=x;
	return true;
}

bool stack::isEmpty(){
	if(top<0)
		return true;
	return false;
}

int stack::pop(){
	//empty stack
	if(this->isEmpty())
		return -1;
	
	return a[top--];
}

int stack::peek(){
	if(this->isEmpty())
		return -1;
	return a[top];
}


int main(){
	stack s1;
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	cout<<"Top element= "<<s1.peek()<<"\n";
	cout<<"Popped elements: ";
	cout<<s1.pop()<<" ";
	cout<<s1.pop()<<" ";
	cout<<s1.pop()<<" ";
	cout<<s1.pop()<<" \n";
	
	
	if(s1.isEmpty())
		cout<<"Empty Stack\n";
	return 0;
}
