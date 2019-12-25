//AOJ GRL_4_B Topological Sort verified
//O(V+E)
vector<int> t_sort(vector<int>g[]){
    vector<int>indeg(v,0),ret;//indeg[i]=頂点iの入次数
    queue<int>Q;//stack<int>S;//入次数が0の頂点のリスト　キューでもスタックでもよい
    for(int i=0;i<v;i++)for(auto x:g[i])indeg[x]++;//入次数をカウント
    for(int i=0;i<v;i++)if(indeg[i]==0)Q.push(i);//入次数が0の頂点をスタックに
    while(!Q.empty()){
        int v=Q.front();Q.pop();
        ret.push_back(v);
        for(auto x:g[v]){
            indeg[x]--;//頂点に繋がる頂点の入次数を減らす
            if(indeg[x]==0)Q.push(x);//入次数が0になったら追加
        }
    }
    return ret;
}

//深さ優先探索版も追加する
