//蟻本p286
//O(|V|+|E|)
//GRL_3_C: Strongly Connected Components verified
#include<iostream>
#include<vector>
using namespace std;
vector<int>g[V],rg[V],vs;//vsは帰りがけの順
bool visited[V];
int cmp[V];

void dfs(int v){
    visited[v]=true;
    for(auto x:g[v])if(!visited[x])dfs(x);
    vs.push_back(v);
}
void rdfs(int v,int cnt){
    visited[v]=true;
    cmp[v]=cnt;
    for(auto x:rg[v])if(!visited[x])rdfs(x,cnt);
}

int main(){
    int v,e,s,t,q,cnt=0;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>s>>t;
        g[s].push_back(t);
        rg[t].push_back(s);
    }
    
    for(int i=0;i<v;i++)if(!visited[i])dfs(i);
    for(auto &x:visited)x=false;
    for(int i=v-1;i>=0;i--)if(!visited[vs[i]])rdfs(vs[i],cnt++);
    
    return 0;
}
