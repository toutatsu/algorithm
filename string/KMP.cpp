//Knuth Morris Pratt

//アルゴリズム論より
vector<int> make_next(string s){
    
    int i,shift,k;
    vector<int>next(s.size());
    next[0]=1;
    for(i=1;i<s.size();i++){//i文字目で不一致の場合
        for(shift=1;shift<i;shift+=next[k]){//ずらす文字数
            for(k=0;k<i-shift;k++)if(s[k]!=s[shift+k])break;
            if(k==shift-i)break;
        }
        next[i]=shift;
    }
    return next;
}
int kmp(string pattern,string text){
    int t,p;
    for(t=p=0;t<text.size()&&p<pattern.size();){
        if(text[t]==pattern[p]){t++;p++;}
        else{
            p-=next[p];if(p<0){t++;p++;}
        }
    }
    return (j==pattern.size())?i-pattern.size():-1;
}
