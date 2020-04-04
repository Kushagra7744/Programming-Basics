#include<iostream>
#include<climits>
using namespace std;

struct node{
	int data;
	node *next;
	node(int d){
		data=d;
		next=NULL;
	}
	node(){
		data=INT_MAX;
		next=NULL;
	}
};

class Hash{
	int capacity;
	node *hash_table;
	public:
		Hash(int cap);
		int computeHash(int key);
		void insertKey(int key);
		void deleteKey(int key);
		void displayHash();
		
};

Hash::Hash(int cap){
	capacity=cap;
	(hash_table)= new node[cap];
}

int Hash::computeHash(int key){
	return key%capacity;
}
void Hash::displayHash(){
	for(int i=0;i<capacity;i++){
	    node *temp=&hash_table[i];
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<endl;
	}
}
void Hash::insertKey(int key){
	int index=computeHash(key);
	node *temp=&hash_table[index];
	if(temp->data==INT_MAX){
	    temp->data=key;
	    return;
	}
	while(temp->next!=NULL)
		temp=temp->next;
	node *new_node= new node(key);
	temp->next=new_node;
}

void Hash::deleteKey(int key){
	int index=computeHash(key);
	node *temp=&hash_table[index],*prev;
	
	if(temp->next==NULL){
	    temp->data=INT_MAX;
	    return;
	}
	
	while(temp->next!=NULL || temp->data!=key){
		prev=temp;
		temp=temp->next;
	}
	if(temp!=NULL && temp->data==key){
		prev->next=temp->next;
		cout<<"deleted "<<temp->data<<endl;
		delete temp;
		
	}
	else{
		cout<<"requested key does not exist\n";
	}
}


int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
  
	Hash h(7);   
	
  	for (int i = 0; i < n; i++)  
    	h.insertKey(arr[i]);   
  
//  	h.displayHash();
	
  	h.deleteKey(8); 
  	h.displayHash(); 
  
  	return 0; 
}
