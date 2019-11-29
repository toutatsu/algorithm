//テストしろ
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int p=q.front();q.pop();
        for(auto x:graph[p]){
            if(!visited[x]){visited[x]=true;q.push(x);}
        }
    }
