#if ! defined(__cplusplus)
#error "not compiled with C++"
#endif

using namespace std;

void flag_check(bool f){cout<<(cout<<f?"true":"false"<<endl;)}

//変数名と値の出力
#define dbg(a) cerr<<#a<<":"<<a<<" ";//#は変数名
#define dbg2(a,b) dbg(a)dbg(b)
#define dbg3(a,b,c) dbg(a)dbg2(b,c)
#define dbg4(a,b,c,d) dbg2(a,b)dbg2(c,d)
#define dbg5(a,b,c,d,e) dbg2(a,b)dbg3(c,d,e)
#define dbg6(a,b,c,d,e,f) dbg3(a,b,c)dbg3(d,e,f)
#define dbg7(a,b,c,d,e,f,g) dbg3(a,b,c)dbg4(d,e,f,g)
#define dbg8(a,b,c,d,e,f,g,h) dbg4(a,b,c,d)dbg4(e,f,g,h)
#define dbg9(a,b,c,d,e,f,g,h,i) dbg4(a,b,c,d)dbg5(e,f,g,h,i)
#define dbg10(a,b,c,d,e,f,g,h,i,j) dbg5(a,b,c,d,e)dbg5(f,g,h,i,j)

#include<vector>

template<typename T>
void printv(vector<T>v){
    for(int i=0;i<v.size();i++)cout<<v[i]<<" \n"[i+1==v.size()];
}

template<typename T>
void print2d(T map,int h,int w){
    for(int i=0;i<h*w;i++)cout<<map[i/w][i%w]<<" \n"[i%w+1==w];
}
