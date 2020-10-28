//AOJ GRL_4_B Topological Sort verified

//AtCoder Beginner Contest 021 C
//https://atcoder.jp/contests/abc021/submissions/16442866

//AtCoder Beginner Contest 139 E DAG最長経路
//https://atcoder.jp/contests/abc139/submissions/17705313

//O(V+E)
//Graph用
template<typename T>
vector<int>topological_sort(Graph<T>graph){
    //O(V+E)
    vector<int>indeg(graph.Vertex_num,0),ret;//indeg[i]=頂点iの入次数
    queue<int>Q;//#include<queue> 入次数が0の頂点のリスト　キューでもスタック stack<int>S でもよい
    for(int i=0;i<graph.Vertex_num;i++)for(auto x:graph.g[i])indeg[x.to]++;//入次数をカウント
    for(int i=0;i<graph.Vertex_num;i++)if(indeg[i]==0)Q.push(i);//入次数が0の頂点を入れる
    while(!Q.empty()){
        int v=Q.front();Q.pop();
        ret.push_back(v);
        for(auto x:graph.g[v]){
            indeg[x.to]--;//頂点に繋がる頂点の入次数を減らす
            if(indeg[x.to]==0)Q.push(x.to);//入次数が0になったら追加
        }
    }
    //もし入次数が0でない頂点が残っていたらDAGでない
    if(ret.size()!=graph.Vertex_num)return vector<int>(0);//cerr<<"閉路有 DAGではありません"<<endl;
    return ret;
}
int V,E;
int main(){
    cin>>V>>E;
    Graph<long long>g(V,E);
    g.input(true,false);
    auto t=topological_sort(g);
    for(auto x:t)cout<<x<<endl;
    return 0;
}


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
