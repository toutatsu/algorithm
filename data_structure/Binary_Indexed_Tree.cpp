//Binary Indexed Tree
//蟻本p161
//AOJ DSL_2_B Range Sum Query (RSQ) verified
//AtCoder Library Practice Contest B
#include<iostream>
#include<vector>
using namespace std;

template<typename T>class fenwick_tree{

    int size;
    vector<T>bit;//[1,size]

    T sum(int i){T s;for(s=0;i>0;i-=i&-i)s+=bit[i];return s;}//i番目(1-index)までの和を返す
    
    public:
    fenwick_tree(int size):bit(size+1,0LL),size(size){}
    T sum(int l,int r){return sum(r-1)-sum(l-1);}//1-idxで[l,r)の和を返す
    void add(int i,T x){for(;i<=size;i+=i&-i)bit[i]+=x;}//i番目にxを足す
};

int N,Q;
long long t,a,b;
int main(){
    cin>>N>>Q;
    fenwick_tree<long long>bit(N);
    for(int i=1;i<=N;i++){
        cin>>a;
        bit.add(i,a);
    }
    for(int i=0;i<Q;i++){
        cin>>t>>a>>b;
        if(t==1LL)cout<<bit.sum(a+1,b+1)<<endl;
        else bit.add(a+1,b);
    }
    return 0;
}
