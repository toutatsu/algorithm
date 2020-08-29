//素数テーブル
int IsPrime(int n){
	vector<int>IsPrime(n+1,1);//1で初期化
	IsPrime[0]=0;IsPrime[1]=0;//0と1は非素数
	for(int i=2;i*i<=n;i++)if(IsPrime[i])for(int j=i*2;j<=n;j+=i)IsPrime[j]=0;
	//for(auto&i:IsPrime)cout<<i;//素数テーブル
	//putchar('\n');
	//for(int i=0;i<n;i++)if(IsPrime[i])cout<<i<<endl;
	return IsPrime[n];
}
//bool version ABC 096 D verfied?
    bool isprime[n];
    for(auto &x:isprime)x=true;
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=n;i++)if(isprime[i])for(int j=i+i;j<=n;j+=i)isprime[j]=false;


//逆に合成数を見つけるパターン 誰かの pdは0で初期化
for(int i=2;i<=n;i++)for(int j=i+i;j<=n;j+=i) pd[j]=1;

//素数判定 ABC149 C verified
bool isPrime(int x){
	if(x<2)return false;
	else if(x==2)return true;
	else if(x%2==0)return false;
	for(int i=3;i*i<=x;i+=2)if(x%i==0)return false;
	return true;
}


//※動作未確認
int IsPrime(int n){
	if 0 or 1 return false;
	for(int i=2;i*i<=n;i+=2)if(!n%i)return false;
	return true;
}


//素因数分解 ARC 026 Verified
#include<map>
map<long long,int>prime_factor(long long n){
	map<long long,int>factor;
    for(long long i=2LL;i*i<=n;i++)while(n%i==0LL){factor[i]++;n/=i;}
    if(n!=1LL)factor[n]=1;
    return factor;
}


//ABC177 E
#include<bits/stdc++.h>
using namespace std;

vector<int>prime(int N){
    vector<int>factor(N+1);//factor[i]:iの最小の素因数 iが素数の場合は0
    factor[0]=-1,factor[1]=-1;
    for(int i=2;i*i<=N;i++){
        if(factor[i]!=0)continue;
        for(int j=i*2;j<=N;j+=i)if(factor[j]==0)factor[j]=i;
    }
    return factor;//最小素因数を持った配列
}
vector<int>S(1000000001);

map<int,int>osa_k(int N){//高速な素因数分解　O(logN)?
    //vector<int>factor=prime(N);
    //S : 最小素因数を持った配列
    map<int,int>prime_factor;
    if(N==0||N==1)return prime_factor;
    for(;S[N]!=0;N/=S[N])prime_factor[S[N]]++;
    prime_factor[N]++;
    return prime_factor;
}

