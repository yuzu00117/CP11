// main.cpp以外のすべての.cppでconioexを使うときは
#define CONIOEX

#include <stdio.h>
#include "main.h"
#include "conioex.h"

void Player_Init(void);	    //初期化
void Player_Uninit(void);	//終了処理
void Player_Update(void);	//更新
void Player_Draw(void);	    //描画

void PlayerInit(void)
{
	PLAYER* pPlayer = GetPlayer();

    //プレイヤーを画面の中心（くらい）にセットする
	pPlayer->posx = SCREEN_RIGHT / 2;
	pPlayer->posy = SCREEN_BOTTOM / 2;
	pPlayer->pos_oldx = pPlayer->posx;
	pPlayer->pos_oldy = pPlayer->posy;
	pPlayer->speedx = 0.1f;
	pPlayer->speedy = 0.06f;

	//現在の場所にプレイヤーを描画する
	gotoxy(floatToInt(pPlayer->posx), floatToInt(pPlayer->posy));
	printf("@");

}