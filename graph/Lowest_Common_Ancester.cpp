//AOJ GRL_5_C: Lowest Common Ancestor verified
#include<iostream>
#include<vector>
using namespace std;
vector<int>tree[100000];
long long depth[100000],parent[20][100000];
void dfs(int current_v,int parent_v,long long cost){
    parent[0][current_v]=parent_v;
    depth[current_v]=cost;
    for(auto x:tree[current_v])if(x!=parent_v)dfs(x,current_v,cost+1LL);//(木の子孫は全て未訪問)
    return;
}
//蟻本p293　O(logN)
int LCA(int u,int v){
    if(depth[u]>depth[v])swap(u,v);
    //uとvの深さが同じになるまで親を辿る
    for(int k=0;k<20;k++){
        if((depth[v]-depth[u])>>k&1)v=parent[k][v];
    }
    if(u==v)return u;
    //二分探索でLCAを求める
    for(int k=20-1;k>=0;k--){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
int main(){
    int n,k,c,root=0,q,u,v;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){cin>>c;tree[i].push_back(c);}
    }
    dfs(root,-1,0LL);
    //parent初期化O(NlogN)
    for(int k=0;k+1<20;k++){
        for(int v=0;v<n;v++){
            if(parent[k][v]<0)parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        cout<<LCA(u,v)<<endl;
    }
    return 0;
}


-------------------------------------------------------------------------------------------------------------------------
    
//AOJ GRL_5_C: Lowest Common Ancestor TLE
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
