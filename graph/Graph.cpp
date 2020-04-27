#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

template<typename T>
class Graph{
    struct edge{int to;T cost;};
    //struct edge{int to;T cap,rev;}; //ford_fulkerson

    public:
    int Vertex_num,Edge_num;
    vector<edge>*g;
    vector<bool>visited;//dfs用
    //vector<edge>edges;//for Bellman-Ford

    const T INF=numeric_limits< T >::max();//#include<limits>

    Graph(int V,int E){//0～V-1
        Vertex_num=V;
        Edge_num=E;
        g=new vector<edge>[V];
        visited=vector<bool>(Vertex_num,false);
        // //edges=new vector<edge>(E);//for Bellman-Ford
    }

    void append(int from,int to,T cost){
        edge e={to,cost};
        g[from].push_back(e);
        //edges->push_back(e);//for Bellman-Ford
    }

    void input(bool direct,bool weight){
        int from,to;
        T cost;
        for(int i=0;i<Edge_num;i++){
            cin>>from>>to;
            if(weight)cin>>cost;
            else cost=1;
            this->append(from,to,cost);
            if(!direct)this->append(to,from,cost);
        }
    }

//     // void flow_input(){
//     //     int from,to;
//     //     T cap;
//     //     for(int i=0;i<Edge_num;i++){
//     //         cin>>from>>to>>cap;
//     //         g[from].push_back(edge{to,cap,int(g[to].size())});
//     //         g[to].push_back(edge{from,0,int(g[from].size()-1)});
//     //     }
//     // }

    void check(){
        for(int i=0;i<Vertex_num;i++){
            cout<<"Vertex "<<i<<endl;
            for(auto x:g[i])cout<<x.to<<" "<<x.cost<<endl;
        }
    }

    
    void dfs(int start){
        visited[start]=true;
        cout<<start<<"visit"<<endl;
        for(auto x:g[start])if(!visited[x.to])dfs(x.to);
    }

    vector<T>bfs(int start){//重み無しの時最短経路になる？
        vector<T>dist(Vertex_num,-1);//訪問:startからの距離 未訪問:-1
        queue<int>q;
        q.push(start);
        dist[start]=0;
        while(!q.empty()){
            int p=q.front();q.pop();
            for(auto x:g[p])if(dist[x.to]==-1){dist[x.to]=dist[p]+x.cost;q.push(x.to);}
            //visited[]の更新はpushするときにやらないとqueueがあふれる↑
        }
        return dist;
    }

    vector<T>dijkstra(int start){
        //#include<queue>
        vector<T>dist(Vertex_num,INF);
        dist[start]=0;

        priority_queue<pair<T,int>>q;//cost,vertex_num : costでソートさせる

        pair<T,int>c;
        q.push(make_pair(0,start));
        while(!q.empty()){
            c=q.top(),q.pop();
            for(auto x:g[c.second]){
                long new_cost=c.first+x.cost;//現在地までのコスト+頂点x.toへの辺のコスト
                if(new_cost<dist[x.to]){
                    dist[x.to]=new_cost;
                    //prev[x.to]=c.second;//帰り道
                    q.push(make_pair(dist[x.to],x.to));
                }
            }
        }
        return dist;
    }

//     // vector<T>bellman_ford(int start){
//     //     //Bellman-Ford algorithm
//     //     //Worst-case performance        O(|V||E|)
//     //     //Average performance           
//     //     //Best-case performance         O(|E|)
//     //     //Worst-case space complexity   O(|V|)
//     //     //蟻本89p参考
//     //     vector<T>dist(Vertex_num,INF);
//     //     dist[start]=0;
//     //     for(int i=0;i<Vertex_num;i++){
//     //         for(int j=0;j<Edge_num;j++){
//     //             if(dist[edges[j].to]>dist[edges[j].from]+edges[j].cost){
//     //                 dist[edges[j].to]=dist[edges[j].from]+edges[j].cost;
//     //                 if(i==Vertex_num-1)return vector<int>(1,-1);//負閉路
//     //             }
//     //         }
//     //     }
//     //     return dist;
//     // }

    vector<int>topological_sort(){
        //O(V+E)
        vector<int>indeg(Vertex_num,0),ret;//indeg[i]=頂点iの入次数
        queue<int>Q;//#include<queue> 入次数が0の頂点のリスト　キューでもスタック stack<int>S でもよい
        for(int i=0;i<Vertex_num;i++)for(auto x:g[i])indeg[x.to]++;//入次数をカウント
        for(int i=0;i<Vertex_num;i++)if(indeg[i]==0)Q.push(i);//入次数が0の頂点を入れる
        while(!Q.empty()){
            int v=Q.front();Q.pop();
            ret.push_back(v);
            for(auto x:g[v]){
                indeg[x.to]--;//頂点に繋がる頂点の入次数を減らす
                if(indeg[x.to]==0)Q.push(x.to);//入次数が0になったら追加
            }
        }
        //もし入次数が0でない頂点が残っていたらDAGでない
        if(ret.size()!=Vertex_num)cerr<<"閉路有 DAGではありません"<<endl;
        return ret;
    }


// //     T flow_dfs(int v,int sink,T f){//増加パスを探す
// //         if(v==sink)return f;
// //         visited[0][v]=true;
// //         for(int i=0;i<g[v].size();i++){
// //             edge &e=g[v][i];
// //             if(!visited[0][e.to]&&e.cap>0){
// //                 T d=flow_dfs(e.to,sink,min(f,e.cap));
// //                 if(d>0){
// //                     e.cap-=d;
// //                     g[e.to][e.rev].cap+=d;
// //                     return d;
// //                 }
// //             }
// //         }
// //         return 0;
// // }
// //     T ford_fulkerson(int source,int sink){
// //         //sourceからsinkへの最大流量flowを求める
// //         T flow,f;
// //         for(flow=0;(f=flow_dfs(source,sink,INF))!=0;flow+=f)for(auto& x:visited[0])x=false;
// //         return flow;
// //     }
// //     // typedef struct{int to,cap,rev;}flow_edge;
// //     // vector<edge>g[v];//グラフの隣接リスト
// //     // bool visited[v];//dfsで使用


};


int V,E;
int main(){
    cin>>V>>E;
    Tree<long long>t(V);
    t.input(false,false);
    t.check();
    cout<<t.tree_diameter()<<endl;
    return 0;
}
