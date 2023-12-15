#define CONIOEX
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "conioex.h"
#include "main.h"
#include "player.h"
#include "enemy.h"

PLAYER g_Enemy[NUM_ENEMY];

void EnemyInit(void) //初期化
{
	//エネミー座標をランダムにセットする
	for (int i = 0; i < NUM_ENEMY; i++)
	{
		g_Enemy[i].posx = rand() % SCREEN_RIGHT + 1;//1～40のランダム
		g_Enemy[i].posy = rand() % SCREEN_BOTTOM + 1;//1～20のランダム
		g_Enemy[i].pos_oldx = g_Enemy[i].posx;
		g_Enemy[i].pos_oldy = g_Enemy[i].posy;
		g_Enemy[i].speedx = (float)(rand() % 1000) / 10000;
		g_Enemy[i].speedy = (float)(rand() % 1000) / 20000;
		g_Enemy[i].use= 1; // 生存フラグオン

		//現在の場所にエネミーを描画する
		gotoxy(floatToInt(g_Enemy[i].posx), floatToInt(g_Enemy[i].posy));
		printf("#");
	}
}

void EnemyUninit(void) //終了処理
{
}

void EnemyUpdate(void) //更新
{
	for (int i = 0; i < NUM_ENEMY; i++)
	{
		if (g_Enemy[i].use == 0)
			continue;

		//前回座標を保存する
		g_Enemy[i].pos_oldx = g_Enemy[i].posx;
		g_Enemy[i].pos_oldy = g_Enemy[i].posy;

		//エネミー座標をg_Enemy.speedのぶん増やす
		g_Enemy[i].posx += g_Enemy[i].speedx;
		g_Enemy[i].posy += g_Enemy[i].speedy;

		//SCREEN_RIGHTかSCREEN_LEFTで跳ね返る
		if (g_Enemy[i].posx > SCREEN_RIGHT || g_Enemy[i].posx < SCREEN_LEFT)
		{
			//Xの移動方向を反転させる
			g_Enemy[i].speedx *= -1;
		}

		//SCREEN_TOPかSCREEN_BOTTOMで跳ね返る
		if (g_Enemy[i].posy > SCREEN_BOTTOM || g_Enemy[i].posy < SCREEN_TOP)
		{
			//Yの移動方向を反転させる
			g_Enemy[i].speedy *= -1;
		}
	}
}
void EnemyDraw(void) //描画
{
	
	for (int i = 0; i < NUM_ENEMY; i++)
	{
		if (g_Enemy[i].use == 0)
			continue;
		//もし座標が更新されていたら描画を行う
		if ((floatToInt(g_Enemy[i].pos_oldx) != floatToInt(g_Enemy[i].posx)) ||
			(floatToInt(g_Enemy[i].pos_oldy) != floatToInt(g_Enemy[i].posy)))
		{
			//ひとつ前の場所
			gotoxy(floatToInt(g_Enemy[i].pos_oldx), floatToInt(g_Enemy[i].pos_oldy));
			printf(" ");

			//現在の場所
			gotoxy(floatToInt(g_Enemy[i].posx), floatToInt(g_Enemy[i].posy));
			printf("#");
		}
	}
}

// 敵の削除
void EnemyDelete(int id)
{
	// 生存フラグをオフ
	g_Enemy[id].use = 0;

	gotoxy(floatToInt(g_Enemy[id].posx), floatToInt(g_Enemy[id].posy));
	printf(" ");
}

PLAYER* GetEnemy()
{
	return g_Enemy;
}