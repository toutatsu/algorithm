//Dijkstra's algorithm
//Worst-case performance        O(|E|+|V|log|V|) フィボナッチヒープ使用時
//Average performance           
//Best-case performance         
//Worst-case space complexity

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
