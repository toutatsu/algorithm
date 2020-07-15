#include<iostream>
#include<cmath>

const long long int MOD=1000000007;
using namespace std;

typedef unsigned long long ull;

ull power(ull x,ull n){
	ull res=1;
		if(n>0){
			res=power(x,n/2);
			if(n%2==0)res=(res*res)%MOD;
			else res=(((res*res)%MOD)*x)%MOD;
		}
	return res;
}
int main(){
	ull m,n;
	cin>>m>>n;
	cout<<power(m,n)<<endl;
	return 0;
}