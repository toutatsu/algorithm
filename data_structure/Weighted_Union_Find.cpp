//テストしろ
//あとでtemplateに書きなおせ
//AOJ
#include<iostream>
#include<vector>
using namespace std;

class disjointset{

  public:

    vector<int>rank,parent,sz,diff_weight;
    //木xの高さはrank[x]以下，parentは親ノードの番号，sz[頂点]はその集合の要素の数, diffは親ノードとの値の差を表す

    disjointset(int size){//0,1,2,...size
        rank=parent=sz=diff_weight=vector<int>(size+1);
        for(int i=0;i<=size;i++)rank[i]=diff_weight[i]=0,parent[i]=i,sz[i]=1;
    }
    
    int root(int n){//経路圧縮と同時に値を累積和
        if(parent[n]==n)return n;
        int r=root(parent[n]);//親まで経路圧縮&累積和
        diff[n]+=diff_weight[parent[n]];//累積和
        return parent[n]=r;//経路圧縮
    }
    
    int weight(int n){root(n);return diff_weight[n];}

    void unite(int x,int y,int z){
        //weight(y)-weight(x)=w
        w+=weight(x);w-=weight(y);//重み修正
        x=root(x);y=root(y);
        if(x==y)return;//すでにつながっているため終了
        (rank[x]>rank[y])?parent[y]=x,sz[x]+=sz[y]:parent[x]=y,sz[y]+=sz[x];//低い木が高い木に属する
        rank[root(x)]+=(rank[x]==rank[y]);//同じ高さの場合　頂点の高さを1足す
        (rank[x]>rank[y])?diff_weight[y]=w:diff_weight[x]=-w;
        return;
    }
    
    bool same(int x,int y){return root(x)==root(y);}
    
    int diff(int x,int y){return weight(y)-diff_weight(x);

    int size(int n){return sz[root(n)];}
};
