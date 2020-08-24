#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct position{
    int i,j;
    bool operator == (const position& x) const {return (i==x.i&&j==x.j);}
};
template<typename T>
class Grid{
    public:

    int Height_num,Width_num;
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
};
