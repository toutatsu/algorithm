//AOJ GRL_2_A: Minimum Spanning Tree Verified
//蟻本p100参照
//O(V^2)
//priority_queueを使うとO(ElogV)になるらしい
template<typename T>
T prim(Graph<T>graph){
    vector<T>mincost(graph.Vertex_num,graph.INF);
    mincost[0]=0;
    vector<bool>used(graph.Vertex_num,false);
    int res=0;
    while(true){
        int v=-1;
        for(int u=0;u<graph.Vertex_num;u++)if(!used[u]&&(v==-1||mincost[u]<mincost[v]))v=u;
        if(v==-1)break;
        used[v]=true;
        res+=mincost[v];
        for(int u=0;u<graph.Vertex_num;u++){
            T cost_vu=graph.INF;
            for(auto x:graph.g[v])if(x.to==u)cost_vu=x.cost;
            mincost[u]=min(mincost[u],cost_vu);
        }
    }
    return res;
}
