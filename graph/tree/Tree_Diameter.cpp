

template<typename T>
T tree_diameter(Tree<T>tree){
    vector<T>a=Graph<T>::bfs(0);
    int idx=-1,ma=-1;
    for(int i=0;i<Graph<T>::Vertex_num;i++)if(ma<a[i])ma=a[i],idx=i;
    a=Graph<T>::bfs(idx);
    ma=-1;
    for(int i=0;i<Graph<T>::Vertex_num;i++)if(ma<a[i])ma=a[i];
    return ma;
}
