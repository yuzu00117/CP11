#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "conioex.h"
#include "main.h"
#include "player.h"
#include "enemy.h"

// ゲームループ
void Init(void);   // 初期化
void Uninit(void); // 終了処理
void Update(void); // 更新
void Draw(void);   // 描画

DWORD g_Mode_default;
HANDLE g_hStdin;

int g_MouseX, g_MouseY;

PLAYER g_Player;

int main(void)
{
	// ゲームデータの初期化
	Init();

	// 取得する時間の細かさ（分解能）を指定する関数
	// 今回は1/1000を指定する
	timeBeginPeriod(1); // WindowsAPI

	// ※60FPS Frame Per Secondでゲームを動かす
	//(1.0f / 60)→0.01666666666
	//(unsigned int)
	DWORD currentTime; // 現在システム時間
	DWORD lastTime;	   // 前回システム時間

	// Windowsのシステム時間を指定された分解能で返す関数
	// システム時間→Windowsが起動してからの経過時間
	currentTime = timeGetTime();
	lastTime = currentTime; // ゲーム動き出す直前の時間を保存しておく

	// ゲームループ
	while (1)
	{
		// 現在システム時間の更新
		currentTime = timeGetTime();

		// ゲームの更新タイミングを待つ
		if ((currentTime - lastTime) > (1000.0f / 60))
		{
			// 前回システム時間を更新する
			lastTime = currentTime;

			// ゲームデータの更新
			Update();

			// 描画
			Draw();
		}
	}

	// ゲームデータの後片付け
	Uninit();

	// 分解能を元に戻す
	timeEndPeriod(1);

	return 0;
}

void Init()
{
	PlayerInit();
	EnemyInit();

	// カーソルを非表示に変える
	setcursortype(NOCURSOR);

	g_hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(g_hStdin, &g_Mode_default);
	SetConsoleMode(g_hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
}

void Uninit()
{
	PlayerUninit();
	EnemyUninit();

	SetConsoleMode(g_hStdin, g_Mode_default);
}
void Update()
{
	PlayerUpdate();
	EnemyUpdate();

	// 当たり判定
	// すべてのキャラクターの座標更新後に判定を行う
	g_Player.posx;

	ENEMY *pEnemy = GetEnemy();

	for (int i = 0; i < NUM_ENEMY; i++)
	{
		// プレイヤーと敵の x,y座標が同じであれば
		if (floatToInt(g_Player.posx) == pEnemy[i].posx && floatToInt(g_Player.posy) == pEnemy[i].posy)
		{
			EnemyDelete(i);
		}
	}
	g_MouseX = inport(PM_CURX);
	g_MouseY = inport(PM_CURY);
}
void Draw()
{
	PlayerDraw();
	EnemyDraw();

	gotoxy(1, 21);
	printf("X:%3d, Y:%3d", g_MouseX, g_MouseY)
}

int floatToInt(float f)
{
	return (int)(f + 0.5f);
}

// g_Playerのゲッター関数
PLAYER *GetPlayer()
{
	return &g_Player;
}