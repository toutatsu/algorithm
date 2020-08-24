//AtCoder Beginner Contest 176 D
template<typename T>
vector<vector<int>> BFS(Grid<T>g,int start_i,int start_j){
    position start={start_i,start_j};
    const int unreachable=1000000000;
    vector<vector<int>>d(g.Height_num,vector<int>(g.Width_num,unreachable));
    //vector<vector<bool>>visited(g.Height_num,vector<bool>(g.Width_num,false));
    deque<position>q;
    q.push_front(start);
    //visited[start.i][start.j]=true;
    d[start.i][start.j]=0;
    
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    while(!q.empty()){
        position state=q.front();q.pop_front();
        for(int i=0;i<4;i++){
            position neighbor={state.i+dx[i],state.j+dy[i]};
            //out of range
            if(!(0<=neighbor.i&&neighbor.i<g.Height_num&&0<=neighbor.j&&neighbor.j<=g.Width_num))continue;
            //unreachable
            if(g.grid[neighbor.i][neighbor.j]=='#')continue;
            //visited
            if(d[neighbor.i][neighbor.j]<=d[state.i][state.j])continue;
            //update distance
            d[neighbor.i][neighbor.j]=d[state.i][state.j];
            //push 
            q.push_front(neighbor);
        }

        for(int i=0;i<5*5;i++){
            position neighbor={state.i+i/5-2,state.j+i%5-2};
            //out of range
            if(!(0<=neighbor.i&&neighbor.i<g.Height_num&&0<=neighbor.j&&neighbor.j<=g.Width_num))continue;
            //unreachable
            if(g.grid[neighbor.i][neighbor.j]=='#')continue;
            //visited
            if(d[neighbor.i][neighbor.j]<=d[state.i][state.j]+1)continue;
            //update distance
            d[neighbor.i][neighbor.j]=d[state.i][state.j]+1;
            //push 
            q.push_back(neighbor);
        }
    }
    return d;
}
int H,W,Ch,Cw,Dh,Dw;
int main(){
    cin>>H>>W>>Ch>>Cw>>Dh>>Dw;
    Grid<char>g(H,W);
    g.input();
    auto d=BFS(g,Ch-1,Cw-1);
    cout<<(d[Dh-1][Dw-1]==1000000000?-1:d[Dh-1][Dw-1])<<endl;
    return 0;
}
