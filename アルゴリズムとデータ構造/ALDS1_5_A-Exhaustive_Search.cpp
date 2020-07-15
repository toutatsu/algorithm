#include<iostream>
using namespace std;

int n,A[50];
bool solve(int i,int m){
	if(m==0)return 1;
	if(i>=n)return 0;
	return (solve(i+1,m)||solve(i+1,m-A[i]));
}

int main(){
	int q,M;
	cin>>n;
	for(int i=0;i<n;i++)cin>>A[i];
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>M;
		cout<<(solve(0,M)?"yes":"no")<<endl;
	}
	return 0;
}