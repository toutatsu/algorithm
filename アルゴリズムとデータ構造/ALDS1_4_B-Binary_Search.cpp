#include<iostream>
#include<algorithm>//lower_bound
using namespace std;

int A[1000000],n;

bool binarySearch(int key){
	int left=0,right=n,mid;
	while(left<right){
		mid=(left+right)/2;
		if(key==A[mid])return true;
		else if(key>A[mid])left=mid+1;
		else if(key<A[mid])right=mid;
	}
	return false;
}
int main(){
	int q,k,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)cin>>A[i];
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>k;
		//if(binarySearch(k))sum++;
		if(*lower_bound(A,A+n,k)==k)sum++;//STL
	}
	cout<<sum<<endl;
	return 0;
}