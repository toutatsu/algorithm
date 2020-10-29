//木に対しては単一最短経路のコストをdfsで求められる ABC070 D, ABC 126 D,ABC 148 F verified 
template<typename T>
int dfs(Tree<T>*t,int current_v,int parent_v,T cost){
    t->parent[current_v]=parent_v;
    t->depth[current_v]=cost;
    for(auto x:t->g[current_v])if(x.to!=parent_v)dfs(t,x.to,current_v,cost+x.cost);//(木の子孫は全て未訪問)
    return cost;
}

int main(){
    int ans=dfs(&t,x-1,-1,0);
}
