//Binary Indexed Tree
//蟻本p161
//AOJ DSL_2_B Range Sum Query (RSQ) verified
template<typename T>
class fenwick_tree{
    public:
    int size;
    vector<T>bit;//[1,size]
    
    fenwick_tree(int size):bit(vector<T>(size+1,0)),size(size){}//constructor
    
    T sum(int i){T s;for(s=0;i>0;i-=i&-i)s+=bit[i];return s;}//i番目(1-index)までの和を返す
    void add(int i,T x){for(;i<=size;i+=i&-i)bit[i]+=x;}//i番目にxを足す
};


//AOJ DSL_2_B Range Sum Query (RSQ)
int main(){
    int n,q,com,x,y;
    cin>>n>>q;
    fenwick_tree<int>bit(n);
    for(int i=0;i<q;i++){
        cin>>com>>x>>y;
        if(com)cout<<bit.sum(y)-bit.sum(x-1)<<endl;
        else bit.add(x,y);
    }
    return 0;
}
