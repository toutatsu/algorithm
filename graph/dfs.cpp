visited[V]=false;

//recursion
void dfs(int v){
    visited[v]=true;
    for(all adjacence vertex)if(!visited[vertex])dfs(x);
}



//stack

stack<int>s;

s.push_back(0);
visited[0]=true;

while(!s.empty()){
    int p=s.top();s.pop();
    for(all adjacence vertex)if(!visited[vertex])s.push(vertex),visited[vertex]=true;
}


//木に対しては単一最短経路のコストをdfsで求められる ABC070 D

long long depth[v];

void dfs(int current_v,int parent,long long cost){
    depth[current_v]=cost;
    for(auto x:g[current_v])if(x.to!=parent)dfs(x.to,current_v,cost+x.cost);//(木の子孫は全て未訪問)
    return;
}

int main(){
    dfs(root,-1,0LL);
}
