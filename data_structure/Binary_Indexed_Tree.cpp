BIT
testしろ
int bit[n];

int sum(int i){
  int sum=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return sum;
}

void add(int i,int x){
  while(i≤n){
    bit[i]+=x;
    i+=i&-i;
  }
}
