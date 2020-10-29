#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Tree : public Graph<T>{
    public:
    
    Tree(int V):Graph<T>::Graph(V,V-1){
        depth=vector<T>(Graph<T>::Vertex_num,0);
        parent=vector<T>(Graph<T>::Vertex_num,-1);
    };
};

mod_int<1000000007>dp[2][100000];

//AtCoder Beginner Contest 036 D
//https://atcoder.jp/contests/abc036/submissions/17712281
//tは参照渡し
void tree_dp(Tree<int>*t,int root,int parent){
    dp[0][root]=dp[1][root]=1LL;
    if(t->g[root].size()==1&&t->g[root][0].to==parent){
        dp[0][root]=2;
        return;
    }
    for(auto x:t->g[root]){
        if(x.to==parent)continue;
        tree_dp(t,x.to,root);
        dp[0][root]*=dp[1][x.to];
        dp[1][root]*=dp[0][x.to];
    }
    dp[0][root]+=dp[1][root];
    return;
}

int N;
using namespace std;
int main(){
    cin>>N;
    Tree<int>t(N);
    t.input(false,false);
    tree_dp(&t,0,-1);
    cout<<dp[0][0]<<endl;
    return 0;
}
