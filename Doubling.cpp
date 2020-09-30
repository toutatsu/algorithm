//ABC167 D
//https://atcoder.jp/contests/abc167/submissions/16490253

//ABC179 E
//https://atcoder.jp/contests/abc179/submissions/17106213

#include<iostream>
using namespace std;
class Doubling{
    public:
    int state_num,max_k;
    long long** table;
    long long** sum; 

    Doubling(int64_t mx,int sz):max_k(64-__builtin_clzll(mx)),state_num(sz){
        table=new long long*[max_k];
        sum  =new long long*[max_k];
        for(int i=0;i<max_k;i++){
            table[i]=new long long[state_num];
              sum[i]=new long long[state_num];
        }
        for(int i=0;i<state_num;i++)sum[0][i]=i;
        for(int i=0;i<state_num;i++)table[0][i]=-1LL;
    }

    ~Doubling(){
        for(int i=0;i<max_k;i++){delete[] table[i];delete[] sum[i];}
        delete[] table;
        delete[] sum;
    }

    void set_next(int state,int next){table[0][state]=next;}
    void build(){
        for(int k=0;k+1<max_k;k++){
            for(int i=0;i<state_num;i++){
                table[k+1][i]=(table[k][i]!=-1?table[k][table[k][i]]:-1);
                sum[k+1][i]=(sum[k][i]!=-1?sum[k][i]+sum[k][table[k][i]]:-1);
            };
        }
    }
    long long query(int state, int64_t step){
        long long acc=0LL;
        for(int i=0;i<max_k;i++){
            if((step>>i)&1){
                acc+=sum[i][state];
                state=table[i][state];
            }
        }
        //return state;
        return acc;
    }
};
long long N,X,M;
int main(){
    cin>>N>>X>>M;
    Doubling d(N,M);
    for(long long i=0LL;i<M;i++)d.set_next(i,(i*i)%M);
    d.build();
    cout<<d.query(X,N)<<endl;
    return 0;
}
