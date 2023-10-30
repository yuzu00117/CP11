//------------------------------------------------------
// #name CL11 サンプルプログラム
// #description 図形描画プログラム
// #make 2023/06/07
//------------------------------------------------------
#define _CRT_SECURE_NO_WORNINGS
#include <stdio.h>

int main() {

    void ResetArray(int* p, int data);

    int *pt; // ポインタ変数、アドレスも格納できる

    int data; // 通常の変数には値を入れることができる

    pt = &data; // 変数に & をつけるとアドレスを引き出すことができる

    int s_data[4] = {17, 24, 38, 45};

    //s_data[0] = 80;
    //s_data[1] = 100;

    pt = s_data; // ポインタ変数 pt に配列 s_data の先頭アドレスを格納

    *pt = 100;
    printf("s_data[0]は %d でした\n", s_data[0]);
    
    *(pt + 1) = 500;
    ResetArray(s_data, 4);

    printf("s_data[0]は %d でした\n", s_data[1]);

    printf("ptのアドレスは %p でした\n", pt);
    printf("pt + 4のアドレスは %p でした\n", pt + 4);

    return 0;
}

void ResetArray(int *p, int data) {
    for (int i = 0; i < data; i++)
    {
        *(p + 1) = 0;
    }
}