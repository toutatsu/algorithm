int gcd(int x,int y){return y?gcd(y,x%y):x;} //Greatest Common Divisor
int lcm(int x,int y){return x*y/gcd(x,y);}   //Least Common Multiple
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


//以下https://qiita.com/drken/items/b97ff231e43bce50199aより
//cpawCTF Q26.[PPC]Remainder theorem verified


//拡張ユークリッドの互除法
long long extgcd(long long a,long long b,long long &x,long long &y){
	if(b==0){x=1,y=0;return a;}
	long long gcd_ab=extgcd(b,a%b,y,x);
	y-=a/b*x;
	return gcd_ab;
}

// 負の数にも対応した mod
// 例えば -17 を 5 で割った余りは本当は 3 (-17 ≡ 3 (mod. 5))
// しかし単に -17 % 5 では -2 になってしまう
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 中国剰余定理　Chinese Remainder Theorem
// リターン値を (r, m) とすると解は x ≡ r (mod. m)
// 解なしの場合は (0, -1) をリターン
pair<long long, long long> crt(long long b1, long long m1, long long b2, long long m2) {
  long long p, q;
  long long d = extgcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return make_pair(0, -1);
  long long m = m1 * (m2/d); // lcm of (m1, m2)
  long long tmp = (b2 - b1) / d * p % (m2/d);
  long long r = mod(b1 + m1 * tmp, m);
  return make_pair(r, m);
}

int main(){
    cout<<crt(32134,1584891,193127,3438478).first<<" "<<crt(32134,1584891,193127,3438478).second<<endl;
    return 0;
}
