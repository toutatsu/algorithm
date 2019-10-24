#include<iostream>
#include<vector>
//#include<numeric>//for iota
#include<algorithm>
using namespace std;

class disjointset{

  public:

    vector<int>rank,parent,sz;//木xの高さはrank[x]以下，parentは親ノードの番号，sz[頂点]はその集合の要素の数を指す

    disjointset(){}//なにこれ
	disjointset(int size){//0,1,2,...size
        //parent=vector<int>(size+1);
        //rank=vector<int>(size+1,0);
        //sz=vector<int>(size+1,1);
        //iota(parent.begin(),parent.end(),0);
        rank=parent=sz=vector<int>(size+1);
        for(int i=0;i<=size;i++)rank[i]=0,parent[i]=i,sz[i]=1;

        /*
        vector<int>parent(size+1),rank(size+1,0),sz(rank+1,1);
        iota(parent.begin(),parent.end(),0);
        */  //未確認
	}

    int root(int n){return (parent[n]==n?n:parent[n]=root(parent[n]));}//経路圧縮

    void unite(int x,int y){
        x=root(x);y=root(y);
        if(x!=y){
            if(rank[x]>rank[y])parent[y]=x,sz[x]+=sz[y];//低い木が高い木に属する
            else parent[x]=y,sz[y]+=sz[x];
            if(rank[x]==rank[y])rank[root(x)]++;//同じ高さの場合　頂点の高さを1足す
        }
    }

    bool same(int x,int y){return root(x)==root(y);}

    int size(int n){return sz[root(n)];}
};
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