/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int top,S[1000];//????

void push(int x){S[++top]=x;}

int pop(){top--;return S[top+1];}

int main(){
	int a,b,top=0;
	char s[100];//???
	
	while(scanf("%s",s)!=EOF){
		if(s[0]=='+'){
			a=pop();
			b=pop();
			push(a+b);
		}else if(s[0]=='-'){
			a=pop();
			b=pop();
			push(b-a);
		}else if(s[0]=='*'){
			a=pop();
			b=pop();
			push(a*b);
		}else{
			push(atoi(s));
		}
	}
	printf("%d\n",pop());
	return 0;
}
*/


#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;

int main(){
	stack<int>S;
	int a,b,x;
	string s;
	
	while(cin>>s){
		if(s[0]=='+'){
			a=S.top();S.pop();
			b=S.top();S.pop();
			S.push(a+b);
		}else if(s[0]=='-'){
			b=S.top();S.pop();
			a=S.top();S.pop();
			S.push(a-b);
		}else if(s[0]=='*'){
			a=S.top();S.pop();
			b=S.top();S.pop();
			S.push(a*b);
		}else{
			S.push(atoi(s.c_str()));
		}
	}
	cout<<S.top()<<endl;
	return 0;
}