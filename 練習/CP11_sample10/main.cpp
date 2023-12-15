#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "conioex.h"
#include "main.h"

//敵の数を定義する
#define NUM_ENEMY (20)

//ゲームループ
void Init(void);	//初期化
void Uninit(void);	//終了処理
void Update(void);	//更新
void Draw(void);	//描画
int floatToInt(float f);//座標を実数から整数に変換する


PLAYER g_Player;
PLAYER g_Enemy[NUM_ENEMY];


int main(void)
{
	//ゲームデータの初期化
	Init();

	//取得する時間の細かさ（分解能）を指定する関数
	//今回は1/1000を指定する
	timeBeginPeriod(1);//WindowsAPI

	//※60FPS Frame Per Secondでゲームを動かす
	//(1.0f / 60)→0.01666666666
	//(unsigned int)
	DWORD currentTime;//現在システム時間
	DWORD lastTime;//前回システム時間

	//Windowsのシステム時間を指定された分解能で返す関数
	//システム時間→Windowsが起動してからの経過時間
	currentTime = timeGetTime();
	lastTime = currentTime;//ゲーム動き出す直前の時間を保存しておく

	//ゲームループ
	while (1)
	{
		//現在システム時間の更新
		currentTime = timeGetTime();

		//ゲームの更新タイミングを待つ
		if ((currentTime - lastTime) > (1000.0f / 60))
		{
			//前回システム時間を更新する
			lastTime = currentTime;

			//ゲームデータの更新
			Update();

			//描画
			Draw();
		}
	}

	//ゲームデータの後片付け
	Uninit();

	//分解能を元に戻す
	timeEndPeriod(1);

	return 0;
}


void Init()
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

		//現在の場所にエネミーを描画する
		gotoxy(floatToInt(g_Enemy[i].posx), floatToInt(g_Enemy[i].posy));
		printf("#");
	}


	//カーソルを非表示に変える
	setcursortype(NOCURSOR);
}
void Uninit()
{
}
void Update()
{
	//前回座標を保存する
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;

	//キーボードのカーソルキー左が押された
	if (inport(PK_LEFT))
	{
		g_Player.posx -= g_Player.speedx;
	}
	//画面から出ていかない様に補正する
	if (g_Player.posx < SCREEN_LEFT)
	{
		g_Player.posx = SCREEN_LEFT;
	}

	//キーボードのカーソルキー右が押された
	if (inport(PK_RIGHT))
	{
		g_Player.posx += g_Player.speedx;
	}
	//画面から出ていかない様に補正する
	if (g_Player.posx > SCREEN_RIGHT)
	{
		g_Player.posx = SCREEN_RIGHT;
	}

	//キーボードのカーソルキー上が押された
	if (inport(PK_UP))
	{
		g_Player.posy -= g_Player.speedy;
	}
	//画面から出ていかない様に補正する
	if (g_Player.posy < SCREEN_TOP)
	{
		g_Player.posy = SCREEN_TOP;
	}

	//キーボードのカーソルキー下が押された
	if (inport(PK_DOWN))
	{
		g_Player.posy += g_Player.speedy;
	}
	//画面から出ていかない様に補正する
	if (g_Player.posy > SCREEN_BOTTOM)
	{
		g_Player.posy = SCREEN_BOTTOM;
	}




	//---------------------------------------------------------------------

	for (int i = 0; i < NUM_ENEMY; i++)
	{
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


void Draw()
{
	//画面クリア
	//system("cls");

	//もし座標が更新されていたら描画を行う
	if ((floatToInt(g_Player.pos_oldx) != floatToInt(g_Player.posx)) ||
		(floatToInt(g_Player.pos_oldy) != floatToInt(g_Player.posy)))
	{
		//ひとつ前の場所
		gotoxy(floatToInt(g_Player.pos_oldx), floatToInt(g_Player.pos_oldy));
		printf(" ");

		//現在の場所
		gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
		printf("@");
	}

	//----------------------------------------------------------------------------

	for (int i = 0; i < NUM_ENEMY; i++)
	{
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

PLAYER* GetPlayer()
{
	return &g_Player;
}