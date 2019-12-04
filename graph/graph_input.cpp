#include<iostream>
#include<vector>

    int vertices,edges;
    cin>>vertices>>edges;
    //隣接行列
    int graph[vertices][vertices];
    for(int i=0;i<edges;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;//0オリジン
        graph[a][b]=c;//graph[b][a]=c;  #無向グラフ
    }

    typedef struct{int to;int cost;}edge;
    //隣接リスト
    vector<edge>graph[vertices];
    for(int i=0;i<edges;i++){
        int a;
        edge e;
        cin>>a>>e.to>>e.cost;
        a--;e.to--;//0オリジン
        graph[a].push_back(e);
        //graph[b].push_back(e);   #無向グラフ
    }
