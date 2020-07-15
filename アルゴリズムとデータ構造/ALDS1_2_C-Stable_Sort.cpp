#include<iostream>
#include<algorithm>
using namespace std;

struct Card{char suit,value;};

void bubble(struct Card A[],int N){
	for(int i=0;i<N;i++){
		for(int j=N-1;j>=i+1;j--){
			if(A[j].value<A[j-1].value){
				swap(A[j],A[j-1]);
			}
		}
	}
}

void selection(struct Card A[],int N){
	for(int i=0;i<N;i++){
		int minj=i;
		for(int j=i;j<N;j++){
			if(A[j].value<A[minj].value)minj=j;
		}
		swap(A[i],A[minj]);
	}
}

void print(struct Card A[],int N){
	for(int i=0;i<N;i++){
		if(i)cout<<" ";
		cout<<A[i].suit<<A[i].value;
	}
	cout<<endl;
}

bool isStable(struct Card C1[],struct Card C2[],int N){
	for(int i=0;i<N;i++)if(C1[i].suit!=C2[i].suit)return false;
	return true;
}

int main(){
	Card C1[100],C2[100];
	int N;
	char ch;
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>C1[i].suit>>C1[i].value;
		C2[i]=C1[i];
	}
	
	bubble(C1,N);
	selection(C2,N);
	
	print(C1,N);
	cout<<"Stable"<<endl;
	
	print(C2,N);
	cout<<(isStable(C1,C2,N)?"Stable":"Not stable")<<endl;
	
	return 0;
}