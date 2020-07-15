#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

#define MAX 100000
#define SENTINEL INT_MAX
struct Card{
	char suit;
	int value;
};

struct Card L[MAX/2+2],R[MAX/2+2];

void merge(struct Card A[],int n,int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	for(int i=0;i<n1;i++)L[i]=A[left+i];
	for(int i=0;i<n2;i++)R[i]=A[mid+i];
	L[n1].value=R[n2].value=SENTINEL;
	int i=0,j=0;
	for(int k=left;k<right;k++){
		if(L[i].value<=R[j].value){
			A[k]=L[i++];
		}else{
			A[k]=R[j++];
		}
	}
}

void mergeSort(struct Card A[],int n,int left,int right){
	if(left+1<right){
		int mid=(left+right)/2;
		mergeSort(A,n,left,mid);
		mergeSort(A,n,mid,right);
		merge(A,n,left,mid,right);
	}
}

int partition(struct Card A[],int p,int r){
	struct Card x,tmp;
	x=A[r];
	int i=p-1;
	for(int j=p;j<r;j++)if(A[j].value<=x.value)swap(A[++i],A[j]);
	swap(A[i+1],A[r]);
	return i+1;
}

void quickSort(struct Card A[],int p,int r){
	int q;
	if(p<r){
		q=partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main(){
	int n,i,v;
	struct Card A[MAX],B[MAX];
	char S[10];
	bool stable=true;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>S>>v;
		A[i].suit=B[i].suit=S[0];
		A[i].value=B[i].value=v;
	}
	
	mergeSort(A,n,0,n);
	quickSort(B,0,n-1);
	
	for(int i=0;i<n;i++)if(A[i].suit!=B[i].suit)stable=false;
	
	
	cout<<(stable?"Stable\n":"Not stable\n");
	for(int i=0;i<n;i++)cout<<B[i].suit<<" "<<B[i].value<<endl;
	return 0;
}