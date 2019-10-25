//Bellman-Ford algorithm
//Worst-case performance        O(|V||E|)
//Average performance           
//Best-case performance         O(|E|)
//Worst-case space complexity   O(|V|)

//蟻本89p参考

struct edge{int ,from,to,cost;};
int INF=0x7fffffff;

vector<int> bellman-ford(int start){
    vector dist(v,INF);
    edge es[e];
    dist[start]=0;
    for(int i=0;i<v;i++){
        for(int j=0;j<e;j++){
            if(d[es[j].to]>d[es[j].from]+es[j].cost){
                d[es[j].to]=d[es[j].from]+es[j].cost
                if(i==v-1)return vector<int>v(v,-1);//負閉路
            }
        }
    }
    return dist;
}




//ABC061
//負閉路の検出だけでなく負閉路から頂点nに到達可能か判定

#include<iostream>
#include<vector>
using namespace std;
struct edge{long from,to,cost;};
long bellman_ford(int start){
    long n,m,a;
    cin>>n>>m;
    edge es[m];
    for(int i=0;i<m;i++){
        cin>>es[i].from>>es[i].to>>es[i].cost;
        es[i].from--;es[i].to--;es[i].cost*=-1;
    }
    vector<long>dist(n,0x7fffffffffffff);
    dist[start]=0L;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[es[j].to]>dist[es[j].from]+es[j].cost){
                dist[es[j].to]=dist[es[j].from]+es[j].cost;
            }
        }
    }
    
    bool f[n]={};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[es[j].from]==0x7fffffffffffff)continue;
            if(dist[es[j].to]>dist[es[j].from]+es[j].cost){
                dist[es[j].to]=dist[es[j].from]+es[j].cost;
                f[es[j].to]=true;
            }
            if(f[es[j].from]==true)f[es[j].to]=true;
        }
    }
    return f[n-1]?0x7fffffffffffff:dist[n-1];
}

int main(){
    long a=bellman_ford(0)*-1;
    if(a==0x7fffffffffffff*-1)cout<<"inf"<<endl;
    else cout<<a<<endl;
    return 0;
}
