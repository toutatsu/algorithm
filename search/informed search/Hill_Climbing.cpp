#include<bits/stdc++.h>
using namespace std;

random_device rnd;
mt19937 mt(rnd());
std::uniform_int_distribution<> r(1, 1000000000);

template<typename T>
class Hill_Climbing{
    public:
    vector<T>*ans;

    Hill_Climbing(int size){
        ans=new vector<T>(100);
    };

    void Initialization(){
        for(int i=0;i<100;i++)ans[0][i]=r(mt);
    }

    int evaluation(){


    }
};
int main(){
    Hill_Climbing<int> HC(100);
    HC.Initialization();
    for(auto x:HC.ans[0])cout<<x<<endl;
    return 0;
}
