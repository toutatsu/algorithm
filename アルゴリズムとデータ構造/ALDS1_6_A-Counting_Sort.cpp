#include<iostream>
using namespace std;

#define MAX 2000001
#define VMAX 10000

int main(){
	int C[VMAX+1]={0},n,*A,*B;
	cin>>n;
  
	A=(int*)malloc(sizeof(int)*(n+1));
	B=(int*)malloc(sizeof(int)*(n+1));
	
	for(int i=0;i<=VMAX;i++)C[i]=0;
	for(int i=0;i<n;C[A[i+1]]++,i++)cin>>A[i+1];
	for(int i=1;i<=VMAX;i++)C[i]+=C[i-1];
	for(int i=1;i<=n;C[A[i]]--,i++)B[C[A[i]]]=A[i];
	for(int i=1;i<=n;i++){
		if(i-1)cout<<" ";
		cout<<B[i];
	}
	cout<<endl;
	return 0;
}