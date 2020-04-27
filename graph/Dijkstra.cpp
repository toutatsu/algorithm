//Dijkstra's algorithm
//Worst-case performance        O(|E|+|V|log|V|) フィボナッチヒープ使用時
//Average performance           
//Best-case performance         
//Worst-case space complexity


//AOJ GRL_1_A: Single Source Shortest Path Verified
template<typename T>
vector<T>dijkstra(Graph<T>graph,int start){
    //#include<queue>
    vector<T>dist(graph.Vertex_num,graph.INF);
    dist[start]=0;
    pair<T,int>c;
    //costで昇順のqueue　costが小さいものから見ていく
    priority_queue< pair<T,int>, vector<pair<T,int>>, std::greater<pair<T,int>> >q;
    q.push(make_pair(0,start));
    while(!q.empty()){
        c=q.top(),q.pop();
        if(dist[c.second]<c.first)continue;//更新済みの頂点
        for(int i=0;i<graph.g[c.second].size();i++){
            typename Graph<T>::edge x=graph.g[c.second][i];
            T new_cost=c.first+x.cost;//現在地までのコスト+頂点x.toへの辺のコスト
            if(new_cost<dist[x.to]){
                //prev[x.to]=c.second;//帰り道
                q.push(make_pair(dist[x.to]=new_cost,x.to));
            }
        }
    }
    return dist;
}

int V,E,r;
int main(){
    cin>>V>>E>>r;
    Graph<long long>g(V,E);
    g.input(true,true);
    auto v=dijkstra(g,r);
    for(auto x:v){
        if(x==g.INF)cout<<"INF"<<endl;
        else cout<<x<<endl;
    }
    return 0;
}











//蟻本97p参考 

//not verified

struct edge{int ,from,to,cost;};
int INF=0x7fffffff;


int dist[v]=INF;

priority_queue<int,int>q;//cost,頂点番号
while(!q.empty()){
    c=q.top();q.pop();

    //隣接リストに対して
    for(int i=0;i<g[c].size();i++){
        if(dist[g[c][i]>d[g[c]]+co){
            dist[g[c]]



            q.push_back();
        }

    }


}

//ABC035より
while(!Q.empty()){
    pair<long,long>position=Q.top();Q.pop();
    for(auto x:G[position.second]){
        long new_cost=position.first+x.second;
        if(new_cost<d[x.first]){
            d[x.first]=new_cost;
            prev[x.first]=position.second;
            Q.push(make_pair(d[x.first],x.first));
        }
    }
}

                
//アルゴリズム論より
//O(|V|^2)
//not verified
#define N 10 /* ノード数 */
#define INF 10000 /* 十分大きな数 */
#define FALSE 0
#define TRUE 1

void dijkstra(int s, int A[][N])
{
  int i, j, c, fixed[N], d[N];
  for (i = 0; i < N; i++) {
    fixed[i] = FALSE; d[i] = INF;
  }
  c = s; d[c] = 0;
    
      for (i = N - 1; 0 <= i; i--) {
    fixed[c] = TRUE;
    for (j = 0; j < N; j++)
      if ((A[c][j] != INF) 
        && (d[c] + A[c][j] < d[j]))
        d[j] = d[c] + A[c][j];
    l = INF;
    for (j = 0; j < N; j++)
      if ((fixed[j]==FALSE) && (d[j]<l)) {
        l = d[j]; c = j;
      }
  }
}
