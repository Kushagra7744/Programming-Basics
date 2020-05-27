#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

void sieve_of_eratosthenes(int n){
	bool is_prime[n+1];
	memset(is_prime,true,sizeof(is_prime));
	
	for(int i=2;i<=sqrt(n);i++){
		if(is_prime[i]){
			for(int j=i*i;j<=n;j+=i){
				is_prime[j]=false;
			}
		}
	}
	
	for(int i=2;i<=n;i++){
//		cout<<is_prime[i]<<endl;
		if(is_prime[i]==true)
			cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
	int n;// print prime numbers upto n
	cin>>n;
	sieve_of_eratosthenes(n);
}
