//蟻本p279
//O(|V|+|E|)

vector<T>graph[V],rgraph[V],vs;//vsは帰りがけの順
visited[vertex];
//recursion

void dfs(int v){
    visited[v]=true;
    for(all adjacence vertex)if(!visited[vertex])dfs(x);
    vs.push_back(v);
}

void rdfs(int v,int k){
    visited[v]=true;
    comp[v]=k;
    //rgraph
    for(all adjacence vertex)if(!visited[vertex])dfs(x,k);
}

int scc(){
    for(all vertex)if(!visited[i])dfs(i);
    for(all)visited[]=false;
    for(int i=vs.size()-1,k=0;i>=0;i--){
        if(visited[vs[i]])rdfs(vs[i],k++);
    }
    return k;
}




