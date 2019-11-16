#define MOD 1000000007

//繰り返し自乗法
long long power(long long a,long long x){
    return x?x%2?power(a,x-1)*a%MOD:(long long)powl(power(a,x/2),2)%MOD:1;
}

//2進数を利用
long long power(long long a,long long x){
    long long ret=1;
    while(x){
        if(x&1)ret=ret*a%MOD;
        a=a*a%MOD;
        x>>=1;
    }
    return ret;
}
