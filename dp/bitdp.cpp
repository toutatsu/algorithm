//https://atcoder.jp/contests/abc180/submissions/17485786
//https://atcoder.jp/contests/abc180/submissions/17448270 参考

#include<iostream>
#include<vector>
using namespace std;

long long N;

typedef struct{
    int x,y,z;
}city;

vector<city>c(17);

class bitdp{
    public:
    //0-idx
    int n;
    vector<vector<int>>dp;

    bitdp(int n):n(n),dp(1<<n,vector<int>(n,100000000)){};

    int d(city a,city b){//a->b
        return abs(b.x-a.x)+abs(b.y-a.y)+max(0,b.z-a.z);
    }

    void build(){
        for(int i=0;i<n;i++)if(i)dp[1<<i][i]=d(c[0],c[i]);/*distance*/
        for(int i=0;i<(1<<n);i++){//訪問状態
            for(int j=0;j<n;j++){//現在地
                if(~i>>j&1)continue;
                for(int k=0;k<n;k++){//遷移先
                    if(i>>k&1)continue;
                    dp[i|1<<k][k]=min(dp[i|1<<k][k],dp[i][j]+d(c[j],c[k]));
                }
            }
        }
    }

    void print(){
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" \n"[j==n-1];
            }
        }
    }
    //cout<<dp[(1<<n)-1][0]<<endl;
};

int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>c[i].x>>c[i].y>>c[i].z;
    bitdp dp(N);
    dp.build();
    cout<<dp.dp[(1<<N)-1][0]<<endl;
    return 0;
}
