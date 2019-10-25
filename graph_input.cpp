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

    //隣接リスト
    vector<pair<int,int>>graph(vertices);
    for(int i=0;i<edges;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;//0オリジン
        graph[a].push_back(make_pair(b,c));
        //graph[b].push_back(make_pair(a,c));   #無向グラフ
    }
