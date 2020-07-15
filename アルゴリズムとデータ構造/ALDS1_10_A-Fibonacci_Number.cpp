#include<iostream>
using namespace std;

int dp[50];


int fib(int n){
	for(int i=0;i<50;i++)dp[i]=0;
	if(n==0||n==1)return dp[n]=1;
	if(dp[n])return dp[n];
	return dp[n]=fib(n-1)+fib(n-2);
}

int main(){
	int n;cin>>n;
	
	//cout<<fib(n)<<endl;
	dp[0]=dp[1]=1;
	for(int i=2;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
	cout<<dp[n]<<endl;
	return 0;
}