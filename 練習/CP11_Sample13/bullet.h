#pragma once


//�v���C���[�f�[�^�\����
struct BULLET
{
	float posx;//���݂�X���W
	float posy;//���݂�Y���W
	float pos_oldx;//�O���X���W
	float pos_oldy;//�O���Y���W

	float speedx;//���ւ̈ړ����x
	float speedy;//�c�ւ̈ړ����x

	int use;//�g�p���Ă��邩�g�p���Ă��Ȃ����̃t���O
};


void BulletInit(void);
void BulletUninit(void);
void BulletUpdate(void);
void BulletDraw(void);

void BulletShot(float player_x, float player_y);
void BulletDelete(void);

BULLET* GetBullet();
