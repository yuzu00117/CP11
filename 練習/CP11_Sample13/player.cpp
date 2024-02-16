//main.cpp以外のすべての.cppでconioexを使うときは#define CONIOEXを追加する
#define CONIOEX

#include "main.h"
#include <stdio.h>
#include "conioex.h"
#include "player.h"
#include "bullet.h"


//プレイヤー用データ
PLAYER g_Player;

struct BLOCK
{
	int posx;
	int posy;
};

BLOCK g_Block;

void PlayerInit(void)
{
	//プレイヤーを画面の中心（くらい）にセットする
	g_Player.posx = SCREEN_RIGHT / 2;
	g_Player.posy = SCREEN_BOTTOM / 2;
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;
	g_Player.speedx = 0.1f;
	g_Player.speedy = 0.06f;

	g_Player.maxhp = 3;
	g_Player.hp = g_Player.maxhp;

	g_Player.jump_pow = 0.0f;
	g_Player.gravity = 0.1f;
	g_Player.is_ground = 1;

	//現在の場所にプレイヤーを描画する
	gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
	printf("@");

	// ブロックのある座標を設定
	g_Block.posx = 20;
	g_Block.posy = 8;
}

void PlayerUninit(void)
{

}

void PlayerUpdate(void)
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

	// 足元に何もない場合
	if (g_Player.posy < (SCREEN_BOTTOM / 2))
	{
		if (floatToInt(g_Player.posy + 1.0f) != g_Block.posy ||
			floatToInt(g_Player.posx) != g_Block.posx)
		{
			if (g_Player.is_ground == 1)
			{
				g_Player.jump_pow = 0.0f;//ジャンプ力を設定
				g_Player.gravity = 0.1f;
				g_Player.is_ground = 0;//接地フラグオフ
			}
		}
	}

	//ジャンプ処理
	if (inport(PK_SP) && (g_Player.is_ground == 1))
	{
		g_Player.jump_pow = 1.0f;//ジャンプ力を設定
		g_Player.gravity = 0.1f;
		g_Player.is_ground = 0;//接地フラグオフ
	}

	//接地していないなら
	if (g_Player.is_ground == 0)
	{
		//ジャンプ力分の高さを変える
		g_Player.posy -= g_Player.jump_pow;
		//ジャンプ力を重力の分だけ減衰させる
		g_Player.jump_pow -= g_Player.gravity;

		// ブロックとの接地チェック
		if (floatToInt(g_Player.posy + 1.0f) == g_Block.posy &&
			floatToInt(g_Player.posx) == g_Block.posx)
		{
			g_Player.posy = (g_Block.posy - 1);
			g_Player.is_ground = 1;
		}
		
		//接地チェック
		if (g_Player.posy > (SCREEN_BOTTOM / 2))
		{
			g_Player.posy = (SCREEN_BOTTOM / 2);
			g_Player.is_ground = 1;
		}
	}
}

void PlayerDraw(void)
{
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

	gotoxy(1, 11);
	printf("########################################");
	gotoxy(20, 8);
	printf("########");
}


void PlayerDrawHP(void)
{
	gotoxy(1, 22);
	printf("PlayerHP : %d", g_Player.hp);
}


//g_Playerのゲッター関数
PLAYER* GetPlayer()
{
	return &g_Player;
}


void PlayerDamage(void)
{
	//プレイヤーのヒットポイントが1減る
	g_Player.hp--;
}


int PlayerGetHP(void)
{
	//現在のHPを返す
	return g_Player.hp;
}

void PlayerHeal(void)
{
	g_Player.hp = g_Player.maxhp;
}
