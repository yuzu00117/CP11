// main.cpp以外のすべての.cppでconioexを使うときは#define CONIOEXを追加する
#define CONIOEX

#include "bullet.h"
#include "main.h"
#include <stdio.h>
#include "conioex.h"

BULLET g_Bullet;

void BulletInit(void)
{
	// エネミー座標をランダムにセットする
		g_Bullet.posx = 1;
		g_Bullet.posy = 1;
		g_Bullet.pos_oldx = g_Bullet.posx;
		g_Bullet.pos_oldy = g_Bullet.posy;
		g_Bullet.speedx = 1.0f;
		g_Bullet.speedy = 1.0f;
		g_Bullet.isFire = false // デフォルトはオフ
	}
}

void BulletUninit(void)
{
}

void BulletUpdate(void)
{
	g_Bullet.pos_oldx = g_Bullet.posx;
	g_Bullet.pos_oldy = g_Bullet.posy;

	// 弾の座標更新
	if (g_Bullet.g_Bullet.isFire == true)
	{
		g_Bullet.posx += g_Bullet.speedx;
	}
}

void BulletDraw(void)
{
	// 弾が発射されているとき
	if (g_Bullet.g_Bullet.isFire == true)
	{
		// 座標の更新があったら描画
		if ((floatToInt(g_Bullet.pos_oldx) != floatToInt(g_Bullet.posx)) ||
			(floatToInt(g_Bullet.pos_oldy) != floatToInt(g_Bullet.posy)))
		{
			// 一つ前の場所
			gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_Bullet.pos_oldy));
			printf(" ");

			// 現在の場所
			gotoxy(floatToInt(g_Bullet.posx), floatToInt(g_Bullet.posy));
			printf("=");
		}
	}
}

void BulletDelete(int id)
{
	// 弾が壁に当たったらフラグを消す
	if (g_Bullet.posx < SCREEN_LEFT || g_Bullet.posx > SCREEN_RIGHT)
	{
		gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_bulletOldY));
		printf(" ");
		g_Bullet.isFire = false;
	}
	if (g_Bullet.posy < SCREEN_TOP || g_Bullet.posy > SCREEN_BOTTOM)
	{
		gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_bulletOldY));
		printf(" ");
		g_Bullet.isFire = false;
	}
}

// g_Bullet[]のゲッター関数
BULLET *GetBullet()
{
	return g_Bullet;
}
