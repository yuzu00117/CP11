//-------------------------------------------------------------------------------------
// #name CP11 Sample03
// #description sizeof, typedef の練習
// #make 2023/10/20
//-------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

// int typedef
typedef int INT2; // 型の別名を作成する機能

// struct
struct CHARA_DATA
{
    char ID;
    char No;
    int HP;
    int STR;
    int DEX;
};

// 関数宣言
void sizeof_Sample();
void cast_Sample();
void shift_Sample();
void bit_Sample();

int main()
{
    // 練習プログラム
    //sizeof_Sample();
    //cast_Sample();
    //shift_Sample();
    bit_Sample();
}

//-------------------------------------------------------------------------------------

// sizeof演算子のサンプルプログラム
void sizeof_Sample()
{
    printf ("sizeof Sample Program\n\n");
    int data = 100;
    int size = 0;

    CHARA_DATA chara_data;

    size = sizeof(CHARA_DATA);

    printf("data の値は %d でした\n", data);
    printf("size の値は %d でした\n", size);
}

// キャスト演算子のサンプルプログラム
void cast_Sample()
{
    printf("cast_Sample_Program\n\n");
    char *p_char = NULL;   
    int data[10];
    int *p = NULL;

    p = data;
    p_char = (char*)data; // キャスト演算子、強制型変換

    int size = 0;
    size = sizeof(p_char);

    printf("size の値は %d でした\n", size);
}

// シフト演算のサンプルプログラム
void shift_Sample()
{
    int data = 100;

    data = data << 1;
    printf("data の値は %d でした\n", data);

    
    data = data >> 1;
    printf("data の値は %d でした\n", data);
}

// ビット演算子のサンプルプログラム
void bit_Sample()
{
    unsigned char data = 0x10; // 0001 0000

    // & は AND演算子
    data = data & 0x33;
    printf("data の値は %d です\n", data);

    // | は OR演算子
    data = data | 0x33;
    printf("data の値は %d です\n", data);

    // ^ は XOR演算子
    data = data ^ 0x33;
    printf("data の値は %d です\n", data);

    // ~ は NOT演算子
    data = ~0x33;
    printf("data の値は %d です\n", data);
}