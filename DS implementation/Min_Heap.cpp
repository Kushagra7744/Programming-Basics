#include<iostream>
#include<climits>
using namespace std;
//implement insert, extractMin,delete
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

class minHeap{
	int capacity;
	int size;
	int *heap;
	
	public:
	
	minHeap(int c){
		capacity=c;
		size=0;
		heap=new int[c];
	}
	
	int leftIdx(int i){return 2*i +1;}
	int rightIdx(int i){return 2*i +2;}
	int parentIdx(int i){return (i-1)/2;}
	
	void heapifyUP(int);
	void heapifyDOWN(int);
	void ensureCapacity();
	void LevelOrder();
	
	int extractMin();
	int getMin();
	void deleteKey(int);
	void decreaseKey(int,int);
	void insert(int);
};

void minHeap::LevelOrder(){
	for(int i=0;i<size;i++)
		cout<<heap[i]<<" ";
	cout<<endl;
}

int minHeap::getMin(){
	if(size<=0)
		return INT_MIN;
	return heap[0];
}
void minHeap::insert(int val){
	ensureCapacity();
	heap[size]=val;
	size++;
	heapifyUP(size-1);
}

void minHeap::ensureCapacity(){
	if(size==capacity){
		int *new_heap= new int[capacity*2];
		for(int i=0;i<size;i++)
			new_heap[i]=heap[i];
		capacity*=2;
		heap=new_heap;
	}
}

void minHeap::decreaseKey(int index,int val){
	if(index>size){
		cout<<"Invalid index\n";
		return;
	}
	
	heap[index]=val;
	heapifyUP(index);
	heapifyDOWN(index);
}

int minHeap::extractMin(){
	if(size<=0){
		cout<<"Empty heap\n";
		return INT_MIN;
	}
		
	int res=heap[0];
	heap[0]=heap[size-1];
	size--;
	heapifyDOWN(0);
	return res;
}

void minHeap::deleteKey(int index){
	if(index>size){
		cout<<"Invalid index\n";
	}
	decreaseKey(index,INT_MIN);
	extractMin();
}

void minHeap::heapifyUP(int index){
	while(index>0 && heap[index]<heap[parentIdx(index)]){
		swap(heap[index],heap[parentIdx(index)]);
		index=parentIdx(index);
	}
}

void minHeap::heapifyDOWN(int i){
	if(i>=size)
		return;
	
	int smallIndex=i;
	
	if(leftIdx(i)<size && heap[smallIndex]>heap[leftIdx(i)])
		smallIndex=leftIdx(i);
	if(rightIdx(i)<size && heap[smallIndex]>heap[rightIdx(i)])
		smallIndex=rightIdx(i);
	
	if(smallIndex==i)
		return;
		
	swap(heap[i],heap[smallIndex]);
	heapifyDOWN(smallIndex);
}

int main(){
	
	minHeap ob(10);
	ob.insert(1);
	ob.insert(2);
	ob.insert(3);
	ob.insert(4);
	ob.insert(5);
	ob.insert(6);
	ob.insert(7);
	ob.insert(16);
	ob.deleteKey(5);
	ob.decreaseKey(4,0);
	ob.LevelOrder();	
	ob.extractMin();
	ob.LevelOrder();
	cout<<ob.getMin()<<endl;	
	
	return 0;
}















