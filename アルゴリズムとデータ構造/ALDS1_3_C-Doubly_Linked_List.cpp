/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

struct Node{
	int key;
	Node *prev, *next;
};
Node *nil;

Node *listSearch(int key){
	Node *cur=nil->next;
	while(cur!=nil&&cur->key!=key)cur=cur->next;
	return cur;
}

void init(){
	nil=(Node*)malloc(sizeof(Node));
	nil->next=nil->prev=nil;
}

void printList(){
	Node *cur=nil->next;
	int isf=0;
	while(1){
		if(cur==nil)break;
		if(isf++>0)cout<<" ";
		cout<<cur->key;
		cur=cur->next;
	}
	cout<<"\n";
}
void deleteNode(Node *t){
	if(t==nil)return;
	t->prev->next=t->next;
	t->next->prev=t->prev;
	free(t);
}

void deleteFirst(){
	deleteNode(nil->next);
}


void deleteLast(){
	deleteNode(nil->prev);
}


void deleteKey(int key){
	deleteNode(listSearch(key));
}

void insert(int key){
	Node *x=(Node *)malloc(sizeof(Node));
	x->key=key;
	x->next=nil->next;
	nil->next->prev=x;
	nil->next=x;
	x->prev=nil;
}

int main(){
	int key,n,size=0;
	char com[20];
	int np=0,nd=0;
	cin>>n;
	init();
	for(int i=0;i<n;i++){
		scanf("%s%d",com,&key);
		if(com[0]=='i'){insert(key);np++;size++;}
		else if(com[0]=='d'){
			if(strlen(com)>6){
				if(com[6]=='F')deleteFirst();
				else if(com[6]=='L')deleteLast();
			}else{
				deleteKey(key);
				nd++;
			}
			size--;
		}
	}
	printList();
	return 0;
}
*/

#include<cstdio>
#include<list>
#include<algorithm>
using namespace std;

int main(){
	int q,x;
	char com[20];
	list<int>v;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%s",com);
		if(com[0]=='i'){
			scanf("%d",&x);
			v.push_front(x);
		}else if(com[6]=='L'){
			v.pop_back();
		}else if(com[6]=='F'){
			v.pop_front();
		}else if(com[0]=='d'){
			scanf("%d",&x);
			for(list<int>::iterator it=v.begin(); it!=v.end();it++){
				if(*it==x){
					v.erase(it);
					break;
				}
			}
		}
	}
	int i=0;
	for(list<int>::iterator it=v.begin();it!=v.end();it++){
		if(i++)printf(" ");
		printf("%d",*it);
	}
	printf("\n");
	return 0;
}