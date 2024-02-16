#pragma once

// プレイヤーデータ構造体
struct BULLET
{
	// 弾の座標
	float posx;
	float posy;
	// 一つ前の弾の座標
	float pos_oldx;
	float pos_oldy;

	float speedx;
	float speedy;

	bool isFire // 使用しているか使用していないかのフラグ
};

void BulletInit(void);
void BulletUninit(void);
void BulletUpdate(void);
void BulletDraw(void);

void BulletShot(void);
void BulletDelete(int id);

BULLET *GetBullet();
