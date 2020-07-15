#include<iostream>
using namespace std;

bool isPrime(int x){
	if(x<2)return false;
	else if(x==2)return true;
	else if(x%2==0)return false;
	for(int i=3;i*i<=x;i+=2){
		if(x%i==0)return 0;
	}
	return true;
}

#include<vector>
using namespace std;

int IsPrime(int n){//The Sieve of Eratosthenes
	vector<int>IsPrime(n+1,1);//1‚Å‰Šú‰»
	IsPrime[0]=0;IsPrime[1]=0;//0‚Æ1‚Í”ñ‘f”
	for(int i=2;i*i<=n;i+=2)if(IsPrime[i])for(int j=i*2;j<=n;j+=i)IsPrime[j]=0;
	for(auto&i:IsPrime)cout<<i;//‘f”ƒe[ƒuƒ‹
	putchar('\n');
	for(int i=0;i<n;i++)if(IsPrime[i])cout<<i<<endl;
	return IsPrime[n];
}

int main(){
	int n,x,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(isPrime(x))cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}