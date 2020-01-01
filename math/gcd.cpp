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

//https://qiita.com/drken/items/b97ff231e43bce50199a
//verifyしろ
template<typename T>
extgcd(T a,T b,T &x,T &y){
	if(b==0)x=1,y=0,return a;
	T gcd_ab=extgcd(b,a%b,y,x);
	y-=a/b*x;
	return gcd_ab;
}
