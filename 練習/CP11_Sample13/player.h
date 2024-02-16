#pragma once


//プレイヤーデータ構造体
struct PLAYER
{
	float posx;//現在のX座標
	float posy;//現在のY座標
	float pos_oldx;//前回のX座標
	float pos_oldy;//前回のY座標

	float speedx;//横への移動速度
	float speedy;//縦への移動速度

	int maxhp;//最大ヒットポイント
	int hp;//ヒットポイント

	float jump_pow;	//ジャンプ力
	float gravity;	//重力
	int	is_ground;	//接地フラグ

	int use;//使用しているか使用していないかのフラグ
};


void PlayerInit(void);
void PlayerUninit(void);
void PlayerUpdate(void);
void PlayerDraw(void);
void PlayerDrawHP(void);
void PlayerDamage(void);

PLAYER* GetPlayer();
int PlayerGetHP(void);
void PlayerHeal(void);
