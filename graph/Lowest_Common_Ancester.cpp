#include<iostream>
#include<vector>
using namespace std;
vector<int>tree[100000];
long long depth[100000],parent[100000];
void dfs(int current_v,int parent_v,long long cost){
    parent[current_v]=parent_v;
    depth[current_v]=cost;
    for(auto x:tree[current_v])if(x!=parent_v)dfs(x,current_v,cost+1LL);//(木の子孫は全て未訪問)
    return;
}
//蟻本p292　O(N)
int LCA(int u,int v){
    //uとvの深さが同じになるまで親を辿る
    while(depth[u]>depth[v])u=parent[u];
    while(depth[v]>depth[u])v=parent[v];
    //同じ頂点に到達するまで親を辿る
    while(u!=v)u=parent[u],v=parent[v];
    return u;
}
int main(){
    int n,k,c,root=0,q,u,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){cin>>c;tree[i].push_back(c);}
    }
    dfs(root,-1,0LL);
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        cout<<LCA(u,v)<<endl;
    }
    return 0;
}
