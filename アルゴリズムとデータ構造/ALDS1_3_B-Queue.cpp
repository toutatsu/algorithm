/*
#include<iostream>
#include<algorithm>
#include<string>
#define LEN 100000

using namespace std;

typedef struct pp{
	char name[100];
	int t;
}P;

P Q[LEN];
int head,tail,n;

void enqueue(P x){
	Q[tail]=x;
	tail=(tail+1)%LEN;
}

P dequeue(){
	P x=Q[head];
	head=(head+1)%LEN;
	return x;
}

int main(){
	int elaps=0,c,q;
	P u;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>Q[i].name>>Q[i].t;
	head=1;tail=n+1;
	
	while(head!=tail){
		u=dequeue();
		c=min(q,u.t);
		u.t-=c;
		elaps+=c;
		if(u.t>0)enqueue(u);
		else cout<<u.name<<" "<<elaps<<endl;
	}
	return 0;
}
*/
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	int n,q,t;
	string name;
	queue<pair<string,int>>Q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>name>>t;
		Q.push(make_pair(name,t));
	}
	
	pair<string,int>u;
	int elaps=0,a;
	
	while(!Q.empty()){
		u=Q.front();Q.pop();
		a=min(u.second,q);
		u.second-=a;
		elaps+=a;
		if(u.second>0){
			Q.push(u);
		}else{
			cout<<u.first<<" "<<elaps<<endl;
		}
	}
	return 0;
}