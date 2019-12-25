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
    //もし入次数が0にでない頂点が残っていたらDAGでない
    return ret;
}


//wikipedia 3つ目のコード
//AOJ GRL_4_B Topological Sort verified

vector<int>t_sort; //← トポロジカルソートされた結果の入る空の連結リスト
int visited[v]; //0:未訪問 1:一時的に訪問 2:恒久的に訪問

bool dfs(int v){
    if(visited[v]==1)return false;//閉路があり DAG でないので中断
    else if(visited[v]==0){//未訪問
        visited[v]=1;//n に「一時的」の印を付ける
        for(auto x:g[v])dfs(x);
        visited[v]=2;
        t_sort.push_back(v);//vを先頭に追加
    }
}

int main(){

    for(int i=0;i<v;i++)if(!visited[i])dfs(i);
    reverse(t_sort.begin(),t_sort.end());//逆順に
}
