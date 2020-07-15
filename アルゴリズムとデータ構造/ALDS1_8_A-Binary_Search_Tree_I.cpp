#include<iostream>//–¢’ño
#include<string>
using namespace std;

struct Node{
	int key;
	Node *parent,*right,*left;
}
Node *root,*NIL;

void insert(int k){
	Node *y==NIL;
	Node *x=root;
	Node *z;






void inorder(Node *u){
	if(u==NIL)return;
	inorder(u->left);
	cout<<" "<<u->key;
	inorder(u->right);
}

void preorder(Node *u){
	if(u==NIL)return;
	cout<<" "<<u->key;
	preorder(u->left);
	preorder(u->right);
}

int main(){
	int n,x;
	string com;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>com;
		if(com=="insert"){
			cin>>x;
			insert(x);
		}else if(com=="print"){
			inorder(root);cout<<endl;
			preorder(root);cout<<endl;
		}
	}
	return 0;
}