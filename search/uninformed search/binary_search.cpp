//ABC144 verified

//めぐる式二分探索
long long ng=-1LL,ok=1000000000000LL,mid;//ng:解が存在しない値　ok:解が存在する値

    while(abs(ok-ng)>1LL){
        mid=(ok+ng)/2LL;
        if(solve(?))ok=mid;
        else ng=mid;
    }
//AtCoder Petrozavodsk Contest 001 C
//https://atcoder.jp/contests/apc001/submissions/16421241

//ABC146 AGC011B
while(abs(ok-ng)>1LL)(solve(mid=(ok+ng)/2LL))?ok=mid:ng=mid;
