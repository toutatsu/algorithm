//AC Library 参考
//AOJ Disjoint Set: Union Find Tree
//あとでABC126 と size()のverify
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

class disjointset{
    protected:
    int sz;
    vector<int>parent_or_size;//親ノードの番号 or -(集合の大きさ)

    public:
    disjointset():sz(0){}
    disjointset(int n):sz(n),parent_or_size(n,-1){}

    //経路圧縮 parent配列の更新
    int root(int n){
        assert(0<=n&&n<sz);
        return (parent_or_size[n]<0?n:parent_or_size[n]=root(parent_or_size[n]));
    }

    int unite(int x,int y){//x,yの代表を返す
        assert(0<=x&&x<sz && 0<=y&&y<sz);
        if((x=root(x))==(y=root(y)))return x;
        if(size(x)<size(y))std::swap(x, y);
        parent_or_size[x]+=parent_or_size[y]; //集合の大きさ更新
        parent_or_size[y]=x;                  //小さい木が大きい木に属する
        return x;
    }

    bool same(int x,int y){assert(0<=x&&x<sz && 0<=y&&y<sz);return root(x)==root(y);}

    int size(int n){assert(0<=n&&n<sz);return -parent_or_size[root(n)];}

    void groups(){
        //AC Libary 後で実装
    }
};

//////////////////////////////////////////////////////////////////////////////////////////

//AOJ Weighted Union Find Trees
class weighted_union_find:public disjointset{

    vector<int>diff_weight;//親ノードとの値の差

    public:
    weighted_union_find(int n):disjointset::disjointset(n),diff_weight(n,0){};

    //経路圧縮 parent配列の更新 と同時に値を累積和
    int root(int n){
        assert(0<=n&&n<sz);
        if(parent_or_size[n]<0)return n;
        int r=(root(parent_or_size[n]));//親まで経路圧縮&累積和
        diff_weight[n]+=diff_weight[parent_or_size[n]];//累積和
        return parent_or_size[n]=r;//経路圧縮
    }
    
    int weight(int n){root(n);return diff_weight[n];}

    bool unite(int x,int y,int w){
        assert(0<=x&&x<sz && 0<=y&&y<sz);
        w+=weight(x)-weight(y);
        if((x=root(x))==(y=root(y)))return false;
        if(size(x)<=size(y)){std::swap(x, y);w*=-1;}
        parent_or_size[x]+=parent_or_size[y]; //集合の大きさ更新
        parent_or_size[y]=x;                  //小さい木が大きい木に属する
        diff_weight[y]=w;
        return true;
    }
    bool same(int x,int y){assert(0<=x&&x<sz && 0<=y&&y<sz);return root(x)==root(y);}
    int diff(int x,int y){return weight(y)-weight(x);}
};

#include<string>
int main(){
    int n,q,com,x,y,z;
    cin>>n>>q;
    weighted_union_find ds(n);
    for(int i=0;i<q;i++){
        cin>>com>>x>>y;
        if(com){if(ds.same(x,y))cout<<ds.diff(x,y)<<endl;else cout<<"?"<<endl;}
        else {cin>>z;ds.unite(x,y,z);}
    }
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////


//アルゴリズムとデータ構造 rankを用いた実装
//AOJ Disjoint Set: Union Find Tree, ABC126 E verified 
#include<iostream>
#include<vector>
using namespace std;

class disjointset{

  public:

    vector<int>rank,parent,sz;//木xの高さはrank[x]以下，parentは親ノードの番号，sz[頂点]はその集合の要素の数を指す

    disjointset(int size){//0,1,2,...size　　←注意
        rank=parent=sz=vector<int>(size+1);
        for(int i=0;i<=size;i++)rank[i]=0,parent[i]=i,sz[i]=1;
    }
　  //注意 parent配列はrootを呼ばないと更新されない
    int root(int n){return (parent[n]==n?n:parent[n]=root(parent[n]));}//経路圧縮

    void unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y)return;
        (rank[x]>rank[y])?parent[y]=x,sz[x]+=sz[y]:parent[x]=y,sz[y]+=sz[x];//低い木が高い木に属する
        rank[root(x)]+=(rank[x]==rank[y]);//同じ高さの場合　頂点の高さを1足す
    }

    bool same(int x,int y){return root(x)==root(y);}

    int size(int n){return sz[root(n)];}
};



//ABC??
int main(){
    int n,m;
    cin>>n>>m;
    disjointset ds(n);
    vector<int>a(m),b(m);
    vector<long long>ans(m);
    for(int i=0;i<m;i++)cin>>a[i]>>b[i];
    ans[0]=(long long)n*(n-1)/2;
    for(int i=m-1;i>0;i--){
        cout<<i<<(ds.same(a[i],b[i])?"same":"not same")<<endl;
        if(ds.same(a[i],b[i]))ans[m-i]=ans[m-i-1];
        else ans[m-i]=ans[m-i-1]-(long long)ds.size(a[i])*ds.size(b[i]);
        ds.unite(a[i],b[i]);
        for(auto x:ans)cout<<x;
        cout<<endl;
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<endl;
    return 0;
}
