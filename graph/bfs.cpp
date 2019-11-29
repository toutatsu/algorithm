//ABC146D verified

    queue<int>q;
    q.push(0);
    visited[0]=true;

    while(!q.empty()){
        int p=q.front();q.pop();
        for(auto& x:graph[p])if(!visited[x]){visited[x]=true;q.push(x);}
    }
