//あとでtemplateに書きなおせ
//AOJ Weighted Union Find Trees verified

#include<iostream>
#include<vector>
using namespace std;

class weighted_union_find{

  public:

    vector<int>rank,parent,sz,diff_weight;
    //木xの高さはrank[x]以下，parentは親ノードの番号，sz[頂点]はその集合の要素の数, diffは親ノードとの値の差を表す

    disjointset(int size){
        rank=parent=sz=diff_weight=vector<int>(size+1);
        for(int i=0;i<=size;i++)rank[i]=diff_weight[i]=0,parent[i]=i,sz[i]=1;
    }
    
    int root(int n){//経路圧縮と同時に値を累積和
        if(parent[n]==n)return n;
        int r=root(parent[n]);//親まで経路圧縮&累積和
        diff_weight[n]+=diff_weight[parent[n]];//累積和
        return parent[n]=r;//経路圧縮
    }
    
    int weight(int n){root(n);return diff_weight[n];}

    bool unite(int x,int y,int w){
        //weight(y)-weight(x)=wにして繋げる
        w+=weight(x);w-=weight(y);//重み修正???????????????????????????????????????????
        x=root(x);y=root(y);
        if(x==y)return false;//すでにつながっているため終了
      
      //↑の二行  if(same(x,y))return false;でも行けるか後で試せ
      
        (rank[x]>rank[y])?parent[y]=x,sz[x]+=sz[y]:parent[x]=y,sz[y]+=sz[x];//低い木が高い木に属する
        rank[root(x)]+=(rank[x]==rank[y]);//同じ高さの場合　頂点の高さを1足す
        (rank[x]>rank[y])?diff_weight[y]=w:diff_weight[x]=-w;
        return true;
    }
    
    bool same(int x,int y){return root(x)==root(y);}
    
    int diff(int x,int y){return weight(y)-weight(x);}

    int size(int n){return sz[root(n)];}
};

int main(){
    int n,q,com,x,y,z;
    cin>>n>>q;
    weighted_union_find ds(n);
    for(int i=0;i<q;i++){
        cin>>com>>x>>y;
        if(com)if(ds.same(x,y))cout<<ds.diff(x,y)<<endl;else cout<<"?"<<endl;
        else {cin>>z;ds.unite(x,y,z);}
    }
    return 0;
}
