//ABC167 D
//https://atcoder.jp/contests/abc167/submissions/16490253

#include<iostream>
using namespace std;
class Doubling{
    public:
    int state_num,max_k;
    int** table;

    Doubling(int sz,int64_t mx):state_num(sz),max_k(64-__builtin_clzll(mx))
    {table=new int*[max_k];for(int i=0;i<max_k;i++)table[i]=new int[state_num];}

    ~Doubling(){for(int i=0;i<max_k;i++)delete[] table[i];delete[] table;}

    void set_next(int state,int next){table[0][state]=next;}
    void build(){
        for(int k=1;k<max_k;k++){
            for(int i=0;i<state_num;i++){
                table[k][i]=(table[k-1][i]!=-1?table[k-1][table[k-1][i]]:-1);
            };
        }
    }
    int query(int state, int64_t step){
        for(int i=0;i<max_k;i++)if((step>>i)&1)state=table[i][state];
        return state;
    }
};
long long N,K;
int main(){
    cin>>N>>K;
    int A[N];
    for(int i=0;i<N;i++){cin>>A[i];A[i]--;}
    Doubling d(N,K);
    for(int i=0;i<N;i++)d.set_next(i,A[i]);
    d.build();
    cout<<d.query(0,K)+1LL<<endl;
    return 0;
}
