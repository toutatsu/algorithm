class Tree : public Graph<T>{
    //Graph<T>:: this->と同じ？
    public:
    vector<T>depth,parent;//dfs用

    Tree(int V):Graph<T>::Graph(V,V-1){
        depth=vector<T>(Graph<T>::Vertex_num,0);
        parent=vector<T>(Graph<T>::Vertex_num,-1);
    };

    //木に対しては単一最短経路のコストをdfsで求められる ABC070 D, ABC 126 D,ABC 148 F verified 

    void Tree_dfs(int current_v,int parent_v,T cost){
        parent[current_v]=parent_v;
        depth[current_v]=cost;
        for(auto x:Graph<T>::g[current_v])if(x.to!=parent_v)dfs(x.to,current_v,cost+x.cost);//(木の子孫は全て未訪問)
    }
    void dfs(int root){Tree_dfs(root,-1,0LL);}//再帰関数の呼び出し

    T tree_diameter(){
        vector<T>a=Graph<T>::bfs(0);
        int idx=-1,ma=-1;
        for(int i=0;i<Graph<T>::Vertex_num;i++)if(ma<a[i])ma=a[i],idx=i;
        a=Graph<T>::bfs(idx);
        ma=-1;
        for(int i=0;i<Graph<T>::Vertex_num;i++)if(ma<a[i])ma=a[i];
        return ma;
    }

    int slow_LCA(int u,int v){
        //蟻本p292　O(N)
        //uとvの深さが同じになるまで親を辿る
        while(depth[u]>depth[v])u=parent[u];
        while(depth[v]>depth[u])v=parent[v];
        //同じ頂点に到達するまで親を辿る
        while(u!=v)u=parent[u],v=parent[v];
        return u;
    }

    void LCA_init(int root){
        this->tree_dfs(root);

        //parent初期化O(NlogN)
        for(int k=0;k+1<20;k++){
            for(int v=0;v<Graph<T>::Vertex_num;v++){
                if(parent[k][v]<0)parent[k+1][v]=-1;
                else parent[k+1][v]=parent[k][parent[k][v]];
            }
        }
    }
    int LCA(int u,int v){
        //蟻本p293　O(logN)
        //使用前にLCA_init()を呼ぶ

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
};
