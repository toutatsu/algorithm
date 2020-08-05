\\paiza S002:最短距離を測る verified
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class Grid{
    public:
    struct position{
        int i,j;
        bool operator == (const position& x) const {return (i==x.i&&j==x.j);}
    };

    int Height_num,Width_num;
    
    const int unreachable=100000000;

    vector<T>*grid;

    Grid(int Height,int Width){
        Height_num=Height;
        Width_num=Width;
        grid=new vector<T>[Height];
        for(int i=0;i<Height;i++)grid[i]=*new vector<T>(Width);
        //vector<vector<T>>grid(Height,vector<T>(Width));
    }

    void input(){
        for(int i=0;i<Height_num*Width_num;i++)cin>>grid[i/Width_num][i%Width_num];
    }

    void check(){
        for(int i=0;i<Height_num*Width_num;i++)cout<<grid[i/Width_num][i%Width_num]<<" \n"[i%Width_num==Width_num-1];
    }

    vector<vector<int>> BFS(int start_i,int start_j){
        position start={start_i,start_j};
        vector<vector<int>>d(Height_num,vector<int>(Width_num,-1));
        vector<vector<bool>>visited(Height_num,vector<bool>(Width_num,false));

        queue<position>q;
        q.push(start);
        visited[start.i][start.j]=true;
        d[start.i][start.j]=0;

        int d4[5]={0,1,0,-1,0};
        
        while(!q.empty()){
            position state=q.front();q.pop();
            for(int i=0;i<4;i++){
                position neighbor={state.i+d4[i],state.j+d4[i+1]};
                if(neighbor.i<0||Height_num<=neighbor.i||neighbor.j<0||Width_num<=neighbor.j)continue;//out of range
                if(visited[neighbor.i][neighbor.j])continue;
                if(grid[neighbor.i][neighbor.j]=='0'||grid[neighbor.i][neighbor.j]=='g'){//reachable
                    visited[neighbor.i][neighbor.j]=true;
                    d[neighbor.i][neighbor.j]=d[state.i][state.j]+1;
                    q.push(neighbor);
                }
            }
        }
        return d;
    }
};

int main(){
    int M,N;
    cin>>M>>N;
    Grid<char>g(N,M);
    g.input();
    int start_i,start_j,goal_i,goal_j;
    for(int i=0;i<N*M;i++){
        if(g.grid[i/M][i%M]=='s'){start_i=i/M,start_j=i%M;}
        if(g.grid[i/M][i%M]=='g'){goal_i=i/M,goal_j=i%M;}
    }
    auto d=g.BFS(start_i,start_j);
    cout<<(d[goal_i][goal_j]==-1?"Fail":to_string(d[goal_i][goal_j]))<<endl;
    return 0;
}
