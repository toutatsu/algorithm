//半分全列挙
//AtCoder Beginner Contest 184 F
//https://atcoder.jp/contests/abc184/submissions/18352007

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//N<=40
long long N,T,ans;
int main(){
    cin>>N>>T;
    vector<long long>A(N);
    for(long long& a:A)cin>>a;
    vector<long long>B{0L},C{0L};
    for(long long a:A){
        //部分和の列挙
        for(int i=B.size();i--;)B.push_back(B[i]+a);
        swap(B,C);
    }
    sort(B.begin(),B.end(),greater<long long>());
    
    for(long long x:C){
        if(x>T)continue;
        x+=*lower_bound(B.begin(),B.end(),T-x,greater<long long>());
        ans=max(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}
