#include<iostream>
using namespace std;


int gcd(int x,int y){return y?gcd(y,x%y):x;}//Greatest Common Divisor再帰関数ver
int lcm(int x,int y){return x*y/gcd(x,y);}//Least Common Multiple最小公倍数
//数が大きい時はx/gcd(x,y)*yにしてあふれるのを防ぐ

int gcd(int x,int y){//ループ
	int r;
	if(x<y)swap(x,y);
	while(y>0){r=x%y;x=y;y=r;}
	return x;
}

int array_gcd(int a[],int size){//複数の数の最大公約数
	int x=a[0];
	for(int i=1;i<size;i++)x=gcd(x,a[i]);
	return x;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	return 0;
}


#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    return 0;
}