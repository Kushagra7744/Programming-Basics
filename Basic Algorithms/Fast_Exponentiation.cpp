#include<bits/stdc++.h>
#define M 1000000007
#define ll long long int
using namespace std;


ll fast_exp_itr(ll base,ll exp){
	ll res=1;
	while(exp>0){
		if(exp%2==1)//odd
			res=res*base%M;
			
		base=(base*base)%M;
		exp/=2;
	}
	return res;
}

int main(){
	ll exp=25;
	ll base=4;
	cout<<fast_exp_itr(base,exp)<<endl;
	return 0;
}
