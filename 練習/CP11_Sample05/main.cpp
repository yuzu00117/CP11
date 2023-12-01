//-----------------------------------------------------------------------------------------------------
// #name CP11 練習
// #description
// #make 2023/11/17
// #update 2023/11/17
//-----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conioex.h>

// プレイヤーデータ
struct PLAYER_DATA
{
    int posX = 0;
    int posY = 0;

    int speed = 1;
};

PLAYER_DATA player;

// 画面サイズ
#define SCREEN_LEFT 1
#define SCREEN_RIGHT 40
#define SCREEN_TOP 1
#define SCREEN_BOTTOM 20

// ゲームループ
void init();    // 初期化
void un_init(); // 終了処理
void update();  // 更新
void draw();    // 描画

int main()
{
    // 初期化
    init();

    // ゲームループ
    while (1)
    {
        update();

        draw();
    }

}

//-----------------------------------------------------------------------------------------------------
// 初期化
void init()
{
    // プレイヤーを画面の中心ぐらいに移動
    player.posX = SCREEN_RIGHT / 2;
    player.posY = SCREEN_BOTTOM / 2;
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// 終了処理
void un_init()
{
    // null
}
//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// 更新
void update()
{
    player.posX += player.speed;

    if (player.posX > SCREEN_RIGHT || player.posX < SCREEN_LEFT)
        player.speed *= -1;
    Sleep(100);
}

//-----------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------
// 描画
void draw()
{
    // 画面クリア
    system("cls");

    // 画面描画
    /*
    for (int y = SCREEN_TOP; y <= SCREEN_BOTTOM; y++)
    {
        for (int x = SCREEN_LEFT; x <= SCREEN_RIGHT; x++)
        {
            if (y == player.posY && x == player.posX)
            {
                printf("P");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    */
   gotoxy(player.posX, player.posY);
   printf("P");
}
//-----------------------------------------------------------------------------------------------------