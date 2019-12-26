#define MOD 1000000007

//--------------------------------ABC034 Cより----------------------------------------
//powlではMODが取れず溢れるため
//繰り返し自乗法

long long power(long long a,long long x){//a^x mod MOD
    return x?x%2?power(a,x-1)*a%MOD:(long long)powl(power(a,x/2),2)%MOD:1;
}


/*フェルマーの小定理
MOD p(素数)での逆元
a^(p-1) ≡ 1    mod(p)
a^(p-2) ≡ a^-1 mod(p)
*/
long long nCr(long long n,long long r){
    long long nCr=1LL,i;
    for(i=n;i>n-r;nCr%=MOD,i--)nCr*=i;              //分子
    for(i=1LL;i<=r;nCr%=MOD,i++)nCr*=power(i,MOD-2);//分母
    return nCr;
}
//--------------------------------------------------------------------------------------

//情報工学実験Ⅰ　asmより
//nCr=(n-1)C(r-1)+(n-1)Crを利用
//合ってるっぽいが再帰が多くstack over flow　になる　　ABC 094 D
int comb(int n, int r){
	int ret;
	if (n == 0) ret = 1;
	else if (r == 1) ret = n;
	else if (r == 0 || n == r) ret = 1;
	else ret = comb(n-1, r-1) + comb(n-1, r);
	return ret;
}



//以下パスカルの三角形による方法　大きな値は計算できない

//////1//////////自作
unsigned long long PascalsTriangle[n+1][n+1]={};//0オリジン

unsigned long long combination(int n,int k){

    if(PascalsTriangle[n][k])return PascalsTriangle[n][k];//すでにデータがあれば利用
    
    PascalsTriangle[0][0]=1ULL;//頂点
    for(int step=1;step<=n;step++){//step段目の計算
        for(int i=0;i<=n;i++){
            PascalsTriangle[step][i]=(i||i==n?PascalsTriangle[step-1][i-1]+PascalsTriangle[step-1][i]:PascalsTriangle[step-1][i]);
        }
    //for(int i=0;i<(n+1)*(n+1);i++)cout<<PascalsTriangle[i/(n+1)][i%(n+1)]<<(i%(n+1)==n?"\n":" ");//確認
    //cout<<endl;
    }
    return PascalsTriangle[n][k];
}


//////2//////////////

------------------ABC132 他の人(chanciiさん)のcombinationより------------------------------
int n,k,c[N][N];//<-0で初期化

	for(int i=0;i<=n+1;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}

///今回は N ≤ 2000 なので、パスカルの三角形を上から求めていく要領で

////////////////3///////////////////////////

unsigned long long combination(int n,int k){//パスカルの三角形　再起関数Ver //正しく動くか未確認
    return (k?k==n?combination(n-1,k):combination(n-1,k-1)+combination(n-1,k):1);
}
