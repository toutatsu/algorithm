//Floyd-Warshall algorithm
//Worst-case performance        O(|V|^3)
//Average performance           O(|V|^3)
//Best-case performanceO        O(|V|^3)
//Worst-case space complexity   O(|V|^2)
for(int k=0;k<v;k++)for(int i=0;i<v;i++)for(int j=0;j<v;j++)graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);



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

