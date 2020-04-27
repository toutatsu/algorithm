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


//AOJ GRL_2_A: Minimum Spanning Tree Verified
//蟻本p101参照
//O(ElogV)
template<typename T>
T kruskal(Graph<T>graph){//disjointsetが必要
    struct edge{int from,to;T cost;};
    vector<edge>edges(0);

    for(int v=0;v<graph.Vertex_num;v++){
        for(int e=0;e<graph.g[v].size();e++){
            edges.push_back(edge{v,graph.g[v][e].to,graph.g[v][e].cost});
        }
    }
    sort(edges.begin(),edges.end(),[](const edge& x,const edge& y){return x.cost<y.cost;});
    disjointset ds(graph.Vertex_num);
    T res=0;
    for(int i=0;i<graph.Edge_num*2;i++){//無向辺で構築したGraphの辺の数は二倍
        if(!ds.same(edges[i].from,edges[i].to)){
            ds.unite(edges[i].from,edges[i].to);
            res+=edges[i].cost;
        }
    }
    return res;
}
