//main.cpp以外のすべての.cppでconioexを使うときは#define CONIOEXを追加する
#define CONIOEX

#include "bullet.h"
#include "main.h"
#include <stdio.h>
#include "conioex.h"


BULLET g_Bullet;


void BulletInit(void)
{
	//エネミー座標をランダムにセットする
	g_Bullet.posx = 1;
	g_Bullet.posy = 1;
	g_Bullet.pos_oldx = g_Bullet.posx;
	g_Bullet.pos_oldy = g_Bullet.posy;
	g_Bullet.speedx = 1.0f;
	g_Bullet.speedy = 0.0f;
	g_Bullet.use = 0;//最初は表示されていないのでフラグオフ
}


void BulletUninit(void)
{

}


void BulletUpdate(void)
{
	//前回値の保存
	g_Bullet.pos_oldx = g_Bullet.posx;
	g_Bullet.pos_oldy = g_Bullet.posy;


	//弾の座標更新
	if (g_Bullet.use == 1)
	{
		g_Bullet.posx += g_Bullet.speedx;
	}
}


void BulletDraw(void)
{
	//弾が発射中であれば描画を行う
	if (g_Bullet.use == 1)
	{
		//右端の壁（40）より弾の座標が大きくなった
		if (floatToInt(g_Bullet.posx) > SCREEN_RIGHT)
		{
			//壁に当たったので弾を消滅させる
			g_Bullet.use = 0;
			//絵も消す
			gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_Bullet.pos_oldy));
			printf(" ");
		}
		else
		{
			//もし座標が更新されていたら描画を行う
			if ((floatToInt(g_Bullet.pos_oldx) != floatToInt(g_Bullet.posx)) ||
				(floatToInt(g_Bullet.pos_oldy) != floatToInt(g_Bullet.posy)))
			{
				//ひとつ前の場所
				gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_Bullet.pos_oldy));
				printf(" ");

				//現在の場所
				gotoxy(floatToInt(g_Bullet.posx), floatToInt(g_Bullet.posy));
				printf("=");
			}
		}
	}
}


void BulletShot(float player_x, float player_y)
{
	//弾が使用中の場合は実行しない
	if (g_Bullet.use == 0)
	{
		g_Bullet.use = 1;//弾のステータスを発射中に変更する
		g_Bullet.posx = floatToInt(player_x) + 1;//プレイヤー座標のひとつ右側から弾を発射する
		g_Bullet.posy = player_y;//縦はプレイヤーと一緒
	}
}


void BulletDelete(void)
{
	//弾のステータスを未使用状態に更新する
	g_Bullet.use = 0;

	//弾の表示を強制的に削除
	gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_Bullet.pos_oldy));
	printf(" ");
}


//g_Bulletのゲッター関数
BULLET* GetBullet()
{
	return &g_Bullet;
}
