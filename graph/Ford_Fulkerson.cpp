//Ford_Fulkerson
//Maximum Flow
//各辺の容量は整数値，（有理数）が条件　無理数の場合終了しない可能性
//最悪計算量　O((最大流量)*|E|)

//AOJ GRL_6_A: Maximum Flow verified
//蟻本p190参照
//c++14以下だと引数にautoが使えないからどうにか--------------------------↓
template<typename T>
T ford_fulkerson_dfs(int v,int sink,T f,vector<bool>&visited,vector<auto>*residual_network){//増加パスを探す
    if(v==sink)return f;
    visited[v]=true;
    for(int i=0;i<residual_network[v].size();i++){
        auto &e=residual_network[v][i];
        if(!visited[e.to]&&e.cap>0){
            T d=ford_fulkerson_dfs(e.to,sink,min(f,e.cap),visited,residual_network);//sinkまでのパスの容量の最小を返す
            if(d>0){//流せる場合残余グラフの更新
                e.cap-=d;
                residual_network[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
template<typename T>
T ford_fulkerson(Graph<T>graph,int source,int sink){
    vector<bool>visited(graph.Vertex_num,false);
    struct flow_path{int to;T cap,rev;};
    vector<flow_path>residual_network[graph.Vertex_num];
    //Graph<T>graphを残余グラフに変換
    for(int v=0;v<graph.Vertex_num;v++){
        for(int e=0;e<graph.g[v].size();e++){
            flow_path path;
            
            path.to=graph.g[v][e].to;
            path.cap=graph.g[v][e].cost;
            path.rev=residual_network[graph.g[v][e].to].size();
            residual_network[v].emplace_back(path);

            path.to=v;
            path.cap=0;
            path.rev=residual_network[v].size()-1;
            residual_network[graph.g[v][e].to].emplace_back(path);
        }
    }

    T maximum_flow=0,f;
    //流せなくなるまでdfs
    for(;(f=ford_fulkerson_dfs(source,sink,graph.INF,visited,residual_network))!=0;maximum_flow+=f){
        for(int i=0;i<graph.Vertex_num;i++)visited[i]=false;
    }
    return maximum_flow;
}

int V,E;
int main(){
    cin>>V>>E;
    Graph<long long>g(V,E);
    g.input(true,true);
    cout<<ford_fulkerson(g,0,V-1)<<endl;
    return 0;
}


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
