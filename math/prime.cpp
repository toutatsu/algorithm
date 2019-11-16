//素数テーブル
//↓後で素数テーブルをbool[]に変えて動作確認したい
int IsPrime(int n){
	vector<int>IsPrime(n+1,1);//1で初期化
	IsPrime[0]=0;IsPrime[1]=0;//0と1は非素数
	for(int i=2;i*i<=n;i++)if(IsPrime[i])for(int j=i*2;j<=n;j+=i)IsPrime[j]=0;
	//for(auto&i:IsPrime)cout<<i;//素数テーブル
	//putchar('\n');
	//for(int i=0;i<n;i++)if(IsPrime[i])cout<<i<<endl;
	return IsPrime[n];
}

//逆に合成数を見つけるパターン 誰かの pdは0で初期化
for(int i=2;i<=n;i++)for(int j=i+i;j<=n;j+=i) pd[j]=1;

//素数判定 ※動作未確認
int IsPrime(int n){
	for(int i=2;i*i<=n;i+=2)if(!n%i)return false;
	return true;
}
