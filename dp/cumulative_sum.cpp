#include<iostream>
#include<vector>
using namespace std;

template<class T>class cumulative_sum{

    public:
    //0-idx
    vector<T>data;

    cumulative_sum(int size):data(size+1,0){};
    cumulative_sum(vector<T>d):data(d){data.insert(data.begin(),0LL);};

    void add(int k,T x){data[k+1]+=x;}

    void build(){for(int i=1;i<data.size();i++)data[i]+=data[i-1];}

    //[0,k)
    T query(int k){return data[k+1]; }
    //[l,r)
    T query(int l,int r){return data[r]-data[l];}
};
int main(){
    vector<int>a={1,2,3,4};
    cumulative_sum<int>acc(a);
    acc.build();
    cout<<acc.query(1,4)<<endl;
    return 0;
}
