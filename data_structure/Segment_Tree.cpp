#include<iostream>
using namespace std;
//AOJ DSL_2_A: Range Minimum Query (RMQ) verified
//ABC 157 E 葉にbitを載せる
class SegmentTree{
    //0-index
    public:
    int n=1,*data,NO_DATA=0x7fffffff;

    SegmentTree(int n_){
        while(n<n_)n*=2;//要素数nを2の冪乗に
        data=new int[n*2-1];
        for(int i=0;i<n*2-1;i++)data[i]=NO_DATA;//木をNO_DATAで初期化
    }
    
    int comp(int a,int b){return a|b;}//比較関数 親に返す値
    
    void updata(int k,int a){//k番目の要素をaに更新
        k+=n-1;//k番目の葉のインデックス
        data[k]=a;//葉を更新
        while(k>0){//頂点に達するまで親を更新
            k=(k-1)/2;
            data[k]=comp(data[k*2+1],data[k*2+2]);
        }
    }

    //[a,b)の最小値を返す
    //k 接点番号　[l,r)に対応
    int query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return NO_DATA;//完全に範囲外
        if(a<=l&&r<=b)return data[k];//完全に範囲内
        int mid=(l+r)/2;
        return comp(query(a,b,k*2+1,l,mid),query(a,b,k*2+2,mid,r));
    }
    //query(a,b,0,0,n)を呼ぶ
    int query(int a,int b){return query(a,b,0,0,n);}
    
    void check(){
        for (int i=0;i<n;i++)cout<<data[n - 1 + i]<<" \n"[i==n-1];
    }
};


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
