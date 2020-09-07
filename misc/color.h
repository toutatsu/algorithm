#include<iostream>

namespace vis{

    int cursol_h=0,cursol_w=0;
    void clearscreen(){printf("\033[2J");}/*画面をきれいにする*/
    void cursoloff()  {printf("\033[?25l");}/*カーソルを消す*/

    //任意の場所に文字を表示
    void setPosition(int h,int w){
        printf("\033[%d;%dH",(h)+1,(w)*2+1);
        cursol_h=h;cursol_w=w;
    }

    void setNext(){
        setPosition(cursol_h,++cursol_w);
    }
    void newline(){
        setPosition(++cursol_h,cursol_w=0);
    }

    enum color{BLACK,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE,DEFAULT=9};
    void charcolor(color C){printf("\033[3%dm",C);}//文字の色を変える
    void backcolor(color C){printf("\033[4%dm",C);}//背景の色を変える

    enum attr{RESET,BOLD,DIM,ITALIC,UNDERLINE,BLINK,BLINK_FAST,REVERSE,HIDE,CANCEL};
    void attribute(int n){printf("\033[%dm",(n));}/*表示形式を変える*/
}
