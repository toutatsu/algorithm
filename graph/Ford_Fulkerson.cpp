//Ford_Fulkerson
//Maximum Flow
//各辺の容量は整数値，（有理数）が条件　無理数の場合終了しない可能性
//最悪計算量　O((最大流量)*|E|)

//AOJ GRL_6_A: Maximum Flow verified
//蟻本p190参照
#include<iostream>
#include<vector>
using namespace std;

typedef struct{int to,cap,rev;}edge;
vector<edge>g[v];//グラフの隣接リスト
bool visited[v];//dfsで使用

int dfs(int v,int sink,int f){//増加パスを探す
    if(v==sink)return f;
    visited[v]=true;
    for(int i=0;i<g[v].size();i++){
        edge &e=g[v][i];
        if(!visited[e.to]&&e.cap>0){
            int d=dfs(e.to,sink,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int main(){
    int v,e,from,to,cap;
    cin>>v>>e;
    
    //from-to 容量capの辺を追加
    for(int i=0;i<e;i++){
        cin>>from>>to>>cap;
        g[from].push_back(edge{to,cap,int(g[to].size())});
        g[to].push_back(edge{from,0,int(g[from].size()-1)});
    }
    //sourceからsinkへの最大流量flowを求める
    int flow,f;
    for(flow=0;(f=dfs(source,sink,INF))!=0;flow+=f)for(auto& x:visited)x=false;
    cout<<flow<<endl;
  
    return 0;
}
