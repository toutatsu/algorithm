//Bellman-Ford algorithm
//Worst-case performance        O(|V||E|)
//Average performance           
//Best-case performance         O(|E|)
//Worst-case space complexity   O(|V|)

//蟻本89p参考  not_verified!!!!!!

struct edge{int ,from,to,cost;};
int INF=0x7fffffff;

vector<int> bellman-ford(int start){
    vector dist(v,INF);
    edge edges[e];
    dist[0]=0;
    for(int i=0;i<v;i++){
        for(int j=0;j<e;j++){
            if(d[edges[j].to]>d[edges[j].from]+edges[j].cost){
                d[edges[j].to]=d[edges[j].from]+edges[j].cost
                if(i==v-1)return vector<int>v(v,-1);
            }
        }
    }
    return dist;
}
