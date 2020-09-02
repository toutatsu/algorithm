//AtCoder Beginner Contest 174 F
//https://atcoder.jp/contests/abc174/submissions/16468562


//O((add,delの計算量)(N+Q)√N+QlogQ)
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Mo{
    public:
    int N,Q,ans=0;
    struct query{int l,r;};
    vector<int>data,order;
    vector<query>q;
    
    //クエリに合わせて実装//
    vector<int>cnt;
    void add(int idx){ans+=(++cnt[data[idx]]==1);}
    void del(int idx){ans-=(--cnt[data[idx]]==0);}
    //クエリに合わせて実装//

    Mo(int N,int Q):N(N),Q(Q),data(N+1),order(Q),q(Q),cnt(N+1,0){}

    void input_data(){for(int i=0;i<N;i++)scanf("%d",&data[i]);}

    /*[l, r) 0-idx*/
    void input_query(){for(int i=0;i<Q;i++){scanf("%d%d",&q[i].l,&q[i].r);q[i].l--;}}

    vector<int>solve(){
        //iota(begin(order), end(order), 0);
        for(int i=0;i<Q;i++)order[i]=i;

        //sort query
        sort(order.begin(),order.end(),
        [&](const int a,const int b){
            return ((q[a].l/(int)sqrt(N))!=(q[b].l/(int)sqrt(N))?q[a].l<q[b].l:q[a].r<q[b].r);
        });

        vector<int>answer(Q);//answer for query
        int L,R,i;
        for(L=R=i=0;i<Q;i++){
            //add
            while(L>q[order[i]].l)add(--L);
            while(R<q[order[i]].r)add(R++);
            //del
            while(L<q[order[i]].l)del(L++);
            while(R>q[order[i]].r)del(--R);
            answer[order[i]] = ans;
        }
        return answer;
    }
};

int N,Q,l,r;
int main(){
    scanf("%d%d",&N,&Q);
    Mo mo(N,Q);
    mo.input_data();
    mo.input_query();
    auto ans=mo.solve();
    for(int i=0;i<Q;i++)printf("%d\n",ans[i]);
    return 0;
}
