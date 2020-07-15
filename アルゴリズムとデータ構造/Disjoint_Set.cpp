#include<iostream>
#include<vector>
using namespace std;

class Disjoint_Set{
    public:
    vector<int>rank,parent,sz;//rankは木の高さ，parentは親ノードの番号，szはその集合の要素の数を指す
    //経路圧縮したらrank変わる?

    DisjointSet(){}//なにこれ
	DisjointSet(int size){
		rank.resize(size,0);
		parent.resize(size,0);
        sz.resize(size,1);
		for(int i=0;i<size;i++)parent[i]=i,rank[i]=0,size[i]=1;//rank,szの初期化いる？
	}

    int Find_Set(int x){
        return (parent[x]==x?x:parent[x]=Find_set(parent[x]));//経路圧縮
    }

    void Unite(int x,int y){
        x=Find_Set(x);
        y=Find_Set(y);
        if(x!=y){
            if(rank[x]>rank[y])parent[y]=x,sz[x]+=sz[y];//低い木が高い木に属する
            else parent[x]=y,sz[y]+=sz[x];
            if(rank[x]=rank[y])rank[y]++;//同じ高さの場合　頂点の高さを1足す
        }
    }

    bool Same(int x,int y){
        return Find_Set(x)==Find_Set(y);
    }

    int Size_of(int x){
        return sz[Find_Set(x)];
    }
};
int main(){
    return 0;
}






}