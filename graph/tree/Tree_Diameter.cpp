
//AOJ GRL_5_A: Diameter of a Tree Verified
//bfsが必要
template<typename T>
T tree_diameter(Tree<T>tree){
    vector<T>a=bfs(tree,0);
    int idx=-1,ma=-1;
    for(int i=0;i<tree.Vertex_num;i++)if(ma<a[i])ma=a[i],idx=i;
    a=bfs(tree,idx);
    ma=-1;
    for(int i=0;i<tree.Vertex_num;i++)if(ma<a[i])ma=a[i];
    return ma;
}

int N;
int main(){
    cin>>N;
    Tree<long long>tree(N);
    tree.input(false,true);
    cout<<tree_diameter(tree)<<endl;
    return 0;
}
