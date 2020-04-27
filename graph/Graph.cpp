#include<iostream>
#include<vector>
#include<limits>
using namespace std;

template<typename T>
class Graph{
    public:
    struct edge{int to;T cost;};
    int Vertex_num,Edge_num;
    vector<edge>*g;

    const T INF=10000000000000;

    Graph(int V,int E){//0～V-1
        Vertex_num=V;
        Edge_num=E;
        g=new vector<edge>[V];
    }

    void emplace_back(int from,int to,T cost){
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
            this->emplace_back(from,to,cost);
            if(!direct)this->emplace_back(to,from,cost);
        }
    }

    void check(){
        for(int i=0;i<Vertex_num;i++){
            cout<<"Vertex "<<i<<endl;
            for(auto x:g[i])cout<<x.to<<" "<<x.cost<<endl;
        }
    }
};
