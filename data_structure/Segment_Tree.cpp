#include<iostream>
#include<vector>
#include<cassert>
#include<functional>
using namespace std;

//AtCoder Beginner Contest 185 F
//ACL D
template<class Monoid>class SegmentTree{
    //0-index
    public:
    int size=1;
    const function<Monoid(Monoid, Monoid)>F;
    const Monoid e;
    vector<Monoid>data;

    SegmentTree(int sz,const function<Monoid(Monoid,Monoid)>f,const Monoid &e):
    F(f),e(e)
    {
        while(size<sz)size*=2;//要素数nを2の冪乗に
        data.assign(size*2,e);
    }
    
    void update(int k,int a){//k番目の要素をaに更新
        k+=size-1;//k番目の葉のインデックス
        data[k]=a;//葉を更新
        while(k>0){//頂点に達するまで親を更新
            k=(k-1)/2;
            data[k]=F(data[k*2+1],data[k*2+2]);
        }
    }

    //[a,b)の最小値を返す
    //k 接点番号　[l,r)に対応
    Monoid query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return e;//完全に範囲外
        if(a<=l&&r<=b)return data[k];//完全に範囲内
        int mid=(l+r)/2;
        return F(query(a,b,k*2+1,l,mid),query(a,b,k*2+2,mid,r));
    }
    //query(a,b,0,0,n)を呼ぶ
    Monoid query(int a,int b){return query(a,b,0,0,size);}
    
    //https://drken1215.hatenablog.com/entry/2020/09/27/080300
    // Monoid get(int a, int b) {
    //     Monoid vleft = UNITY, vright = UNITY;
    //     for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
    //         if (left & 1) vleft = F(vleft, dat[left++]);
    //         if (right & 1) vright = F(dat[--right], vright);
    //     }                                                                                                              
    //     return F(vleft, vright);
    // }
    inline Monoid operator[](int a){return data[a+size-1];}
    
    void check(){
        for (int i=0;i<size;i++)cout<<(*this)[i]<<" \n"[i==size-1];
    }
};


int N,K,A;
int main(){
    cin>>N>>K;
    SegmentTree<int>S(510000,[&](int a, int b){return max(a, b);},0);
    for(int i=0;i<N;i++){
        cin>>A;
        S.update(A,S.query(max(0,A-K), min(510000,A+K+1))+1);
    }
    cout<<S.query(0,510000)<<endl;
    return 0;
}

// #include<iostream>
// using namespace std;
// //AOJ DSL_2_A: Range Minimum Query (RMQ) verified
// //ABC 157 E 葉にbitを載せる
// class SegmentTree{
//     //0-index
//     public:
//     int n=1,*data,NO_DATA=0x7fffffff;

//     SegmentTree(int n_){
//         while(n<n_)n*=2;//要素数nを2の冪乗に
//         data=new int[n*2-1];
//         for(int i=0;i<n*2-1;i++)data[i]=NO_DATA;//木をNO_DATAで初期化
//     }
    
//     int comp(int a,int b){return a|b;}//比較関数 親に返す値
    
//     void updata(int k,int a){//k番目の要素をaに更新
//         k+=n-1;//k番目の葉のインデックス
//         data[k]=a;//葉を更新
//         while(k>0){//頂点に達するまで親を更新
//             k=(k-1)/2;
//             data[k]=comp(data[k*2+1],data[k*2+2]);
//         }
//     }

//     //[a,b)の最小値を返す
//     //k 接点番号　[l,r)に対応
//     int query(int a,int b,int k,int l,int r){
//         if(r<=a||b<=l)return NO_DATA;//完全に範囲外
//         if(a<=l&&r<=b)return data[k];//完全に範囲内
//         int mid=(l+r)/2;
//         return comp(query(a,b,k*2+1,l,mid),query(a,b,k*2+2,mid,r));
//     }
//     //query(a,b,0,0,n)を呼ぶ
//     int query(int a,int b){return query(a,b,0,0,n);}
    
//     void check(){
//         for (int i=0;i<n;i++)cout<<data[n - 1 + i]<<" \n"[i==n-1];
//     }
// };


// //ABC 157 E
// class SegmentTree
// {
//     //0-index
// public:
//     int n = 1, *data, INT_MAX = 0x7fffffff;

//     SegmentTree(int n_)
//     {
//         while (n < n_)
//             n *= 2; //要素数nを2の冪乗に
//         data = new int[n * 2 - 1];
//         for (int i = 0; i < n * 2 - 1; i++)
//             data[i] = 0;
//     }

//     int comp(int a, int b) { return a | b; }

//     void updata(int k, int a)
//     {                //k番目の要素をaに更新
//         k += n - 1;  //k番目の葉のインデックス
//         data[k] = a; //葉を更新
//         while (k > 0)
//         { //頂点に達するまで親を更新
//             k = (k - 1) / 2;
//             data[k] = comp(data[k * 2 + 1], data[k * 2 + 2]);
//         }
//     }

//     //[a,b)の最小値を返す
//     //k 接点番号　[l,r)に対応

//     int query(int a, int b, int k, int l, int r)
//     {
//         if (r <= a || b <= l)
//             return 0; //完全に範囲外
//         if (a <= l && r <= b)
//             return data[k]; //完全に範囲内
//         int mid = (l + r) / 2;
//         return comp(query(a, b, k * 2 + 1, l, mid), query(a, b, k * 2 + 2, mid, r));
//     }
//     //query(a,b,0,0,n)を呼ぶ
//     int query(int a, int b) { return query(a, b, 0, 0, n); }

//     void check()
//     {
//         for (int i = 0; i < n; i++)
//             cout << bitset<26>(data[n - 1 + i]) << " \n"[i == n - 1];
//     }
// };
