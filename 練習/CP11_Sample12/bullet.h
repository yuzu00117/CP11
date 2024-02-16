#pragma once

// �v���C���[�f�[�^�\����
struct BULLET
{
	// �e�̍��W
	float posx;
	float posy;
	// ��O�̒e�̍��W
	float pos_oldx;
	float pos_oldy;

	float speedx;
	float speedy;

	bool isFire // �g�p���Ă��邩�g�p���Ă��Ȃ����̃t���O
};

void BulletInit(void);
void BulletUninit(void);
void BulletUpdate(void);
void BulletDraw(void);

void BulletShot(void);
void BulletDelete(int id);

BULLET *GetBullet();
