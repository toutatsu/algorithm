//Graph用のbfs

//AtCoder Beginner Contest 021 C
//https://atcoder.jp/contests/abc021/submissions/16442866

template<typename T>
vector<T>bfs(Graph<T>graph,int start){
    vector<T>dist(graph.Vertex_num,-1);//訪問:startからの距離 未訪問:-1
    queue<int>q;
    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int p=q.front();q.pop();
        for(auto x:graph.g[p])if(dist[x.to]==-1){dist[x.to]=dist[p]+x.cost;q.push(x.to);}
        //visited[]の更新はpushするときにやらないとqueueがあふれる↑
    }
    return dist;
}




//ABC146D verified

    queue<int>q;
//スタート地点
    q.push(0);
    visited[0]=true;

    while(!q.empty()){
        
        int p=q.front();q.pop();
        
        for(auto& x:graph[p])if(!visited[x]){visited[x]=true;q.push(x);}
    }

//visited[]=trueはpushするときにやらないとqueueがあふれる↑
//ABC151D verified 

        queue<tuple<int,int,int>>q;
        q.push(make_tuple(i,j,0));
        visited[i][j]=true;
        d[i][j]=0;
        while(!q.empty()){
            tuple<int,int,int> p=q.front();q.pop();

            d[get<0>(p)][get<1>(p)]=get<2>(p);
            
            for(int i=0;i<4;i++){
                int ni=get<0>(p)+d4[i],nj=get<1>(p)+d4[i+1];
                if(0<=ni&&ni<h&&0<=nj&&nj<w){
                    if(visited[ni][nj]==false&&s[ni][nj]=='.')visited[ni][nj]=true,q.push(make_tuple(ni,nj,get<2>(p)+1));
                }
            }
        }
