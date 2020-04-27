//Floyd-Warshall algorithm
//Worst-case performance        O(|V|^3)
//Average performance           O(|V|^3)
//Best-case performanceO        O(|V|^3)
//Worst-case space complexity   O(|V|^2)

//AOJ GRL_1_C: All Pairs Shortest Path Verified
template<typename T>
vector<vector<T>> floyd_warshall(Graph<T>graph){
    vector<vector<T>>dist(graph.Vertex_num,vector<T>(graph.Vertex_num,graph.INF));
    for(int i=0;i<graph.Vertex_num;i++)dist[i][i]=0;

    for(int v=0;v<graph.Vertex_num;v++)for(int e=0;e<graph.g[v].size();e++)
    dist[v][graph.g[v][e].to]=graph.g[v][e].cost;

    for(int k=0;k<graph.Vertex_num;k++)
    for(int i=0;i<graph.Vertex_num;i++)
    for(int j=0;j<graph.Vertex_num;j++)
    if(dist[i][k]!=graph.INF&&dist[k][j]!=graph.INF&&//INFを中継しない
    dist[i][j]>dist[i][k]+dist[k][j])dist[i][j]=dist[i][k]+dist[k][j];

    for(int i=0;i<graph.Vertex_num;i++)if(dist[i][i]<0)return vector<vector<T>>(0);//閉路有

    return dist;
}

//最短経路出力　アルゴリズム論より
//verifyしろ

int pred[v][v];

for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            pred[i][j]=-1;

for(int k=0;k<v;k++)
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            if(graph[i][k]+graph[k][j]<graph[i][j])
                graph[i][j]=min();pred[i][j]=k;


void path(int i,int j,int pred[v][v]){
    if(pred[i][j]==-1)cout<<i<<j<<endl;
    else{
        path(i,pred[i][j],pred);
        path(path[i][j],j,pred);
    }
}

