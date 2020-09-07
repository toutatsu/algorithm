#include<iostream>
#include <unistd.h>
#include"visualize.h"
using namespace std;
using namespace vis;

class bl{

    enum block_type{
        T,Z,S,O
    };
    int blo[3][3];

    bl(type t):

    void rotate(int l,int r){};
}

void printmap(int map[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map[i][j]==9)setNext();
            else {
                charcolor(color(map[i][j]));
                attribute(attr(REVERSE));
                attribute(attr(BOLD));
                //printf(" %d",map[i][j]);
                printf("  ");
                cursol_w++;
            }
            attribute(attr(RESET));
        }
        newline();
    }
}

void down(int block[10][10]){
    for(int i=9;i>=0;i--){
        for(int j=0;j<10;j++){
            block[i][j]=(i!=0?block[i-1][j]:9);
        }
    }
}

int main(){
    clearscreen();
    setPosition(0,0);


    int block[10][10];
    for(int i=0;i<100;i++)block[i/10][i%10]=9;
    block[0][5]=1;
    block[1][4]=block[1][5]=block[1][6]=1;


    int data[10][10]={{0,1,2,3,4,5,6,7,9,1},
    {7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7},
    {7,7,7,7,7,7,7,7,7,7},
    {0,1,2,9,4,5,6,7,9,2}
    };

    printmap(data);

    setPosition(0,0);

    printmap(block);

    for(int i=0;i<5;i++){
        down(block);
        usleep(500000);
        setPosition(0,0);
        printmap(data);
        setPosition(0,0);
        printmap(block);
    }
    
    
    return 0;
}
