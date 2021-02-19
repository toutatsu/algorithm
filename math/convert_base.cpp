//AtCoder Beginner Contest 186 C

#include<iostream>
using namespace std;

string convert_base(int n,int base){
    string ret;
    while(n)ret="0123456789ABCDEF"[n%base]+ret,n/=base;
    return ret;
}

int N,ans;
int main(){
    cin>>N;
    for(int i=1;i<=N;i++)ans+=(to_string(i)+convert_base(i,8)).find("7")==string::npos;
    cout<<ans<<endl;
    return 0;
}
