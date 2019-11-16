#include<stdio.h>
#include<stdlib.h>
#include<time.h>//乱数の種　時間計測用

#define INT_MAX 0x7fffffff

int i,j,n,pattern,loop,loop_count;
long long  swap_count,compare_count;
long long time_sum,compare_sum,swap_sum;

clock_t start,end;

void initialize_array(int *array,int *seed);//seed配列を種とした乱数で配列をランダムに設定
void print_array(int *array);//配列を表示
int print_time(int s,int e);//かかった時間を表示

void swap(int *x,int *y){int t=*x;*x=*y;*y=t;swap_count++;}//値を交換
int compare(const void *a, const void *b){return *(int*)a - *(int*)b;}//qsort関数の比較用

//heap用
#define PARENT(i) ((i)-1)/2 //親のindex
#define CHILD(i) (i)*2+1    // 左の子供のindex

//O(n^2)
void bubble_sort(int *array);
void selection_sort(int *array);
void insertion_sort(int *array);
//O(nlogn)
void merge_sort(int *array,int l,int r);
void heap_sort(int *array);
void quick_sort(int *array,int l,int r);
//O(kn)
void counting_sort(int *array);

int main(){

    srand(time(NULL));//"乱数の種を決める"乱数の種

    printf("要素数を入力:");scanf("%d",&n);
    printf("ソート前の配列のパターン\n1:ランダム 2:昇順 3:降順　→");scanf("%d",&pattern);
    printf("試行回数:");scanf("%d",&loop);

    int *array=(int*)malloc(sizeof(int)*n);//配列の確保
    int *seed=(int*)malloc(sizeof(int)*n);//乱数の種の配列
    for(i=0;i<n;i++)seed[i]=rand();//乱数の種をランダムに決める

    //print_array(array);

    puts("バブルソート");
    for(time_sum=compare_sum=swap_sum=loop_count=0;loop-loop_count;loop_count++){
        initialize_array(array,seed);

        start=clock();
        bubble_sort(array);
        end=clock();

        //print_array(array);
        time_sum+=print_time(start,end);
        compare_sum+=compare_count;
        swap_sum+=swap_count;
    }
    printf("平均時間:%d[ms]\n",time_sum/loop);
    printf("平均比較回数:%lld 平均交換回数:%lld\n",compare_sum/loop,swap_sum/loop);

    
    puts("選択ソート");
    for(time_sum=compare_sum=swap_sum=loop_count=0;loop-loop_count;loop_count++){
        initialize_array(array,seed);

        start=clock();
        selection_sort(array);
        end=clock();

        //print_array(array);
        time_sum+=print_time(start,end);
        compare_sum+=compare_count;
        swap_sum+=swap_count;
    }
    printf("平均時間:%d[ms]\n",time_sum/loop);
    //printf("compare:%d swap:%d",compare_count,swap_count);
    printf("平均比較回数:%lld 平均交換回数:%lld\n",compare_sum/loop,swap_sum/loop);
        

    puts("挿入ソート");
    for(time_sum=compare_sum=swap_sum=loop_count=0;loop-loop_count;loop_count++){
        initialize_array(array,seed);

        start=clock();
        insertion_sort(array);
        end=clock();

        //print_array(array);
        time_sum+=print_time(start,end);
        compare_sum+=compare_count;
        swap_sum+=swap_count;
    }
    printf("平均時間:%d[ms]\n",time_sum/loop);
    printf("平均比較回数:%lld 平均交換回数:%lld\n",compare_sum/loop,swap_sum/loop);


    puts("マージソート");
    for(time_sum=compare_sum=swap_sum=loop_count=0;loop-loop_count;loop_count++){

        initialize_array(array,seed);

        start=clock();
        merge_sort(array,0,n);
        end=clock();

        //print_array(array);
        time_sum+=print_time(start,end);
        compare_sum+=compare_count;
        swap_sum+=swap_count;
    }
    printf("平均時間:%d[ms]\n",time_sum/loop);
    printf("平均比較回数:%lld 平均交換回数:%lld\n",compare_sum/loop,swap_sum/loop);
    

    puts("ヒープソート");
    for(time_sum=compare_sum=swap_sum=loop_count=0;loop-loop_count;loop_count++){

        initialize_array(array,seed);

        start=clock();
        heap_sort(array);
        end=clock();

        //print_array(array);
        time_sum+=print_time(start,end);
        compare_sum+=compare_count;
        swap_sum+=swap_count;
    }
    printf("平均時間:%d[ms]\n",time_sum/loop);
    printf("平均比較回数:%lld 平均交換回数:%lld\n",compare_sum/loop,swap_sum/loop);


    puts("クイックソート");
    for(time_sum=compare_sum=swap_sum=loop_count=0;loop-loop_count;loop_count++){
        initialize_array(array,seed);

        start=clock();
        quick_sort(array,0,n);
        end=clock();

        //print_array(array);
        time_sum+=print_time(start,end);
        compare_sum+=compare_count;
        swap_sum+=swap_count;
    }
    printf("平均時間:%d[ms]\n",time_sum/loop);
    printf("平均比較回数:%lld 平均交換回数:%lld\n",compare_sum/loop,swap_sum/loop);


    puts("qsort");
    for(time_sum=compare_sum=swap_sum=loop_count=0;loop-loop_count;loop_count++){
        initialize_array(array,seed);

        start=clock();
        qsort(array,n,sizeof(int),compare);
        end=clock();

        //print_array(array);
        time_sum+=print_time(start,end);
        compare_sum+=compare_count;
        swap_sum+=swap_count;
    }
    printf("平均時間:%d[ms]\n",time_sum/loop);
    printf("平均比較回数:%lld 平均交換回数:%lld\n",compare_sum/loop,swap_sum/loop);


    puts("計数ソート");
    for(time_sum=compare_sum=swap_sum=loop_count=0;loop-loop_count;loop_count++){

        initialize_array(array,seed);

        start=clock();
        counting_sort(array);
        end=clock();

        //print_array(array);
        time_sum+=print_time(start,end);
        compare_sum+=compare_count;
        swap_sum+=swap_count;
    }
    printf("平均時間:%d[ms]\n",time_sum/loop);
    printf("平均比較回数:%lld 平均交換回数:%lld\n",compare_sum/loop,swap_sum/loop);

    free(array);
}

void initialize_array(int *array,int *seed){
    swap_count=compare_count=0;//カウントの初期化
    srand(seed[loop_count]);//乱数の初期化
    switch (pattern)
    {
    case 1:for(i=0;i<n;i++)array[i]=rand()%n;break;//ランダム
    case 2:for(i=0;i<n;i++)array[i]=i;       break;//昇順
    case 3:for(i=0;i<n;i++)array[i]=n-i-1;   break;//降順
    }
}

void print_array(int *array){for(i=0;i<n;i++)printf("%d%c",array[i],i==n-1?'\n':' ');}//配列の中身を表示

int print_time(int s,int e){//かかった時間を表示
    int sort_time=(int)((e-s)*1000.0)/CLOCKS_PER_SEC;//millsecond単位にするため1000倍

    //printf("%d[ms]\n",sort_time);
    //printf("時間:%d分%d秒%d\n",sort_time/1000/60,sort_time/1000%60,sort_time%1000);

    return sort_time;
}

void bubble_sort(int *array){
    for(i=n-1;i;i--){
        for(j=0;j<i;compare_count++,j++)if(array[j]>array[j+1])swap(&array[j],&array[j+1]);//大きい値を後ろへ
    }
}

void selection_sort(int *array){
    int min=INT_MAX,idx;
    for(i=0;i<n-1;i++){
        for(j=i,min=INT_MAX;j<n;compare_count++,j++)if(array[j]<min)min=array[j],idx=j;//最小値のインデックスを見つける
        swap(&array[i],&array[idx]);
    }
}

void insertion_sort(int *array){
    for(i=0;i<n-1;i++){
        for(j=i;j>=0&&array[j]>array[j+1];compare_count++,j--)swap(&array[j],&array[j+1]);//適切な場所まで要素を移動
    }
}

void merge_sort(int *array,int l,int r){
    if(r-l<=1)return;//要素数が1つ以下の場合終了
    compare_count++;
    int mid=(l+r)/2,ln=mid-l,rn=r-mid;

    //左右で再帰
    merge_sort(array,l,mid);
    merge_sort(array,mid,r);

    int *left=(int*)malloc(sizeof(int)*(ln+1)),*right=(int*)malloc(sizeof(int)*(rn+1));//配列とは別に領域を用意
    for(i=0;i<rn;i++)left[i]=array[l+i],right[i]=array[mid+i];//配列を左右に分けて外部領域へ
    left[ln]=right[rn]=INT_MAX;//簡単のための番兵
    for(i=0,j=0;l+i+j<r;compare_count++)array[l+i+j-1]=(left[i]<=right[j]?left[i++]:right[j++]);//左右の大きい方から先に入れる
    //iやjが1増えてからarrayに入れるのでインデックスを-1した
    free(left),free(right);//確保した領域の開放
    return;
}

void heap_sort(int *array){
    int parent,child;

    //ヒープの構成　upheap
    for(i=0;i<n;i++){//array[i]をヒープの葉から根に向かって入れる
        for(child=i,parent=PARENT(child);child>0;compare_count++,child=parent,parent=PARENT(parent)){
            if(array[parent]>array[child])break;//親の方が大きい場合終了
            swap(&array[parent],&array[child]);
        }
    }
    //ヒープソート
    for(i=n-1;i>0;i--){//iはソートされた配列の先頭　ヒープの最後の次
        swap(&array[0],&array[i]);//ヒープの根(最大値)を配列へ

        //ヒープの再構成　downheap 交換してきた根を葉に向かって入れる
        for(parent=0,child=CHILD(0);child<i;compare_count++,parent=child,child=CHILD(child)){
            if(child+1<i&&array[child]<array[child+1])child++;//大きい子供を選ぶ
            if(array[parent]>array[child])break;                //親の方が大きい場合終了
            swap(&array[parent],&array[child]);
        }
    }
}

void quick_sort(int *array,int l,int r){
    if(r-l<=1)return;//要素数が1つ以下の場合終了
    compare_count++;
    //先頭の要素を基準に左右に分ける
    for(i=l,j=l+1;j<r;compare_count++,j++)if(array[j]<array[l])swap(&array[++i],&array[j]);
    swap(&array[l],&array[i]);//基準を左右の間へ
    //左右で再帰
    quick_sort(array,l,i);
    quick_sort(array,i+1,r);
}

void counting_sort(int *array){
    int *array_copy=(int*)malloc(sizeof(int)*n);//arrayを置く外部領域を確保
    for(i=0;i<n;i++)array_copy[i]=array[i];//arrayをコピー

    int *count=(int*)malloc(sizeof(int)*(n+1));//カウントした要素数を入れる配列
    for(i=0;i<=n;i++)count[i]=0;               //count配列の初期化
    
    for(i=0;i<n;i++)count[array_copy[i]]++;//要素のカウント
    for(i=1;i<=n;i++)count[i]+=count[i-1];//累積和を取る
    for(i=0;i<n;count[array_copy[i]]--,i++)array[count[array_copy[i]]-1]=array_copy[i];//count配列に従って適切な場所に格納
    free(array_copy),free(count);
}
