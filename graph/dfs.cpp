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
