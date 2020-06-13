#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//linear time complexity in worst case
int find(int parent[],vector<vector<int> > &g,int i){
	if(parent[i]==-1)
		return i;
	return find(parent,g,parent[i]);
}

//linear time complexity in worst case
void unionn(int parent[],vector<vector<int> > &g, int i,int j){
	int iset=find(parent,g,i),jset=find(parent,g,j);
	parent[jset]=iset;
	return;
}

bool isCycle(int parent[],vector<vector<int> > &g){
	for(int i=0;i<g.size()-1;i++){
		for(int j=i+1;j<g.size();j++){
			if(g[i][j]==1){
				
				int x=find(parent,g,i),y=find(parent,g,j);
				if(x==y)
					return true;
				unionn(parent,g,x,y);
			}
		}
	}
	return false;
}

int main(){
	int V,E,v1,v2;
	cout<<"Enter no of vertices:\n";
	cin>>V;
	cout<<"Enter no of edges:\n";
	cin>>E;
	vector<vector<int> >g(V,vector<int>(V));
	
	for(int i=0;i<E;i++){	
		cout<<"Enter "<<(i+1)<<" edge:\n";		
		cin>>v1>>v2;
		g[v1][v2]=1;
		g[v2][v1]=1;
	}
	//graph is ready
	
	int parent[V];
	memset(parent,-1,sizeof(int)*V);
	if(isCycle(parent,g))
		cout<<"Yes, graph is cyclic\n";
	else
		cout<<"No, graph is not cyclic\n";
		
	
	
	
	
	return 0;
}
