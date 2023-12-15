#define CONIOEX

#include "main.h"
#include <stdio.h>
#include "conioex.h"


void PlayerInit(void)
{
	PLAYER* pPlayer = GetPlayer();

	//プレイヤーを画面の中心（くらい）にセットする
	pPlayer->posx = SCREEN_RIGHT / 2;
	pPlayer->posy = SCREEN_BOTTOM / 2;
	pPlayer->pos_oldx = pPlayer->posx;
	pPlayer->pos_oldy = pPlayer->posy;
	pPlayer->speedx = 0.1f;
	(*pPlayer).speedy = 0.06f;

	//現在の場所にプレイヤーを描画する
	gotoxy(floatToInt(pPlayer->posx), floatToInt(pPlayer->posy));
	printf("@");
}

void PlayerUninit()
{

}

void PlayerUpdate()
{
	PLAYER* pPlayer = GetPlayer();

	//前回座標を保存する
	pPlayer->pos_oldx = pPlayer->posx;
	pPlayer->pos_oldy = pPlayer->posy;

	//キーボードのカーソルキー左が押された
	if (inport(PK_LEFT))
	{
		pPlayer->posx -= pPlayer->speedx;
	}
	//画面から出ていかない様に補正する
	if (pPlayer->posx < SCREEN_LEFT)
	{
		pPlayer->posx = SCREEN_LEFT;
	}

	//キーボードのカーソルキー右が押された
	if (inport(PK_RIGHT))
	{
		pPlayer->posx += pPlayer->speedx;
	}
	//画面から出ていかない様に補正する
	if (pPlayer->posx > SCREEN_RIGHT)
	{
		pPlayer->posx = SCREEN_RIGHT;
	}

	//キーボードのカーソルキー上が押された
	if (inport(PK_UP))
	{
		pPlayer->posy -= pPlayer->speedy;
	}
	//画面から出ていかない様に補正する
	if (pPlayer->posy < SCREEN_TOP)
	{
		pPlayer->posy = SCREEN_TOP;
	}

	//キーボードのカーソルキー下が押された
	if (inport(PK_DOWN))
	{
		pPlayer->posy += pPlayer->speedy;
	}
	//画面から出ていかない様に補正する
	if (pPlayer->posy > SCREEN_BOTTOM)
	{
		pPlayer->posy = SCREEN_BOTTOM;
	}
}

void PlayerDraw()
{
	PLAYER* pPlayer = GetPlayer();

	//画面クリア
	//system("cls");

	//もし座標が更新されていたら描画を行う
	if ((floatToInt(pPlayer->pos_oldx) != floatToInt(pPlayer->posx)) ||
		(floatToInt(pPlayer->pos_oldy) != floatToInt(pPlayer->posy)))
	{
		//ひとつ前の場所
		gotoxy(floatToInt(pPlayer->pos_oldx), floatToInt(pPlayer->pos_oldy));
		printf(" ");

		//現在の場所
		gotoxy(floatToInt(pPlayer->posx), floatToInt(pPlayer->posy));
		printf("@");
	}
}