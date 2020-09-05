#include<iostream>
#include<random>
#include<map>
using namespace std;

//http://vivi.dyndns.org/tech/cpp/random.html/
class testcase{

    public:

    std::mt19937 mt;            // メルセンヌ・ツイスタの32ビット版
    std::random_device rnd;     // 非決定的な乱数生成器

    testcase(long long Seed=0LL){
        mt.seed(Seed);            // シード指定
    }
    vector<int> uniform_int_distribution(int L,int R,int N,bool output){
        std::uniform_int_distribution<> rand_int(L,R);//integer [L,R]
        vector<int>rnd;
        for(int i=0;i<N;i++){
            int x=rand_int(mt);
            if(output)cout<<x<<" \n"[i==N-1];
            rnd.push_back(x);
        }
        return rnd;
    }

    void graph(int max_V,int max_E){
        //作り途中

        auto V=uniform_int_distribution(2,max_V,1,true);

        // auto a=t.uniform_int_distribution(1,N[0],2,false);
        // do{
        //     a=t.uniform_int_distribution(1,N[0],2,false);
        // }while(a[0]==a[1]);
        // cout<<a[0]<<" "<<a[1]<<endl;

        auto E=uniform_int_distribution(1,min(max_E,V[0]*(V[0]-1)/2),1,true);

        map<pair<int,int>,bool>used;
        for(int i=0;i<E[0];i++){
            auto xy=uniform_int_distribution(1,V[0],2,false);
            if(xy[0]==xy[1]){i--;continue;}
            if(used[make_pair(xy[0],xy[1])]==false){
                cout<<xy[0]<<" "<<xy[1]<<endl;
                used[make_pair(xy[0],xy[1])]=true;
            }
            else i--;
        }

    }
};


int main(int argc,char** argv){
    static const int seed=atoi(argv[1]);
    testcase t(seed);

    auto N=t.uniform_int_distribution(2,5*100,1,true);
    auto Q=t.uniform_int_distribution(2,10,1,true);

    auto c=t.uniform_int_distribution(1,N[0],N[0],true);

    for(int i=0;i<Q[0];i++){
        auto q=t.uniform_int_distribution(1,N[0],2,false);
        if(q[0]>q[1]){i--;continue;}
        cout<<q[0]<<" "<<q[1]<<endl;
    }
    return 0;
}
