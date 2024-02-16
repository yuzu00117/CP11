// main.cpp以外のすべての.cppでconioexを使うときは#define CONIOEXを追加する
#define CONIOEX

#include "main.h"
#include <stdio.h>
#include "conioex.h"
#include "player.h"

PLAYER g_Player;

// 弾の座標
float g_bulletX;
float g_bulletY;
// 一つ前の弾の座標
float g_bulletOldX;
float g_bulletOldY;

// 弾が発射されているか
bool isFire;

void PlayerInit(void)
{
	// プレイヤーを画面の中心（くらい）にセットする
	g_Player.posx = SCREEN_RIGHT / 2;
	g_Player.posy = SCREEN_BOTTOM / 2;
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;
	g_Player.speedx = 0.1f;
	g_Player.speedy = 0.06f;

	// 現在の場所にプレイヤーを描画する
	gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
	printf("@");
}

void PlayerUninit(void)
{
}

void PlayerUpdate(void)
{
	// 前回座標を保存する
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;

	g_bulletOldX = g_bulletX;
	g_bulletOldY = g_bulletY;

	// キーボードのカーソルキー左が押された
	if (inport(PK_LEFT))
	{
		g_Player.posx -= g_Player.speedx;
	}
	// 画面から出ていかない様に補正する
	if (g_Player.posx < SCREEN_LEFT)
	{
		g_Player.posx = SCREEN_LEFT;
	}

	// キーボードのカーソルキー右が押された
	if (inport(PK_RIGHT))
	{
		g_Player.posx += g_Player.speedx;
	}
	// 画面から出ていかない様に補正する
	if (g_Player.posx > SCREEN_RIGHT)
	{
		g_Player.posx = SCREEN_RIGHT;
	}

	// キーボードのカーソルキー上が押された
	if (inport(PK_UP))
	{
		g_Player.posy -= g_Player.speedy;
	}
	// 画面から出ていかない様に補正する
	if (g_Player.posy < SCREEN_TOP)
	{
		g_Player.posy = SCREEN_TOP;
	}

	// キーボードのカーソルキー下が押された
	if (inport(PK_DOWN))
	{
		g_Player.posy += g_Player.speedy;
	}
	// 画面から出ていかない様に補正する
	if (g_Player.posy > SCREEN_BOTTOM)
	{
		g_Player.posy = SCREEN_BOTTOM;
	}

	// 弾を発射
	// フラグがオンであれば弾を右に移動させ表示
	if (isFire == true)
	{
		g_bulletX += 1.0f;
	}
	// Spaceキーが押されたらフラグをオンにし、座標をプレイヤーの一つ右へ
	if (inport(PK_SP))
	{
		isFire = true;
		g_bulletX = g_Player.posx + 1;
		g_bulletY = g_Player.posy;
	}
	
	// 弾が壁に当たったらフラグを消す
	if (g_bulletX < SCREEN_LEFT || g_bulletX > SCREEN_RIGHT)
	{
		gotoxy(floatToInt(g_bulletOldX), floatToInt(g_bulletOldY));
		printf(" ");
		isFire = false;
	}
	if (g_bulletY < SCREEN_TOP || g_bulletY > SCREEN_BOTTOM)
	{
		gotoxy(floatToInt(g_bulletOldX), floatToInt(g_bulletOldY));
		printf(" ");
		isFire = false;
	}
}

void PlayerDraw(void)
{
	// もし座標が更新されていたら描画を行う
	if ((floatToInt(g_Player.pos_oldx) != floatToInt(g_Player.posx)) ||
		(floatToInt(g_Player.pos_oldy) != floatToInt(g_Player.posy)))
	{
		// ひとつ前の場所の弾を削除
		gotoxy(floatToInt(g_Player.pos_oldx), floatToInt(g_Player.pos_oldy));
		printf(" ");

		// 現在の場所に再描画
		gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
		printf("@");
	}

	// 弾が発射されているとき
	if (isFire == true)
	{
		// 座標の更新があったら描画
		if ((floatToInt(g_bulletOldX) != floatToInt(g_bulletX)) ||
			(floatToInt(g_bulletOldY) != floatToInt(g_bulletY)))
		{
			// 一つ前の場所
			gotoxy(floatToInt(g_bulletOldX), floatToInt(g_bulletOldY));
			printf(" ");

			// 現在の場所
			gotoxy(floatToInt(g_bulletX), floatToInt(g_bulletY));
			printf("=");
		}
	}
}

// g_Playerのゲッター関数
PLAYER *GetPlayer()
{
	return &g_Player;
}
