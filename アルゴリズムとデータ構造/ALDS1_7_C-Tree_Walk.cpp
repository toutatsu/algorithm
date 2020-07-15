#include<iostream>
using namespace std;
#define MAX 10000
#define NIL -1

struct Node{int parent,left,right;};

Node T[MAX];
int n;

void preParse(int u){
	if(u==NIL)return;
	cout<<" "<<u;
	preParse(T[u].left);
	preParse(T[u].right);
}

void inParse(int u){
	if(u==NIL)return;
	inParse(T[u].left);
	cout<<" "<<u;
	inParse(T[u].right);
}

void postParse(int u){
	if(u==NIL)return;
	postParse(T[u].left);
	postParse(T[u].right);
	cout<<" "<<u;
}

int main(){
	int v,l,r,root=0;
	cin>>n;
	
	for(int i=0;i<n;i++)T[i].parent=NIL;
	
	for(int i=0;i<n;i++){
		cin>>v>>l>>r;
		T[v].left=l;T[v].right=r;
		if(T[v].left!=NIL)T[l].parent=v;
		if(T[v].right!=NIL)T[r].parent=v;
	}
	
	for(int i=0;i<n;i++)if(T[i].parent==NIL)root=i;
	
	cout<<"Preorder\n";
	preParse(root);
	cout<<endl;
	cout<<"Inorder\n";
	inParse(root);
	cout<<endl;
	cout<<"Postorder\n";
	postParse(root);
	cout<<endl;
	
	return 0;
}