//Bipartite_Matching

//最大流量を利用 蟻本p196参照
//GRL_7_A: Bipartite Matching verified
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
    int v,e,x,y,from,to,cap;
    cin>>x>>y>>e;
    
    //from-to 容量1の辺を追加
    for(int i=0;i<e;i++){
        cin>>from>>to;
        to+=x;
        g[from].push_back(edge{to,1,int(g[to].size())});
        g[to].push_back(edge{from,0,int(g[from].size()-1)});
    }
    //sourceからx,yからsinkへ容量1の辺を繋ぐ
    int s=x+y,t=x+y+1;
    from=s;
    for(int i=0;i<x;i++){
        to=i;
        g[from].push_back(edge{to,1,int(g[to].size())});
        g[to].push_back(edge{from,0,int(g[from].size()-1)});
    }
    to=t;
    for(int i=0;i<y;i++){
        from=i+x;
        g[from].push_back(edge{to,1,int(g[to].size())});
        g[to].push_back(edge{from,0,int(g[from].size()-1)});
    }
    //sourceからsinkへの最大流量flowを求める
    int flow,f;
    for(flow=0;(f=dfs(s,t,INF))!=0;flow+=f)for(auto& x:visited)x=false;
    cout<<flow<<endl;
    return 0;
}
