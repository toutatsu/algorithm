#include<bits/stdc++.h>
using namespace std;
int N;
int main(){
    cin>>N;
    cout<<N*2<<endl;

    for(int bit=0;bit<1<<N;bit++){
        bitset<32>b(bit);
        cout<<b<<endl;
        for(int keta=0;keta<N;keta++){
            cout<<(b[0])<<endl;
            b>>=1;
        }
    }
    return 0;
}
