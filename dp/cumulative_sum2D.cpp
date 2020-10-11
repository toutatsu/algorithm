//https://atcoder.jp/contests/abc005/submissions/17354257
#include<iostream>
#include<vector>
using namespace std;

template<class T>class cumulative_sum2D{
    public:
    //0-idx
    int h,w;
    vector<vector<T>>data;

    cumulative_sum2D(int h,int w):h(h+1),w(w+1),data(h,vector<T>(w,0LL)){};
    cumulative_sum2D(vector<vector<T>>d):data(d),h(d.size()+1),w(d[0].size()+1){
        data.insert(data.begin(),vector<T>(w,0LL));
        for(int i=1;i<h;i++)data[i].insert(data[i].begin(),0LL);
    };

    void add(int i,int j,T x){data[i+1][j+1]+=x;}

    void build(){
        for(int i=0;i<h;i++)for(int j=1;j<w;j++)data[i][j]+=data[i][j-1];
        for(int i=0;i<w;i++)for(int j=1;j<h;j++)data[j][i]+=data[j-1][i];
    }
    //左上:data[c][d]　右下:data[a][b]
    T query(int a,int b,int c,int d){
        return data[a+1][b+1]-data[c][b+1]-data[a+1][d]+data[c][d];
    }
};

int N,Q,P;
int o[2501];
int main(){
    cin>>N;
    vector<vector<int>>D(N,vector<int>(N));
    for(int i=0;i<N*N;i++)cin>>D[i/N][i%N];
    cumulative_sum2D<int>acc(D);
    acc.build();
    for(int a=0;a<N;a++)for(int b=0;b<N;b++)for(int c=0;c<=a;c++)for(int d=0;d<=b;d++)o[(a-c+1)*(b-d+1)]=max(o[(a-c+1)*(b-d+1)],acc.query(a,b,c,d));
    for(int i=1;i<=2500;i++)o[i]=max(o[i],o[i-1]);
    cin>>Q;
    for(int i=0;i<Q;i++){cin>>P;cout<<o[P]<<endl;}
    return 0;
}
