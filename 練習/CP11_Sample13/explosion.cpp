
#include "explosion.h"

#define CONIOEX
#include "conioex.h"

#include "main.h"
#include <stdio.h>


//*******************************************
//グローバル変数
//*******************************************
EXPLOSION g_Explosion;


void ExplosionInit(void)
{
	g_Explosion.posx = 0;
	g_Explosion.posy = 0;

	g_Explosion.frame = 0;

	g_Explosion.use = 0;
}


void ExplosionUninit(void)
{

}


void ExplosionUpdate(void)
{

}


void ExplosionDraw(void)
{
	//useフラグがオンであれば描画を行う
	if (g_Explosion.use != 0)
	{
		gotoxy(floatToInt(g_Explosion.posx), floatToInt(g_Explosion.posy));

		//アニメーションパターン表示
		if (g_Explosion.frame < 5)
			printf("=");
		else if(g_Explosion.frame < 10)
			printf("*");
		else
			printf("-");

		//時間経過
		g_Explosion.frame++;

		//時間経過で表示を消す
		if (g_Explosion.frame > 15)
		{
			//useフラグオフ
			g_Explosion.use = 0;

			//表示削除
			gotoxy(floatToInt(g_Explosion.posx), floatToInt(g_Explosion.posy));
			printf(" ");
		}
	}
}


void ExplosionStart(float posx, float posy)
{
	//現在アニメーションを実行していないなら新しくセットする
	if (g_Explosion.use == 0)
	{
		g_Explosion.posx = posx;
		g_Explosion.posy = posy;
		g_Explosion.frame = 0;//経過時間をリセットする
		g_Explosion.use = 1;//useフラグオン
	}
}