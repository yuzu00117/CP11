#pragma once


//�����A�j���[�V�����\����
struct EXPLOSION
{
	float posx;//���݂�X���W
	float posy;//���݂�Y���W

	int frame;//�o�߃t���[���i���ԁj

	int use;//�g�p���Ă��邩�g�p���Ă��Ȃ����̃t���O
};


void ExplosionInit(void);
void ExplosionUninit(void);
void ExplosionUpdate(void);
void ExplosionDraw(void);

void ExplosionStart(float posx, float posy);
